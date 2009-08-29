/*
 * UnifiedPeopleListController_Provider.m
 *
 * Copyright (c) 2007-2009 Kent Sutherland
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
 * Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#import "UnifiedPeopleListController_Provider.h"
#import "UnifiedAccount.h"
#import <objc/runtime.h>
#import <objc/message.h>

NSMenu *_addMenu = nil;

@implementation UnifiedPeopleListController_Provider

+ (void)load
{
    NSAutoreleasePool *pool = [[NSAutoreleasePool alloc] init];
    
    [BundleUtilities subclass:NSClassFromString(@"PeopleListController") usingClassName:@"UnifiedPeopleListController" providerClass:self];
    
    [pool release];
}

+ (id)sharedController
{
	static id sharedController = nil;
	
	if (!sharedController) {
		IMAccount *account = [[[UnifiedAccount alloc] initWithUniqueID:@"Chax" service:nil] autorelease];
		
		[account setAccountLoginStatus:4];
		
		sharedController = [[NSClassFromString(@"UnifiedPeopleListController") alloc] initWithAccount:account];
	}
	
	return sharedController;
}

- (id)initWithAccount:(IMAccount *)account
{
	struct objc_super superData = {self, [self superclass]};
	
	if ( (self = objc_msgSendSuper(&superData, @selector(initWithAccount:), account)) ) {
		[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(chax_notificationReceived:) name:@"ReloadContactList" object:nil];
		
		[self setPrefIdentifier:@"Chax"];
		[self setName:ChaxLocalizedString(@"Contacts")];
	}
	return self;
}

- (void)dealloc
{
    [_addMenu release];
    
    struct objc_super superData = {self, [self superclass]};
	
	objc_msgSendSuper(&superData, @selector(dealloc));
}

- (BOOL)supportsOfflineToggle
{
	return YES;
}

- (BOOL)supportsGroups
{
	return YES;
}

- (BOOL)peopleList:(id)fp8 canRemoveRows:(id)fp12
{
	return YES;
}

- (void)setGroupsSortOrder:(id)fp8
{
    struct objc_super superData = {self, [self superclass]};
	
	objc_msgSendSuper(&superData, @selector(setGroupsSortOrder:), fp8);
	
	[self refreshList];
}

- (void)logServiceInOrOut:(id)sender
{
	if ([(NSArray *)[[IMAccountController sharedInstance] allConnectedAccounts] count] == 0) {
		NSArray *accounts = [[IMAccountController sharedInstance] allActiveAccounts];
		
		for (Account *account in accounts) {
			if ([account autoLogin]) {
				[(IMAccountController *)[IMAccountController sharedInstance] autoLogin];
				[[self representedAccount] setAccountLoginStatus:4];
                
                [self uncollapseTableAnimated:YES];
                
				return;
			}
		}
		
		[[self representedAccount] setAccountLoginStatus:0];
	} else {
		[[IMDaemonController sharedController] logoutAllAccounts];
		[[self representedAccount] setAccountLoginStatus:0];
        
        [self collapseTableAnimated:YES];
	}
}

- (void)processIMHandleGroupChange:(IMHandle *)imHandle
{
	[self reloadContacts];
}

- (void)_arrangesByGroupChanged
{
	struct objc_super superData = {self, [self superclass]};
	
	objc_msgSendSuper(&superData, @selector(_arrangesByGroupChanged));
	
	if (!_addMenu) {
		//Build the menu delayed the first time
		[self performSelector:@selector(rebuildAddBuddyMenu) withObject:nil afterDelay:2.0];
	} else {
		[self rebuildAddBuddyMenu];
	}
}

- (void)_deleteBuddies:(id)sender
{
    for (PeopleListController *pl in [NSClassFromString(@"PeopleListController") peopleListControllers]) {
        if (![self isEqual:pl]) {
            [pl _deleteBuddies:sender];
        }
    }
}

- (void)reloadContacts
{
	[[self sourcePeople] beginCoalescedChanges];
	
	[[self peopleList] removeAllIMHandlesAndGroups:YES];
	
	for (PeopleListController *pl in [NSClassFromString(@"PeopleListController") peopleListControllers]) {
		if (![self isEqual:pl]) {
			NSArray *handles = [[pl peopleList] allIMHandles];
			
			for (IMHandle *nextIMHandle in handles) {
				[[self sourcePeople] addIMHandle:nextIMHandle];
			}
		}
	}
	
	[[self sourcePeople] endCoalescedChanges];
}

- (void)rebuildAddBuddyMenu
{
	if (!_addMenu) {
		_addMenu = [[NSMenu alloc] init];
	}
	
	while (_addMenu.numberOfItems > 0) {
		[_addMenu removeItemAtIndex:0];
	}
	
	NSArray *connectedAccounts = [[IMAccountController sharedInstance] allConnectedAccounts];
	
	for (IMAccount *nextAccount in connectedAccounts) {
		NSString *description = [nextAccount description];
		
		if (description) {
			NSMenu *accountSubmenu = [[[NSMenu alloc] init] autorelease];
			
			[[_addMenu addItemWithTitle:description action:nil keyEquivalent:@""] setSubmenu:accountSubmenu];
			
			[[accountSubmenu addItemWithTitle:NSLocalizedString(@"Add Buddy\\U2026", nil) action:@selector(addABuddyChax:) keyEquivalent:@""] setRepresentedObject:[nextAccount uniqueID]];
			[[accountSubmenu addItemWithTitle:ChaxLocalizedString(@"Add Group...") action:@selector(addAGroupChax:) keyEquivalent:@""] setRepresentedObject:[nextAccount uniqueID]];
		}
	}
	
	[[self valueForKey:@"_addButton"] setUsesMenu:YES];
	[[self valueForKey:@"_addButton"] setMenu:_addMenu];
}

- (void)addABuddyChax:(id)sender
{
	IMAccount *account = [[IMAccountController sharedInstance] accountForUniqueID:[sender representedObject]];
	PeopleListController *accountPeopleListController = [NSClassFromString(@"PeopleListController") peopleListControllerWithRepresentedAccount:account];
	
	AddBuddy *addBuddy = [accountPeopleListController addBuddy];
	
	id groups = [accountPeopleListController groupsWithCapability:nil];
	
	[addBuddy openForNewIMHandleWithGroups:groups buddyWindow:[self window]];
}

- (void)addAGroupChax:(id)sender
{
	IMAccount *account = [[IMAccountController sharedInstance] accountForUniqueID:[sender representedObject]];
	PeopleListController *accountPeopleListController = [NSClassFromString(@"PeopleListController") peopleListControllerWithRepresentedAccount:account];
	
	[accountPeopleListController showWindow:nil];
	[NSClassFromString(@"GroupsEditorController") addGroupForPeopleListController:accountPeopleListController];
}

@end
