//
//  ViewController.m
//  ServerCallDemoUsingStaticLib
//
//  Created by Ravi Deshmukh on 21/05/14.
//  Copyright (c) 2014 myiOSCode. All rights reserved.
//

#import "ViewController.h"
#import "RDServerHandler.h"

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    
    NSString *stringURL = @"http://yourprojectwebserviceURL";
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
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
