// Copyright (c) 2011,2013 Jonathan Hersh, Simon Fell
//
// Permission is hereby granted, free of charge, to any person obtaining a 
// copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation
// the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the 
// Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included 
// in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS 
// OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, 
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN 
// THE SOFTWARE.
//

#import "zkSforceClient+Operations.h"

@interface ZKSforceClient (zkAsyncQuery)

typedef void (^zkCompleteUserInfoBlock)                      (ZKUserInfo *result);
typedef void (^zkCompleteSetPasswordResultBlock)             (ZKSetPasswordResult *result);
typedef void (^zkCompleteResetPasswordResultBlock)           (ZKResetPasswordResult *result);
typedef void (^zkCompleteQueryResultBlock)                   (ZKQueryResult *result);
typedef void (^zkCompleteLoginResultBlock)                   (ZKLoginResult *result);
typedef void (^zkCompleteGetUpdatedResultBlock)              (ZKGetUpdatedResult *result);
typedef void (^zkCompleteGetServerTimestampResultBlock)      (ZKGetServerTimestampResult *result);
typedef void (^zkCompleteGetDeletedResultBlock)              (ZKGetDeletedResult *result);
typedef void (^zkCompleteDescribeThemeResultBlock)           (ZKDescribeThemeResult *result);
typedef void (^zkCompleteDescribeSoftphoneLayoutResultBlock) (ZKDescribeSoftphoneLayoutResult *result);
typedef void (^zkCompleteDescribeSObjectBlock)               (ZKDescribeSObject *result);
typedef void (^zkCompleteDescribeLayoutResultBlock)          (ZKDescribeLayoutResult *result);
typedef void (^zkCompleteDescribeGlobalThemeBlock)           (ZKDescribeGlobalTheme *result);
typedef void (^zkCompleteDescribeCompactLayoutsResultBlock)  (ZKDescribeCompactLayoutsResult *result);
typedef void (^zkCompleteDescribeAppMenuResultBlock)         (ZKDescribeAppMenuResult *result);
typedef void (^zkCompleteDictionaryBlock)                    (NSDictionary *result);
typedef void (^zkCompleteArrayBlock)                         (NSArray *result);
typedef void (^zkFailWithExceptionBlock)                     (NSException *result);
typedef void (^zkCompleteVoidBlock)                          (void);

// Login to the Salesforce.com SOAP Api
-(void) performLogin:(NSString *)username password:(NSString *)password
           failBlock:(zkFailWithExceptionBlock)failBlock
       completeBlock:(zkCompleteLoginResultBlock)completeBlock;

// Describe an sObject
-(void) performDescribeSObject:(NSString *)sObjectType
                     failBlock:(zkFailWithExceptionBlock)failBlock
                 completeBlock:(zkCompleteDescribeSObjectBlock)completeBlock;

// Describe a number sObjects
-(void) performDescribeSObjects:(NSArray *)sObjectType
                      failBlock:(zkFailWithExceptionBlock)failBlock
                  completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe the Global state
-(void) performDescribeGlobalWithFailBlock:(zkFailWithExceptionBlock)failBlock
                completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe all the data category groups available for a given set of types
-(void) performDescribeDataCategoryGroups:(NSArray *)sObjectType
                                failBlock:(zkFailWithExceptionBlock)failBlock
                            completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe the data category group structures for a given set of pair of types and data category group name
-(void) performDescribeDataCategoryGroupStructures:(NSArray *)pairs topCategoriesOnly:(BOOL)topCategoriesOnly
                                         failBlock:(zkFailWithExceptionBlock)failBlock
                                     completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe a list of FlexiPage and their contents
-(void) performDescribeFlexiPages:(NSArray *)flexiPages
                        failBlock:(zkFailWithExceptionBlock)failBlock
                    completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe the items in an AppMenu
-(void) performDescribeAppMenu:(NSString *)appMenuType
                     failBlock:(zkFailWithExceptionBlock)failBlock
                 completeBlock:(zkCompleteDescribeAppMenuResultBlock)completeBlock;

// Describe Gloal and Themes
-(void) performDescribeGlobalThemeWithFailBlock:(zkFailWithExceptionBlock)failBlock
                     completeBlock:(zkCompleteDescribeGlobalThemeBlock)completeBlock;

// Describe Themes
-(void) performDescribeTheme:(NSArray *)sobjectType
                   failBlock:(zkFailWithExceptionBlock)failBlock
               completeBlock:(zkCompleteDescribeThemeResultBlock)completeBlock;

// Describe the layout of the given sObject or the given actionable global page.
-(void) performDescribeLayout:(NSString *)sObjectType recordTypeIds:(NSArray *)recordTypeIds
                    failBlock:(zkFailWithExceptionBlock)failBlock
                completeBlock:(zkCompleteDescribeLayoutResultBlock)completeBlock;

// Describe the layout of the SoftPhone
-(void) performDescribeSoftphoneLayoutWithFailBlock:(zkFailWithExceptionBlock)failBlock
                         completeBlock:(zkCompleteDescribeSoftphoneLayoutResultBlock)completeBlock;

// Describe the search view of an sObject
-(void) performDescribeSearchLayouts:(NSArray *)sObjectType
                           failBlock:(zkFailWithExceptionBlock)failBlock
                       completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe a list of objects representing the order and scope of objects on a users search result page
-(void) performDescribeSearchScopeOrderWithFailBlock:(zkFailWithExceptionBlock)failBlock
                          completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe the compact layouts of the given sObject
-(void) performDescribeCompactLayouts:(NSString *)sObjectType recordTypeIds:(NSArray *)recordTypeIds
                            failBlock:(zkFailWithExceptionBlock)failBlock
                        completeBlock:(zkCompleteDescribeCompactLayoutsResultBlock)completeBlock;

// Describe the tabs that appear on a users page
-(void) performDescribeTabsWithFailBlock:(zkFailWithExceptionBlock)failBlock
              completeBlock:(zkCompleteArrayBlock)completeBlock;

// Create a set of new sObjects
-(void) performCreate:(NSArray *)sObjects
            failBlock:(zkFailWithExceptionBlock)failBlock
        completeBlock:(zkCompleteArrayBlock)completeBlock;

// Update a set of sObjects
-(void) performUpdate:(NSArray *)sObjects
            failBlock:(zkFailWithExceptionBlock)failBlock
        completeBlock:(zkCompleteArrayBlock)completeBlock;

// Update or insert a set of sObjects based on object id
-(void) performUpsert:(NSString *)externalIDFieldName sObjects:(NSArray *)sObjects
            failBlock:(zkFailWithExceptionBlock)failBlock
        completeBlock:(zkCompleteArrayBlock)completeBlock;

// Merge and update a set of sObjects based on object id
-(void) performMerge:(NSArray *)request
           failBlock:(zkFailWithExceptionBlock)failBlock
       completeBlock:(zkCompleteArrayBlock)completeBlock;

// Delete a set of sObjects
-(void) performDelete:(NSArray *)ids
            failBlock:(zkFailWithExceptionBlock)failBlock
        completeBlock:(zkCompleteArrayBlock)completeBlock;

// Undelete a set of sObjects
-(void) performUndelete:(NSArray *)ids
              failBlock:(zkFailWithExceptionBlock)failBlock
          completeBlock:(zkCompleteArrayBlock)completeBlock;

// Empty a set of sObjects from the recycle bin
-(void) performEmptyRecycleBin:(NSArray *)ids
                     failBlock:(zkFailWithExceptionBlock)failBlock
                 completeBlock:(zkCompleteArrayBlock)completeBlock;

// Get a set of sObjects
-(void) performRetrieve:(NSString *)fieldList sObjectType:(NSString *)sObjectType ids:(NSArray *)ids
              failBlock:(zkFailWithExceptionBlock)failBlock
          completeBlock:(zkCompleteDictionaryBlock)completeBlock;

// Submit an entity to a workflow process or process a workitem
-(void) performProcess:(NSArray *)actions
             failBlock:(zkFailWithExceptionBlock)failBlock
         completeBlock:(zkCompleteArrayBlock)completeBlock;

// convert a set of leads
-(void) performConvertLead:(NSArray *)leadConverts
                 failBlock:(zkFailWithExceptionBlock)failBlock
             completeBlock:(zkCompleteArrayBlock)completeBlock;

// Logout the current user, invalidating the current session.
-(void) performLogoutWithFailBlock:(zkFailWithExceptionBlock)failBlock
        completeBlock:(zkCompleteVoidBlock)completeBlock;

// Logs out and invalidates session ids
-(void) performInvalidateSessions:(NSArray *)sessionIds
                        failBlock:(zkFailWithExceptionBlock)failBlock
                    completeBlock:(zkCompleteArrayBlock)completeBlock;

// Get the IDs for deleted sObjects
-(void) performGetDeleted:(NSString *)sObjectType startDate:(NSDate *)startDate endDate:(NSDate *)endDate
                failBlock:(zkFailWithExceptionBlock)failBlock
            completeBlock:(zkCompleteGetDeletedResultBlock)completeBlock;

// Get the IDs for updated sObjects
-(void) performGetUpdated:(NSString *)sObjectType startDate:(NSDate *)startDate endDate:(NSDate *)endDate
                failBlock:(zkFailWithExceptionBlock)failBlock
            completeBlock:(zkCompleteGetUpdatedResultBlock)completeBlock;

// Create a Query Cursor
-(void) performQuery:(NSString *)queryString
           failBlock:(zkFailWithExceptionBlock)failBlock
       completeBlock:(zkCompleteQueryResultBlock)completeBlock;

// Create a Query Cursor, including deleted sObjects
-(void) performQueryAll:(NSString *)queryString
              failBlock:(zkFailWithExceptionBlock)failBlock
          completeBlock:(zkCompleteQueryResultBlock)completeBlock;

// Gets the next batch of sObjects from a query
-(void) performQueryMore:(NSString *)queryLocator
               failBlock:(zkFailWithExceptionBlock)failBlock
           completeBlock:(zkCompleteQueryResultBlock)completeBlock;

// Search for sObjects
-(void) performSearch:(NSString *)searchString
            failBlock:(zkFailWithExceptionBlock)failBlock
        completeBlock:(zkCompleteArrayBlock)completeBlock;

// Gets server timestamp
-(void) performGetServerTimestampWithFailBlock:(zkFailWithExceptionBlock)failBlock
                    completeBlock:(zkCompleteGetServerTimestampResultBlock)completeBlock;

// Set a user's password
-(void) performSetPassword:(NSString *)userId password:(NSString *)password
                 failBlock:(zkFailWithExceptionBlock)failBlock
             completeBlock:(zkCompleteSetPasswordResultBlock)completeBlock;

// Reset a user's password
-(void) performResetPassword:(NSString *)userId
                   failBlock:(zkFailWithExceptionBlock)failBlock
               completeBlock:(zkCompleteResetPasswordResultBlock)completeBlock;

// Returns standard information relevant to the current user
-(void) performGetUserInfoWithFailBlock:(zkFailWithExceptionBlock)failBlock
             completeBlock:(zkCompleteUserInfoBlock)completeBlock;

// Send existing draft EmailMessage
-(void) performSendEmailMessage:(NSArray *)ids
                      failBlock:(zkFailWithExceptionBlock)failBlock
                  completeBlock:(zkCompleteArrayBlock)completeBlock;

// Send outbound email
-(void) performSendEmail:(NSArray *)messages
               failBlock:(zkFailWithExceptionBlock)failBlock
           completeBlock:(zkCompleteArrayBlock)completeBlock;

// Perform a series of predefined actions such as quick create or log a task
-(void) performPerformQuickActions:(NSArray *)quickActions
                         failBlock:(zkFailWithExceptionBlock)failBlock
                     completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe the details of a series of quick actions
-(void) performDescribeQuickActions:(NSArray *)quickActions
                          failBlock:(zkFailWithExceptionBlock)failBlock
                      completeBlock:(zkCompleteArrayBlock)completeBlock;

// Describe the details of a series of quick actions available for the given contextType
-(void) performDescribeAvailableQuickActions:(NSString *)contextType
                                   failBlock:(zkFailWithExceptionBlock)failBlock
                               completeBlock:(zkCompleteArrayBlock)completeBlock;

@end
