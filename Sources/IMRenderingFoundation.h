/*
 *     Generated by class-dump 3.3.3 (64 bit).
 *
 *     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2011 by Steve Nygard.
 */

#pragma mark Named Structures

@class Smiley;

struct _IMSmileyEntry {
    unsigned int _field1;
    unsigned char _field2;
    Smiley *_field3;
};

#pragma mark -

/*
 * File: IMRenderingFoundation
 * UUID: 62464202-F117-3F51-BEA9-6FA8B2C8AB2E
 * Arch: Intel x86-64 (x86_64)
 *       Current version: 800.0.0, Compatibility version: 1.0.0
 *       Minimum Mac OS X version: 10.7.0
 *
 *       Objective-C Garbage Collection: Supported
 */

@class TranscriptStyleController, BaseInstantMessage, DDScannerResult, DDPatternCompiler;

@protocol FileTransferFragmentProvider;

@protocol TranscriptFragmentProvider <NSObject>
- (id)role;
- (id)fragmentIdForChatItem:(id)arg1;
- (id)initWithTranscriptStyleController:(id)arg1;
- (void)transcriptWillLoad;
- (void)transcriptDidLoad;
- (void)nameDisplayChanged:(id)arg1;
- (id)fragmentForChatItem:(id)arg1;
- (id)appendFragmentForChatItem:(id)arg1 toNode:(id)arg2;
- (void)removeFragmentForChatItem:(id)arg1;
- (void)addFragmentIdPropertiesToElement:(id)arg1 forChatItem:(id)arg2;
@end

@interface TranscriptFragmentProvider : NSObject <TranscriptFragmentProvider>
{
    TranscriptStyleController *_controller;
}

- (id)role;
- (id)fragmentIdForChatItem:(id)arg1;
- (id)initWithTranscriptStyleController:(id)arg1;
- (void)dealloc;
- (void)transcriptWillLoad;
- (void)transcriptDidLoad;
- (void)nameDisplayChanged:(id)arg1;
- (id)fragmentForChatItem:(id)arg1;
- (id)appendFragmentForChatItem:(id)arg1 toNode:(id)arg2;
- (void)removeFragmentForChatItem:(id)arg1;
- (void)addFragmentIdPropertiesToElement:(id)arg1 forChatItem:(id)arg2;

@end

@interface SystemMessageFragmentProvider : TranscriptFragmentProvider
{
    NSMutableDictionary *_persons;
}

- (id)initWithTranscriptStyleController:(id)arg1;
- (id)role;
- (void)transcriptWillLoad;
- (void)dealloc;
- (void)makeVisible;
- (void)makeInvisible;
- (id)setupMutableArrayForIMHandle:(id)arg1;
- (void)nameDisplayChanged:(id)arg1;
- (id)fragmentForChatItem:(id)arg1;

@end

@interface AnnouncementFragmentProvider : SystemMessageFragmentProvider
{
}

@end

@interface AppKitToSuperParserContext : IMAttributedStringParserContext
{
    NSMutableAttributedString *_superFormat;
    NSMutableArray *_fileTransferGUIDs;
    NSColor *_bodyBackgroundColor;
    NSColor *_bodyForegroundColor;
    long long _baseWritingDirection;
    BOOL _didAddBodyAttributes;
}

- (id)initWithAttributedString:(id)arg1 baseWritingDirection:(long long)arg2 bodyBackgroundColor:(id)arg3 bodyForegroundColor:(id)arg4;
- (void)dealloc;
- (id)_attributesForAttachmentWithAttributes:(id)arg1;
- (id)name;
- (id)resultsForLogging;
- (void)parser:(id)arg1 foundAttributes:(id)arg2 inRange:(struct _NSRange)arg3;
- (id)superFormatString;
- (id)fileTransferGUIDs;
- (void)_preloadImage:(id)arg1;

@end

@interface ArchivedMessagePlaceholder : NSObject <NSCoding>
{
    BaseInstantMessage *_message;
    IMChatItem *_chatItem;
}

+ (void)setupArchivedMessageDecoding;
+ (void)setupArchivedMessageEncoding;
- (id)initWithChatItem:(id)arg1;
- (void)dealloc;
- (id)initWithCoder:(id)arg1;
- (void)encodeWithCoder:(id)arg1;

@end

@interface BaseInstantMessage : IMMessage
{
    NSColor *_fgColor;
    NSColor *_bgColor;
}

- (void)dealloc;
- (id)speechDescription;
- (id)foregroundColor;
- (id)backgroundColor;
- (BOOL)isInteresting;

@end

@interface BuddyIconFragment : NSObject
{
    DOMDocumentFragment *_fragment;
    NSString *_personGuid;
    DOMElement *_container;
    DOMElement *_standardRepresentationElement;
    IMChatItem *_chatItem;
    IMHandle *_handle;
    BOOL _usingStaticRepresentation;
}

- (id)initWithChatItem:(id)arg1 size:(unsigned int)arg2 inChat:(id)arg3;
- (void)useActiveRepresentation:(id)arg1;
- (void)useStaticRepresentation;
- (void)dealloc;
- (id)fragment;
- (id)chatItem;

@end

@interface BuddyIconFragmentProvider : TranscriptFragmentProvider
{
    unsigned int _iconSize;
    NSMutableArray *_buddyIconFragments;
    BuddyIconFragment *_activeIcon;
    DOMElement *_pluginElement;
}

- (id)role;
- (id)fragmentIdForChatItem:(id)arg1;
- (id)initWithTranscriptStyleController:(id)arg1;
- (unsigned int)iconSize;
- (void)setIconSize:(unsigned int)arg1;
- (void)transcriptWillLoad;
- (void)_updateIconContainerRule;
- (void)_updatePersonIconRule;
- (void)dealloc;
- (id)_personiconUrlForKey:(id)arg1;
- (void)createRulesForIMHandle:(id)arg1;
- (void)updateRulesForIMHandle:(id)arg1;
- (id)_buildPluginElement;
- (void)_updatePluginElement:(id)arg1 forIMHandle:(id)arg2;
- (id)pluginElement;
- (void)refreshActiveIcon;
- (id)fragmentForChatItem:(id)arg1;
- (void)removeFragmentForChatItem:(id)arg1;

@end

@interface ChatItemFragmentProvider : TranscriptFragmentProvider
{
    BOOL _incomingContentHidden;
    unsigned int _containerIndex;
    DOMDocumentFragment *_lastMessageContainer;
    NSMutableArray *_timestamps;
}

- (id)fragmentIdForChatItem:(id)arg1;
- (id)initWithTranscriptStyleController:(id)arg1;
- (void)dealloc;
- (id)providerForChatItem:(id)arg1;
- (id)appendFragmentForChatItem:(id)arg1 toNode:(id)arg2;
- (void)removeFragmentForChatItem:(id)arg1;
- (void)makeIncomingContentVisible;
- (void)makeIncomingContentHidden;
- (struct CGRect)rectOfChatItem:(id)arg1;
- (struct CGRect)boundsOfChatItem:(id)arg1;

@end

@interface DOMDocument (FezWebUtil)
- (id)createDivElement;
- (id)createSpanElement;
@end

@interface DOMElement (FezWebUtil)
- (struct CGRect)boundsRectForElement;
- (struct CGRect)minimumDisplayRectForElement;
- (void)appendValue:(id)arg1 toAttribute:(id)arg2;
- (id)parentElementWithAttribute:(id)arg1 havingValue:(id)arg2;
- (void)makeDescendantsPerformFunction:(void)arg1;
@end

@interface DateFragmentProvider : TranscriptFragmentProvider
{
    NSMutableArray *_preciseFragments;
    NSMutableArray *_longFragments;
    NSMutableArray *_dateFragments;
    NSMutableArray *_timeFragments;
}

+ (void)initialize;
- (id)initWithTranscriptStyleController:(id)arg1;
- (void)dealloc;
- (void)transcriptWillLoad;
- (void)_adjustElement:(id)arg1 usingFormatter:(long long)arg2;
- (void)adjustDateFragmentsForTimeChange;
- (void)dateFormatDidChange;
- (id)_formatDate:(id)arg1 withFormatter:(long long)arg2;
- (id)_baseDateFragmentWithString:(id)arg1 timestamp:(double)arg2;
- (id)_genericDateFragmentForDate:(id)arg1 formatter:(long long)arg2 cache:(id)arg3;
- (id)preciseStringForDate:(id)arg1;
- (id)preciseFragmentForDate:(id)arg1;
- (id)longStringForDate:(id)arg1;
- (id)longFragmentForDate:(id)arg1;
- (id)dateStringForDate:(id)arg1;
- (id)dateFragmentForDate:(id)arg1;
- (id)timeStringForDate:(id)arg1;
- (id)timeFragmentForDate:(id)arg1;
- (id)formatDate:(id)arg1 roundInterval:(int)arg2 showDate:(BOOL)arg3 showTime:(BOOL)arg4 showSeconds:(BOOL)arg5;

@end

@interface TimestampFragmentProvider : SystemMessageFragmentProvider
{
}

- (void)transcriptWillLoad;
- (id)fragmentIdForChatItem:(id)arg1;
- (id)_displayableDateFragmentForDate:(id)arg1;
- (id)fragmentForChatItem:(id)arg1;
- (void)hideTimestamps;
- (void)showTimestamps;
- (void)makeTimestampsInvisible;
- (void)makeTimestampsVisible;

@end

@interface DatestampFragmentProvider : TimestampFragmentProvider
{
}

- (id)fragmentIdForChatItem:(id)arg1;
- (id)_displayableDateFragmentForDate:(id)arg1;

@end

@interface DocumentFragmentProvider : TranscriptFragmentProvider
{
    DOMElement *_baseAppendPoint;
    NSString *_backgroundImagePath;
    NSColor *_selectionColor;
}

+ (id)baseDocumentString;
- (void)dealloc;
- (void)showNames;
- (void)hideNames;
- (void)showPictures;
- (void)hidePictures;
- (void)hideMessageContent;
- (void)showMessageContent;
- (void)hideScrollbars;
- (void)showScrollbars;
- (void)hideBackground;
- (void)showBackground;
- (void)makeNotSelectable;
- (void)makeSelectable;
- (void)transcriptWillLoad;
- (void)transcriptDidLoad;
- (void)setBackgroundImage:(id)arg1;
- (id)baseAppendPoint;

@end

@interface EmoteFragmentProvider : TranscriptFragmentProvider
{
}

- (id)role;
- (void)transcriptWillLoad;
- (id)fragmentForChatItem:(id)arg1;

@end

@interface EmoticonFragmentProvider : TranscriptFragmentProvider
{
}

+ (id)emoticonForRawText:(id)arg1 name:(id)arg2 imageURL:(id)arg3 message:(id)arg4 inChat:(id)arg5;
- (void)transcriptWillLoad;
- (void)updateCSSRulesShowingImageVariants:(BOOL)arg1;
- (void)showImageVariants;
- (void)showTextVariants;

@end

@interface ErrorFragmentProvider : SystemMessageFragmentProvider
{
}

@end

@interface FezDDResultContainer : NSObject
{
    NSString *_guid;
    struct _NSRange _range;
    BOOL _hasActions;
    struct __DDResult *_ddResult;
    DDScannerResult *_ddScannerResult;
    NSMutableArray *_domNodes;
    NSMutableArray *_relatedResultIDs;
}

- (id)initWithDDResult:(struct __DDResult *)arg1 range:(struct _NSRange)arg2;
- (void)dealloc;
- (id)guid;
- (struct __DDResult *)ddResult;
- (BOOL)hasActions;
- (struct _NSRange)range;
- (id)type;
- (id)fullMatchedString;
- (void)addDOMNode:(id)arg1;
- (id)domNodes;
- (void)addRelatedResultID:(id)arg1;
- (id)relatedResultIDs;

@end

@interface FezDDScanner : NSObject
{
    DDPatternCompiler *_patternCompiler;
    struct __DDScanner *_urlScanner;
    struct __DDScanner *_fullScanner;
    struct dispatch_queue_s *_workerQueue;
    unsigned long long _scanGUIDCounter;
    NSMapTable *_scanToHandlerMap;
    BOOL _buildingFullScanner;
}

+ (id)sharedInstance;
- (id)init;
- (void)dealloc;
- (void)_fullScannerBuildDidFinish:(id)arg1;
- (void)_postDDScannerBuildNotification;
- (void)buildFullScanner;
- (BOOL)isFullScannerReady;
- (id)_newFezDDResultContainerArrayForDDResultRefArray:(struct __CFArray *)arg1 inAttributedStringArray:(id)arg2;
- (struct __CFArray *)newDDResultArrayByScanningStringForURLs:(id)arg1;
- (id)scanAttributedStringForURLs:(id)arg1;
- (void)removeAllDataDetectorAttributesFromAttributedString:(id)arg1;
- (BOOL)applyResults:(id)arg1 toAttributedString:(id)arg2 timeOfMessage:(id)arg3;
- (void)_main_scan:(id)arg1 results:(id)arg2;
- (void)_worker_scan:(id)arg1 attributedStrings:(id)arg2;
- (void)unregisterCompletionHandler:(id)arg1;
- (id)scanInstantMessageArray:(id)arg1 completionHandler:(id)arg2;

@end

@interface FezResourceURLProtocol : NSObject
{
    void *_protocol;
    NSURLRequest *_request;
}

+ (id)customProtocolScheme;
+ (BOOL)canHandleRequest:(id)arg1;
+ (void)shouldRegisterProtocol:(BOOL)arg1;
- (id)initWithCFURLProtocol:(struct _CFURLProtocol *)arg1 usingCallbacks:(const struct CFURLProtocolInstanceCallbacks **)arg2;
- (void)dealloc;
- (void)schedule:(struct __CFRunLoop *)arg1 inMode:(id)arg2;
- (void)unschedule:(struct __CFRunLoop *)arg1 inMode:(id)arg2;
@property(readonly) NSURLRequest *request;
- (void)start;
- (void)stop;
- (void)halt;
- (void)resume;
- (void)resourceDataRequested:(id)arg1;

@end

@interface HeaderFragmentProvider : SystemMessageFragmentProvider
{
    DOMCSSPageRule *_headerRule;
}

- (id)role;
- (void)transcriptWillLoad;
- (void)dealloc;
- (id)fragmentForChatItem:(id)arg1;

@end

@interface IMSmilifier : NSObject
{
    struct _IMSmileyEntry **_startTable;
    struct _IMSmileyEntry *_entryTable;
    NSMutableDictionary *_longerASCIIRepresentationMap;
    NSMutableDictionary *_descriptionToSmileyMap;
    NSMutableArray *_allSmileys;
    unsigned long long _counter;
}

+ (id)sharedInstance;
- (id)init;
- (void)dealloc;
- (void)_generateTables;
- (void)_loadSmileyPacks;
- (void)load;
- (id)allSmileys;
- (id)smileyWithDescription:(id)arg1;
- (void)prepareAppKitFormatStringForSmilification:(id)arg1;
- (void)_smilifyString:(id)arg1 callback:(id)arg2;
- (void)addSmileysToAttributedString:(id)arg1 style:(int)arg2;
- (void)addSmileysToAttributedString:(id)arg1 usingBlock:(id)arg2;

@end

@interface ImagePlaceholderProtocol : FezResourceURLProtocol
{
}

+ (id)customProtocolScheme;
- (void)resourceDataRequested:(id)arg1;

@end

@interface InputLineToSuperParserContext : AppKitToSuperParserContext
{
    IMHandle *_handle;
    NSMutableArray *_localURLsToArchiveAndSend;
    BOOL _finished;
}

- (id)initWithAttributedString:(id)arg1 baseWritingDirection:(long long)arg2 bodyBackgroundColor:(id)arg3 bodyForegroundColor:(id)arg4 handle:(id)arg5 finished:(BOOL)arg6;
- (void)dealloc;
- (id)_attributesForAttachmentWithAttributes:(id)arg1;
- (id)localURLsToArchiveAndSend;

@end

@interface KnockKnockFragmentProvider : TranscriptFragmentProvider
{
    NSString *_knockKnockReplacementMessage;
    unsigned int _messageCount;
}

- (void)transcriptWillLoad;
- (void)setKnockKnockReplacementMessage:(id)arg1;
- (id)knockKnockReplacementMessage;
- (void)hideMessageContent;
- (void)showMessageContent;
- (void)dealloc;
- (id)fragmentForChatItem:(id)arg1;
- (struct CGRect)messagePreviewBounds;

@end

@interface LazyResizingImageRep : NSImageRep
{
    NSImage *_originalImage;
    NSImage *_resizedImage;
    struct CGRect _targetFrame;
    struct CGSize _targetSize;
}

- (id)initWithImage:(id)arg1 targetFrame:(struct CGRect)arg2 targetSize:(struct CGSize)arg3;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)resizedImage;
- (BOOL)draw;
- (BOOL)hasAlpha;

@end

@interface MarkFragmentProvider : SystemMessageFragmentProvider
{
}

- (id)role;
- (void)transcriptDidLoad;
- (id)fragmentForChatItem:(id)arg1;

@end

@interface MessageBodyFragmentProvider : TranscriptFragmentProvider
{
    NSColor *_localFontColor;
    NSFont *_localFont;
    NSString *_localFontFamily;
    long long _localFontSize;
    NSColor *_remoteFontColor;
    NSFont *_remoteFont;
    unsigned int _watchMessageAddressing:1;
    unsigned int _remoteUserOverrideFormatting:1;
    unsigned int _localFontIsBold:1;
    unsigned int _localFontIsItalic:1;
}

- (id)fragmentIdForChatItem:(id)arg1;
- (void)setWatchMessageAddressing:(BOOL)arg1;
- (void)setRemoteUserOverrideFormatting:(BOOL)arg1;
- (void)setLocalFontColor:(id)arg1;
- (void)setRemoteFontColor:(id)arg1;
- (void)setLocalFont:(id)arg1;
- (void)setRemoteFont:(id)arg1;
- (void)_updateMeRule;
- (void)_updateRemoteRule;
- (void)_updateWatchMessageAddressingRule;
- (void)transcriptWillLoad;
- (id)ruleNameForContainerLink;
- (id)ruleNameForContainerAddressing;
- (id)ruleNameForEmoteLink;
- (id)ruleNameForEmoteAddressing;
- (id)ruleNameForEmoteBody;
- (void)dealloc;
- (void)_pruneTag:(id)arg1 fromTopOfNode:(id)arg2;
- (id)fragmentForChatItem:(id)arg1;
- (void)provideContrastOverridesForCriterion:(id)arg1 color:(id)arg2 fromMe:(BOOL)arg3;

@end

@interface MessageContainerFragmentProvider : TranscriptFragmentProvider
{
    unsigned int _containerIndex;
    BOOL _remoteUserOverrideFormatting;
    BOOL _useIMHandleColor;
    NSMutableSet *_visibleColors;
    NSMutableSet *_visibleIMHandles;
}

- (id)role;
- (id)fragmentIdForChatItem:(id)arg1;
- (void)removeFragmentForChatItem:(id)arg1;
- (id)backgroundColorForMessage:(id)arg1;
- (void)setRemoteUserOverrideFormatting:(BOOL)arg1;
- (void)setLocalBackgroundColor:(id)arg1;
- (void)setRemoteBackgroundColor:(id)arg1;
- (void)setWatchMessageAddressing:(BOOL)arg1;
- (void)forceUpdateDisplayRules;
- (void)forceUpdateIMHandleRules;
- (void)forceUpdateColorRules;
- (id)initWithTranscriptStyleController:(id)arg1;
- (void)dealloc;
- (void)showNames;
- (void)hideNames;
- (void)showPictures;
- (void)hidePictures;
- (void)applyClassAttributesToElement:(id)arg1 forChatItem:(id)arg2 prefix:(id)arg3 extraClass:(id)arg4;
- (id)fragmentForChatItem:(id)arg1;
- (void)prepareForNonMessageChatItem;
- (void)processDisplayRulesForChatItem:(id)arg1;
- (id)standardRuleDictionaryForColor:(id)arg1 fromMe:(BOOL)arg2 important:(BOOL)arg3;
- (id)classFormatWithCriterion:(id)arg1 prefix:(id)arg2 fromMe:(BOOL)arg3;
- (id)ruleFormatWithCriterion:(id)arg1 prefix:(id)arg2 fromMe:(BOOL)arg3;
- (void)updateRulesForColor:(id)arg1;
- (void)updateRulesForCriterion:(id)arg1 color:(id)arg2 displayColor:(id)arg3 fromMe:(BOOL)arg4 important:(BOOL)arg5;
- (void)updateRulesForIMHandle:(id)arg1;
- (void)prepareForChatItem:(id)arg1;
- (struct CGRect)messagePreviewBounds;
- (struct CGRect)boundsOfChatItem:(id)arg1;
- (id)colorForIMHandle:(id)arg1;

@end

@interface NSBezierPath (RoundedRectangle)
+ (id)bezierPathWithRoundRectInRect:(struct CGRect)arg1 radius:(float)arg2;
+ (id)bezierPathWithRoundTopRightRectInRect:(struct CGRect)arg1 radius:(float)arg2;
+ (id)bezierPathWithRoundTopRectInRect:(struct CGRect)arg1 radius:(float)arg2;
+ (id)openBezierPathWithRoundTopRectInRect:(struct CGRect)arg1 radius:(float)arg2;
+ (id)openBezierPathWithRoundBottomRectInRect:(struct CGRect)arg1 radius:(float)arg2;
+ (id)bezierPathWithRoundBottomRectInRect:(struct CGRect)arg1 radius:(float)arg2;
+ (id)openBezierPathWithRect:(struct CGRect)arg1 hasTop:(BOOL)arg2 hasBottom:(BOOL)arg3;
+ (id)bezierPathWithPieChart:(float)arg1 inRect:(struct CGRect)arg2 startAngle:(float)arg3;
@end

@interface NSBitmapImageRep (RawDataAdditions)
- (id)JPEGDataWithCompression:(float)arg1;
@end

@interface NSButton (ImageSizingAdditions)
- (id)_templateImageFrom:(id)arg1 ofSize:(struct CGSize)arg2;
- (void)setTemplateImageSize:(struct CGSize)arg1;
@end

@interface NSCell (Cocoa64bitUtil)
- (void)setCGFLoatValue:(double)arg1;
- (double)cgFloatValue;
- (void)takeCGFloatValueFrom:(id)arg1;
@end

@interface NSColor (FezColorUtilAdditions)
+ (id)cannedColorPlist;
+ (id)cannedColorWithTag:(int)arg1;
+ (id)randomizedCannedColors;
+ (id)colorWithWebIntValue:(int)arg1;
- (BOOL)isEqualToColor:(id)arg1;
- (int)webIntValue;
- (id)webStringValue;
@end

@interface NSColor (FezWebUtil)
- (double)whiteness;
- (double)grayness;
- (void)_getRGBComponentValueRed:(long long *)arg1 green:(long long *)arg2 blue:(long long *)arg3;
- (id)rgbaColor;
- (id)hexColor;
- (id)safeLinkColor;
- (id)htmlString;
- (id)cssValue;
- (id)bgCssValue;
@end

@interface NSControl (Cocoa64bitUtil)
- (void)setCGFLoatValue:(double)arg1;
- (double)cgFloatValue;
- (void)takeCGFloatValueFrom:(id)arg1;
@end

@interface NSData (ImageTypeChecking)
- (id)imageFileExtension;
- (BOOL)isGIF;
- (BOOL)isJPEG;
@end

@interface NSDataRetainingImage : NSImage
{
    NSData *_originalDataBlob;
    NSString *_fileExtension;
}

+ (BOOL)canInitWithPasteboard:(id)arg1;
- (id)initWithData:(id)arg1;
- (id)initWithContentsOfFile:(id)arg1;
- (id)initWithPath:(id)arg1;
- (id)initWithPasteboard:(id)arg1 sender:(id)arg2;
- (id)initWithPasteboard:(id)arg1;
- (void)setOriginalData:(id)arg1;
- (id)originalData;
- (id)fileExtension;
- (id)writeToPath:(id)arg1 withName:(id)arg2 unique:(BOOL)arg3 atomically:(BOOL)arg4;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (void)dealloc;
- (id)imageWithMaxSize:(int)arg1;
- (id)imageWithMaxSize:(int)arg1 withLeftPad:(int)arg2;

@end

@interface NSFont (FezWebUtil)
- (id)cssFontFamilyName;
- (id)fontDeltaName;
- (id)cssFontSizeAndFamilyIsImportant:(BOOL)arg1;
- (id)cssFontSizeAndFamily;
- (id)cssValueIsImportant:(BOOL)arg1;
- (id)cssValueDictionaryIsImportant:(BOOL)arg1;
- (id)cssValue;
- (id)aimFontSize;
- (BOOL)hasBoldAttribute;
- (BOOL)hasItalicAttribute;
@end

@interface NSImage (ImageEffects)
+ (id)imageNamed:(id)arg1 state:(int)arg2;
+ (id)imageNamed:(id)arg1 state:(int)arg2 size:(struct CGSize)arg3;
@end

@interface NSImage (ImageRelativeSizing)
- (void)sizeImageToFitInSize:(struct CGSize)arg1;
@end

@interface NSImage (NSDataRetainingWarnings)
- (id)originalData;
@end

@interface NSImage (SimpleImageEffects)
- (id)imageByApplyingShadow:(id)arg1;
@end

@interface NSImage (TintedImageAdditions)
- (id)tintedImageWithColor:(id)arg1;
- (id)tintedImageWithColor:(id)arg1 withSize:(struct CGSize)arg2;
@end

@interface NSImage (iChatAdditions)
+ (id)imageNamed:(id)arg1 inBundle:(id)arg2;
+ (id)cgImageImageFromCGImageRef:(struct CGImage *)arg1;
- (struct CGImage *)CGImage;
- (BOOL)imageIsWithinMaxSize:(struct CGSize)arg1 andMinSize:(struct CGSize)arg2;
- (struct CGSize)sizeForDetailedDisplayInWindow:(id)arg1;
- (struct CGSize)displaySizeForWebImage;
- (id)GIFDataFromRepWithMaxSize:(struct CGSize)arg1 maxLength:(int)arg2 minSize:(struct CGSize)arg3;
- (id)rawGIFData;
- (struct CGSize)largestRepSize;
- (struct CGSize)largestRepPixelSize;
- (void)drawNicelyScaledInRect:(struct CGRect)arg1 operation:(unsigned long long)arg2 fraction:(float)arg3;
- (void)drawNicelyScaledInRect:(struct CGRect)arg1 inView:(id)arg2 operation:(unsigned long long)arg3 fraction:(float)arg4;
- (void)drawStretchedInFrame:(struct CGRect)arg1 inView:(id)arg2 capWidth:(float)arg3 alpha:(float)arg4;
- (id)_resizedImageWithFrame:(struct CGRect)arg1 inSize:(struct CGSize)arg2 lazy:(BOOL)arg3;
- (id)lazyImageWithMaxSize:(int)arg1;
- (id)imageWithMaxSize:(int)arg1;
- (id)imageScaledAndCenteredInSize:(int)arg1;
- (id)imageWithMaxSize:(int)arg1 withLeftPad:(int)arg2;
- (id)imageWithSize:(struct CGSize)arg1;
- (id)JPEGDataWithMaxSize:(float)arg1 minSize:(float)arg2 centerInSize:(BOOL)arg3 compression:(float)arg4;
- (id)bitmapImageRep;
- (id)bitmapImageRepWithPadding:(float)arg1;
@end

@interface NSImageRep (GIFDetectionAdditions)
- (BOOL)hasExpectedGIFAttributes;
- (BOOL)isGIF;
@end

@interface NSMutableAttributedString (FezExtensions)
- (void)setAlignment:(unsigned long long)arg1;
@end

@interface NSNumber (Cocoa64bitUtil)
+ (id)numberWithCGFloat:(double)arg1;
+ (id)numberWithFourCharCode:(unsigned int)arg1;
- (id)initWithCGFloat:(double)arg1;
- (double)cgFloatValue;
- (unsigned int)fourCharCode;
@end

@interface NSString (Cocoa64bitUtil)
- (double)cgFloatValue;
@end

@interface NSString (FezWebUtil)
+ (id)stringWithNonBreakingSpace;
+ (id)stringWithHorizontalEllipsis;
@end

@interface NSURL (FezWebUtil)
- (void)openURL;
@end

@interface NSUserDefaults (SixtyFourBitAdditions)
- (double)cgFloatForKey:(id)arg1;
- (void)setCGFloat:(double)arg1 forKey:(id)arg2;
@end

@interface PersonNameFragmentProvider : TranscriptFragmentProvider
{
    NSMutableDictionary *_persons;
}

- (id)initWithTranscriptStyleController:(id)arg1;
- (void)dealloc;
- (void)transcriptWillLoad;
- (void)nameDisplayChanged:(id)arg1;
- (id)setForIMHandle:(id)arg1;
- (id)fragmentForChatItem:(id)arg1;

@end

@interface PhoneNumberFormatter : NSFormatter
{
}

+ (id)numbersSet;
+ (id)nonNumbersSet;
+ (id)nonNumbersAndDashSet;
+ (BOOL)getObjectValue:(id *)arg1 forString:(id)arg2 errorDescription:(id *)arg3;
+ (id)stringForObjectValue:(id)arg1;
+ (id)smsNumberStringFromString:(id)arg1;
+ (id)plainPhoneNumberFromString:(id)arg1;
- (BOOL)getObjectValue:(id *)arg1 forString:(id)arg2 errorDescription:(id *)arg3;
- (id)stringForObjectValue:(id)arg1;

@end

@interface ShadowedImageRep : NSImageRep
{
    NSImage *_imageToShadow;
    NSShadow *_shadow;
}

- (id)initWithImage:(id)arg1 shadow:(id)arg2;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (BOOL)draw;
- (void)dealloc;
- (BOOL)hasAlpha;

@end

@interface Smiley : NSObject
{
    NSString *_description;
    NSString *_speechDescription;
    NSString *_imagePath;
    NSArray *_ASCIIRepresentations;
    NSImage *_image;
    NSAttributedString *_miniImageRepresentation;
    NSAttributedString *_smallImageRepresentation;
    NSAttributedString *_largeImageRepresentation;
}

- (id)_initWithDescription:(id)arg1 speechDescription:(id)arg2 imagePath:(id)arg3 ASCIIRepresentations:(id)arg4;
- (void)dealloc;
- (id)description;
- (id)speechDescription;
- (id)imageURL;
- (id)image;
- (id)_newScaledImageWithSize:(struct CGSize)arg1 canvasSize:(struct CGSize)arg2;
- (id)_newImageRepresentationWithImage:(id)arg1 baseline:(float)arg2;
- (id)miniImageRepresentation;
- (id)smallImageRepresentation;
- (id)largeImageRepresentation;
- (id)ASCIIRepresentations;

@end

@interface StatusChangeFragmentProvider : SystemMessageFragmentProvider
{
}

@end

@interface SuperToAppKitParserContext : IMFromSuperParserContext
{
    NSMutableAttributedString *_appKitAttributedString;
    NSColor *_bodyBackgroundColor;
    NSColor *_bodyForegroundColor;
    long long _baseWritingDirection;
    BOOL _didAddBodyAttributes;
}

- (id)initWithAttributedString:(id)arg1;
- (void)dealloc;
- (id)appKitAttributedString;
- (id)bodyBackgroundColor;
- (long long)baseWritingDirection;
- (id)name;
- (id)resultsForLogging;
- (void)parserDidStart:(id)arg1 bodyAttributes:(id)arg2;
- (void)parser:(id)arg1 foundAttributes:(id)arg2 inRange:(struct _NSRange)arg3 characters:(id)arg4;
- (void)parser:(id)arg1 foundAttributes:(id)arg2 inRange:(struct _NSRange)arg3 fileTransferGUID:(id)arg4 filename:(id)arg5 bookmark:(id)arg6 width:(id)arg7 height:(id)arg8;

@end

@interface SuperToSpeechParserContext : IMSuperToPlainParserContext
{
}

- (id)name;
- (void)parser:(id)arg1 foundAttributes:(id)arg2 inRange:(struct _NSRange)arg3 characters:(id)arg4;
- (void)parser:(id)arg1 foundAttributes:(id)arg2 inRange:(struct _NSRange)arg3 fileTransferGUID:(id)arg4 filename:(id)arg5 bookmark:(id)arg6 width:(id)arg7 height:(id)arg8;

@end

@interface SuperToWebKitParserContext : IMFromSuperParserContext
{
    IMChatItem *_chatItem;
    BaseInstantMessage *_message;
    DOMHTMLElement *_messageElement;
    DOMHTMLElement *_spanElement;
    DOMDocument *_dom;
    TranscriptStyleController *_styleController;
    NSString *_defaultFontFamily;
    long long _defaultFontSize;
    unsigned int _messageIsEmote:1;
    unsigned int _didTrimEmotePrefix:1;
    unsigned int _isEntireMessageBold:1;
    unsigned int _isEntireMessageItalic:1;
    unsigned int _defaultFontIsBold:1;
    unsigned int _defaultFontIsItalic:1;
}

- (id)initWithChatItem:(id)arg1 dom:(id)arg2 styleController:(id)arg3 defaultFontFamily:(id)arg4 defaultFontSize:(long long)arg5 defaultFontIsBold:(BOOL)arg6 defaultFontIsItalic:(BOOL)arg7;
- (void)dealloc;
- (id)outMessageElement;
- (BOOL)_workaroundWebKitLineHeightBug;
- (id)name;
- (id)_outMessageElementAsString;
- (id)resultsForLogging;
- (void)parserDidStart:(id)arg1 bodyAttributes:(id)arg2;
- (void)parser:(id)arg1 foundAttributes:(id)arg2 inRange:(struct _NSRange)arg3 characters:(id)arg4;
- (void)parser:(id)arg1 foundAttributes:(id)arg2 inRange:(struct _NSRange)arg3 fileTransferGUID:(id)arg4 filename:(id)arg5 bookmark:(id)arg6 width:(id)arg7 height:(id)arg8;
- (void)parserDidEnd:(id)arg1;
- (BOOL)shouldPreprocess;
- (id)parser:(id)arg1 preprocessedAttributesForAttributes:(id)arg2 range:(struct _NSRange)arg3;

@end

@interface TintedImageRep : NSImageRep
{
    NSImage *_imageToTint;
    NSColor *_tintColor;
}

- (id)initWithImage:(id)arg1 tintColor:(id)arg2;
- (id)copyWithZone:(struct _NSZone *)arg1;
- (BOOL)draw;
- (void)dealloc;
- (BOOL)hasAlpha;

@end

@interface TranscriptStyleController : NSObject
{
    WebView *_webView;
    DOMDocument *_dom;
    DOMHTMLElement *_head;
    DOMHTMLElement *_body;
    DOMCSSStyleSheet *_style;
    NSColor *_backgroundColor;
    NSURL *_backgroundImage;
    NSMutableArray *_fragments;
    NSMutableSet *_dirtyCSSRules;
    NSMutableDictionary *_cssCache;
    NSMutableArray *_cssCacheOrder;
    NSMutableDictionary *_cssRuleMap;
    unsigned int _changeCount;
    int _inBatchViewChangeCount;
    BOOL _batchChangeRequiresRebuild;
    DocumentFragmentProvider *_documentFragmentProvider;
    KnockKnockFragmentProvider *_knockKnockFragmentProvider;
    ChatItemFragmentProvider *_chatItemFragmentProvider;
    MessageContainerFragmentProvider *_messageContainerFragmentProvider;
    MessageBodyFragmentProvider *_messageBodyFragmentProvider;
    BuddyIconFragmentProvider *_buddyIconFragmentProvider;
    EmoticonFragmentProvider *_emoticonFragmentProvider;
    id <FileTransferFragmentProvider> _fileTransferFragmentProvider;
    PersonNameFragmentProvider *_personNameFragmentProvider;
    DateFragmentProvider *_dateFragmentProvider;
    EmoteFragmentProvider *_emoteFragmentProvider;
    SystemMessageFragmentProvider *_systemMessageFragmentProvider;
    TimestampFragmentProvider *_timestampFragmentProvider;
    DatestampFragmentProvider *_datestampFragmentProvider;
    ErrorFragmentProvider *_errorFragmentProvider;
    HeaderFragmentProvider *_headerFragmentProvider;
    StatusChangeFragmentProvider *_statusChangeFragmentProvider;
    MarkFragmentProvider *_markFragmentProvider;
    AnnouncementFragmentProvider *_announcementFragmentProvider;
    BOOL _isFirstLoad;
    BOOL _allowsPlugins;
    BOOL _remoteUserOverrideFormatting;
    BOOL _watchMessageAddressing;
    BOOL _messageContentIsHidden;
    BOOL _shouldCacheUncommittedChatItems;
    BOOL _isRebuildingUncommittedChatItems;
    NSMutableArray *_uncommittedChatItems;
    IMChatItem *_lastCommittedChatItem;
}

+ (Class)documentFragmentProviderClass;
+ (Class)chatItemFragmentProviderClass;
+ (Class)messageContainerFragmentProviderClass;
+ (Class)messageBodyFragmentProviderClass;
+ (Class)emoticonFragmentProviderClass;
+ (Class)emoteFragmentProviderClass;
+ (Class)fileTransferFragmentProviderClass;
+ (void)setFileTransferFragmentProviderClass:(Class)arg1;
+ (Class)datestampFragmentProviderClass;
+ (Class)timestampFragmentProviderClass;
+ (Class)errorFragmentProviderClass;
+ (Class)systemMessageFragmentProviderClass;
+ (Class)headerFragmentProviderClass;
+ (Class)statusChangeFragmentProviderClass;
+ (Class)announcementFragmentProviderClass;
+ (Class)markFragmentProviderClass;
+ (Class)personNameFragmentProviderClass;
+ (Class)buddyIconFragmentProviderClass;
+ (Class)dateFragmentProviderClass;
+ (Class)knockKnockFragmentProviderClass;
- (id)documentFragmentProvider;
- (id)chatItemFragmentProvider;
- (id)messageContainerFragmentProvider;
- (id)messageBodyFragmentProvider;
- (id)emoticonFragmentProvider;
- (id)emoteFragmentProvider;
- (id)fileTransferFragmentProvider;
- (id)datestampFragmentProvider;
- (id)timestampFragmentProvider;
- (id)errorFragmentProvider;
- (id)systemMessageFragmentProvider;
- (id)headerFragmentProvider;
- (id)statusChangeFragmentProvider;
- (id)announcementFragmentProvider;
- (id)markFragmentProvider;
- (id)personNameFragmentProvider;
- (id)buddyIconFragmentProvider;
- (id)dateFragmentProvider;
- (id)knockKnockFragmentProvider;
- (id)initWithWebView:(id)arg1;
- (id)window;
- (void)transcriptDidLoad;
- (void)dealloc;
- (void)beginChanges;
- (void)_rebuildCSSRuleMap;
- (BOOL)_firstLoadApplyQueuedCSSRules;
- (int)changeCount;
- (void)_applyChanges;
- (void)applyCurrentChanges;
- (void)endChanges;
- (void)setDOMCSSRule:(id)arg1 forSelector:(id)arg2;
- (id)DOMCSSRuleForSelector:(id)arg1;
- (BOOL)_applyQueuedCSSRules;
- (void)applyCSSSelector:(id)arg1 property:(id)arg2 value:(id)arg3 priority:(id)arg4;
- (void)applyCSSSelector:(id)arg1 property:(id)arg2 value:(id)arg3;
- (void)applyCSSSelector:(id)arg1 fromDictionary:(id)arg2;
- (void)clearCSSSelector:(id)arg1;
- (void)clearCSSSelector:(id)arg1 forProperties:(id)arg2;
- (void)_setNeedsRebuild;
- (void)beginBatchViewChange;
- (BOOL)endBatchViewChange;
- (void)makeSystemMessagesVisible;
- (void)makeSystemMessagesInvisible;
- (void)hideTimestamps;
- (void)showTimestamps;
- (void)hideMessageContent;
- (void)showMessageContent;
- (void)makeTimestampsInvisible;
- (void)makeTimestampsVisible;
- (void)hideScrollbars;
- (void)showScrollbars;
- (void)showSmileys;
- (void)hideSmileys;
- (void)showPictures;
- (void)hidePictures;
- (void)showNames;
- (void)hideNames;
- (void)hideBackground;
- (void)showBackground;
- (void)makeNotSelectable;
- (void)makeSelectable;
- (void)setBackgroundColor:(id)arg1;
- (void)setBackgroundImage:(id)arg1;
- (id)backgroundImageURL;
- (void)appendChatItem:(id)arg1;
- (void)removeChatItem:(id)arg1;
- (void)replaceChatItem:(id)arg1 withChatItem:(id)arg2;
- (struct CGRect)screenBoundsForElement:(id)arg1;
- (struct CGRect)screenBoundsForElementID:(id)arg1;
- (struct CGRect)messagePreviewBounds;
- (struct CGRect)rectOfChatItem:(id)arg1;
- (struct CGRect)boundsOfChatItem:(id)arg1;
- (id)lastChatItem;
- (id)DOM;
- (id)body;
- (id)head;
- (id)style;
- (void)emptyBody;
- (void)removeNodeAndChildren:(id)arg1;
- (void)removeChildren:(id)arg1;
- (void)bodyFinishLayout;
- (void)setWatchMessageAddressing:(BOOL)arg1;
- (void)setRemoteUserOverrideFormatting:(BOOL)arg1;
- (void)setAllowsPlugins:(BOOL)arg1;
- (BOOL)allowsPlugins;
- (void)localUserSetBackgroundColor:(id)arg1;
- (void)localUserSetFontColor:(id)arg1;
- (void)localUserSetFont:(id)arg1;
- (void)remoteUserSetBackgroundColor:(id)arg1;
- (void)remoteUserSetFontColor:(id)arg1;
- (void)remoteUserSetFont:(id)arg1;
- (void)personInfoChanged:(id)arg1;
- (void)personPictureChanged:(id)arg1;
- (void)fileTransferUpdated:(id)arg1;
- (void)retainFragment:(id)arg1;
- (void)adjustDateFragmentsForTimeChange;
- (void)dateFormatDidChange;
- (void)rebuildChatItem:(id)arg1;
- (void)setLastCommittedChatItem:(id)arg1;
- (id)lastCommittedChatItem;

@end

@interface TranscriptToSuperParserContext : AppKitToSuperParserContext
{
}

- (id)_attributesForAttachmentWithAttributes:(id)arg1;

@end

@interface WebView (FezWebUtil)
- (struct CGRect)clipRect;
- (double)documentHeight;
- (void)handleURLRequest:(id)arg1 fromWebView:(id)arg2 withListener:(id)arg3 ignoringAbout:(BOOL)arg4;
@end

