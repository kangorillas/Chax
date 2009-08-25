//
//  CameraSnapshotController.m
//  Chax
//
//  Created by Kent Sutherland on 2/4/09.
//  Copyright 2009 Kent Sutherland. All rights reserved.
//

#import "CameraSnapshotController.h"
#import "iChat5.h"

@implementation CameraSnapshotController

@synthesize delegate = _delegate;

- (id)init
{
	if ( (self = [super initWithWindowNibName:@"CameraSnapshot"]) ) {
	}
	return self;
}

- (void)windowDidLoad
{
	NSImage *cameraImage = [[[NSImage alloc] initWithContentsOfFile:@"/System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/ImageKit.framework/Versions/A/Resources/ik_camera.tiff"] autorelease];
	NSImage *cameraDownImage = [[[NSImage alloc] initWithContentsOfFile:@"/System/Library/Frameworks/Quartz.framework/Versions/A/Frameworks/ImageKit.framework/Versions/A/Resources/ik_camera_down.tiff"] autorelease];
	
	//Set the flip checkbox color
	NSDictionary *attributes = [NSDictionary dictionaryWithObject:[NSColor whiteColor] forKey:NSForegroundColorAttributeName];
	id flip = [Chax objectForKey:@"FlipCameraSnapshot"];
	
	[_flipButton setAttributedTitle:[[[NSAttributedString alloc] initWithString:_flipButton.title attributes:attributes] autorelease]];
	[_flipButton setState:(!flip || [flip boolValue]) ? NSOnState : NSOffState];
	
	//Set the send button images
	[_sendButton setImage:cameraImage];
	[_sendButton setAlternateImage:cameraDownImage];
	
	//Set the window's aspect ratio
	CGFloat viewHeight = _cameraView.frame.size.width / [[_cameraView layerModel] preferredAspectRatio];
	NSRect windowFrame = [[self window] frame];
	
	windowFrame.size.height += viewHeight - _cameraView.frame.size.height;
	
	[[self window] setFrame:windowFrame display:NO];
	[[self window] center];
	[[self window] setLevel:NSNormalWindowLevel];
	
	if ([_cameraView canStartVideo]) {
		[_cameraView startVideo];
	}
}

- (void)windowWillClose:(NSNotification *)notification
{
	[_cameraView stopVideo];
	
	if ([self.delegate respondsToSelector:@selector(cameraSnapshotControllerDidCancel:)]) {
		[self.delegate cameraSnapshotControllerDidCancel:self];
	}
}

- (IBAction)send:(id)sender
{
	[[self window] orderOut:nil];
	[_cameraView stopVideo];
	
	if ([self.delegate respondsToSelector:@selector(cameraSnapshotController:didTakeSnapshot:)]) {
		NSImage *image = [_cameraView bitmapImageFromSurface];
		
		if (_flipButton.state == NSOnState) {
			NSSize size = image.size;
			NSImage *flippedImage = [[[NSImage alloc] initWithSize:size] autorelease];
			NSRect drawRect = NSMakeRect(0, 0, size.width, size.height);
			
			[flippedImage lockFocus];
			
			NSAffineTransform *transform = [NSAffineTransform transform];
			
			[transform translateXBy:size.width yBy:0];
			[transform scaleXBy:-1 yBy:1];
			[transform concat];
			
			[image drawInRect:drawRect fromRect:drawRect operation:NSCompositeSourceOver fraction:1.0];
			[flippedImage unlockFocus];
			
			image = flippedImage;
		}
		
		[self.delegate cameraSnapshotController:self didTakeSnapshot:image];
		
		[Chax setBool:_flipButton.state == NSOnState forKey:@"FlipCameraSnapshot"];
	}
}

@end
