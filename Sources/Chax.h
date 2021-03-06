/*
 * Chax.h
 *
 * Copyright (c) 2007-2011 Kent Sutherland
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

#import <Cocoa/Cocoa.h>

#define DONATE_URL [NSURL URLWithString:@"http://www.ksuther.com/chax/donate"]

typedef enum ChaxMenuItem {
    ChaxMenuItemShowTextStatus = 13371,
    ChaxMenuItemLogViewer,
    ChaxMenuItemActivityViewer,
    ChaxMenuItemAlwaysOnTop,
    ChaxMenuItemAllContacts,
    ChaxMenuItemCameraSnapshot,
    ChaxMenuItemByHandle,
} ChaxMenuItem;

extern NSString *ChaxBundleIdentifier;
extern NSString *ChaxLibBundleIdentifier;
extern NSString *iChatAgentBundleIdentifier;

BOOL ChaxDebugLoggingEnabled();
void SetChaxDebugLoggingEnabled(BOOL enable);
void ChaxDebugLog(NSString *format, ...);

static inline NSString * ChaxLocalizedString(NSString *key) {
	return [[NSBundle bundleWithIdentifier:ChaxLibBundleIdentifier] localizedStringForKey:(key) value:(key) table:nil];
}

@interface Chax : NSObject {
	
}

+ (void)registerURLHandlers;
+ (void)setupSparkle;
+ (void)checkForUpdates;
+ (void)displayDonateWindowIfWanted;
+ (void)addMenuItems;
+ (NSArray *)menuItems;

+ (BOOL)boolForKey:(NSString *)key;
+ (int)integerForKey:(NSString *)key;
+ (NSData *)dataForKey:(NSString *)key;
+ (NSString *)stringForKey:(NSString *)key;
+ (id)objectForKey:(NSString *)key;
+ (void)setBool:(BOOL)value forKey:(NSString *)key;
+ (void)setInteger:(int)value forKey:(NSString *)key;
+ (void)setObject:(id)value forKey:(NSString *)key;

@end
