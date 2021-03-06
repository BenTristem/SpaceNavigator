/*	NSXMLDTDNode.h
	Copyright (c) 2004-2014, Apple Inc. All rights reserved.
*/

#import <Foundation/NSXMLNode.h>


/*!
    @typedef NSXMLDTDNodeKind
	@abstract The subkind of a DTD node kind.
*/
typedef NS_ENUM(NSUInteger, NSXMLDTDNodeKind) {
	NSXMLEntityGeneralKind = 1,
	NSXMLEntityParsedKind,
	NSXMLEntityUnparsedKind,
	NSXMLEntityParameterKind,
	NSXMLEntityPredefined,

	NSXMLAttributeCDATAKind,
	NSXMLAttributeIDKind,
	NSXMLAttributeIDRefKind,
	NSXMLAttributeIDRefsKind,
	NSXMLAttributeEntityKind,
	NSXMLAttributeEntitiesKind,
	NSXMLAttributeNMTokenKind,
	NSXMLAttributeNMTokensKind,
	NSXMLAttributeEnumerationKind,
	NSXMLAttributeNotationKind,

	NSXMLElementDeclarationUndefinedKind,
	NSXMLElementDeclarationEmptyKind,
	NSXMLElementDeclarationAnyKind,
	NSXMLElementDeclarationMixedKind,
	NSXMLElementDeclarationElementKind
};

/*!
    @class NSXMLDTDNode
    @abstract The nodes that are exclusive to a DTD
	@discussion Every DTD node has a name. Object value is defined as follows:<ul>
		<li><b>Entity declaration</b> - the string that that entity resolves to eg "&lt;"</li>
		<li><b>Attribute declaration</b> - the default value, if any</li>
		<li><b>Element declaration</b> - the validation string</li>
		<li><b>Notation declaration</b> - no objectValue</li></ul>
*/
@interface NSXMLDTDNode : NSXMLNode {
@protected
	NSXMLDTDNodeKind _DTDKind;
	NSString *_name;
	NSString *_notationName;
	NSString *_publicID;
	NSString *_systemID;
}

/*!
    @method initWithXMLString:
    @abstract Returns an element, attribute, entity, or notation DTD node based on the full XML string.
*/
- (instancetype)initWithXMLString:(NSString *)string NS_DESIGNATED_INITIALIZER; //primitive

- (instancetype)initWithKind:(NSXMLNodeKind)kind options:(NSUInteger)options NS_DESIGNATED_INITIALIZER; //primitive

- (instancetype)init NS_DESIGNATED_INITIALIZER;

/*!
    @method DTDKind
    @abstract Sets the DTD sub kind.
*/
@property NSXMLDTDNodeKind DTDKind; //primitive

/*!
    @method isExternal
    @abstract True if the system id is set. Valid for entities and notations.
*/
@property (readonly, getter=isExternal) BOOL external; //primitive

/*!
    @method publicID
    @abstract Sets the public id. This identifier should be in the default catalog in /etc/xml/catalog or in a path specified by the environment variable XML_CATALOG_FILES. When the public id is set the system id must also be set. Valid for entities and notations.
*/
@property (copy) NSString *publicID; //primitive

/*!
    @method systemID
    @abstract Sets the system id. This should be a URL that points to a valid DTD. Valid for entities and notations.
*/
@property (copy) NSString *systemID; //primitive

/*!
    @method notationName
    @abstract Set the notation name. Valid for entities only.
*/
@property (copy) NSString *notationName; //primitive

@end

