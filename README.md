RDServerHandler
===============

This is a useful library for iOS to call web services in both synchronous and asynchronous way.

Steps to use my library for calling web services -

Step 1: Add folder in your project RDServerHandlerLib.

Step 2: Add Library search path as below from Xcode Project Build Settings tab -

        $(SRCROOT)/YOUR_PROJECT_NAME/RDServerHandlerLib

Step 3: Import library in a class wherever you want to call a web service.
- #import "RDServerHandler.h"

Step 4: Add below lines of code to call a service the same class.

    NSString *stringURL = @"http:YOUR_WEBSERVICE_URL";
    NSString *stringContentType = @"application/json";  // Any content Type value
    NSString *stringMethodType = @"GET"; // GET/POST/PUT
    NSString *stringBody= @"";
    
    // Call a service with params mentioned in method call
    [[RDServerHandler sharedHandler] callServiceWithURL:[NSURL URLWithString:stringURL]
                                            contentType:stringContentType
                                          andBodyString:stringBody
                                             withMethod:stringMethodType
                                          isSynchronous:YES
                                               username:@""
                                               password:@""];
    // Catch a response for above called service
    [RDServerHandler sharedHandler].serverHandlerBlock = ^(NSString * responseString, NSDictionary *responseDictionary, NSError *error)
    {
        @try
        {
            dispatch_async(dispatch_get_main_queue(), ^
               {
                   if (error==nil || error == NULL)
                   {
                   }
               });
        }
        @catch (NSException *exception) {
            
        }
    };


/***********************************************************************************************************************/

And that's it.

You are ready to go.


