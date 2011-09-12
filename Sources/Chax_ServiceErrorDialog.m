/*
 * Chax_ServiceErrorDialog.m
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

#import "Chax_ServiceErrorDialog.h"

@implementation Chax_ServiceErrorDialog

+ (void)chax_swizzle_displayDisconnectAlertInfoText:(id)fp8 wasConnected:(BOOL)fp12 forAccount:(id)fp16
{
    if (fp12 && [Chax boolForKey:@"AttemptAutoReconnect"]) {
        ChaxDebugLog(@"Chax: %@ was connected, now disconnected due to error '%@'", fp16, fp8);
        ChaxDebugLog(@"Attempting to reconnect in 7 seconds...");
        
        [fp16 performSelector:@selector(loginAccount) withObject:nil afterDelay:7.0];
    }
    
    [self chax_swizzle_displayDisconnectAlertInfoText:fp8 wasConnected:fp12 forAccount:fp16];
}

@end