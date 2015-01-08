//  RDServerHandler.h
//  Created by Ravi Deshmukh
//  Copyright (c) 2014 Ravi Deshmukh. All rights reserved.

#import <Foundation/Foundation.h>

typedef void (^RDServerHandlerBlock)(NSString * ,NSDictionary *, NSError *);

@interface RDServerHandler : NSObject
{
    NSMutableData *_dataReceived;
}

@property (nonatomic, copy) RDServerHandlerBlock serverHandlerBlock;

/**
 *  Shared Instance of RDServerHandler class if all the services needs to be called in Synchronous way.
 *  If there are multiple service calls at a time (may be in background), don't use this shared instance, instead of that, create a separate instance of this class for every service call to invoke a service.
 */
+ (RDServerHandler *)sharedHandler ;

/**
 *  allows to call web service using synchronous and asynchronous way. This method resposnds to success and failure callbacks which will be intimating sending controller after every resposne received. Pass username and password if authentication needs to be passed for any specific service.
 *
 *  @param url               URL for API to be called
 *  @param strContentType    Content-Type
 *  @param strBody           body string in case any .(depending on type of web service call)
 *  @param methodType        Type of Method - GET, POST, PUT etc (In object forms like NSDictionary/NSArray).
 *  @param isSynchronous     is Request Synchronous/ Asynchronous.
 *  @param strUsername       username for authentication
 *  @param strPassword       password for authentication
 */

- (void)callServiceWithURL:(NSURL *)url contentType:(NSString *)strContentType andBodyString:(NSString *)strBody withMethod:(NSString *)methodType isSynchronous:(BOOL)isSynchronous username:(NSString *)strUsername password:(NSString *)strPassword;

/**
 *  allows to call web service using synchronous and asynchronous way. This method resposnds to success and failure callbacks which will be intimating sending controller after every resposne received. Pass username and password if authentication needs to be passed for any specific service.
 *
 *  @param url               URL for API to be called
 *  @param strContentType    Content-Type
 *  @param strBody           body string in case any .(depending on type of web service call)
 *  @param methodType        Type of Method - GET, POST, PUT etc (In object forms like NSDictionary/NSArray).
 *  @param isSynchronous     is Request Synchronous/ Asynchronous.
 *  @param authorizationHeader It will be passed as a flag with access token for Bearer e.g. "xxxxxxxxxxxxxxxxx"
 */

- (void)callServiceWithURL:(NSURL *)url contentType:(NSString *)strContentType andBodyString:(NSString *)strBody withMethod:(NSString *)methodType isSynchronous:(BOOL)isSynchronous authorizationHeader:(NSString *)authorizationHeader ;

/**
 *  allows to call web service using synchronous and asynchronous way. This method resposnds to success and failure callbacks which will be intimating sending controller after every resposne received. Pass username and password if authentication needs to be passed for any specific service.
 *
 *  @param url               URL for API to be called
 *  @param strContentType    Content-Type
 *  @param strBody           body string in case any .(depending on type of web service call)
 *  @param methodType        Type of Method - GET, POST, PUT etc (In object forms like NSDictionary/NSArray).
 *  @param isSynchronous     is Request Synchronous/ Asynchronous.
 *  @param headersDictionary It will be dictionary with Key Value pairs for all header to be passed with the request
 */

- (void)callServiceWithURL:(NSURL *)url contentType:(NSString *)strContentType andBodyString:(NSString *)strBody withMethod:(NSString *)methodType isSynchronous:(BOOL)isSynchronous withHeaders:(NSDictionary *)headersDictionary ;

@end