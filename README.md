# zkSforce README

zkSforce is a cocoa library for calling the Salesforce.com Web Services APIs, easily integrate Salesforce into your OSX and iPhone projects. (supports OSX 10.5 and up, and iOS 3.2 and up)

zkSforce supports all the common methods in the partner web services API
 * login
 * describeGlobal, describeSObject, describeLayout
 * create, update, delete
 * search, query, queryAll

The following methods are not currently supported
 * describeSObjects
 * upsert, merge, convertLead
 * getDeleted & getUpdated
 * process

In general the client acts just like the Web Services API, however in a few places it has some smarts to make your life easier.
 * it'll track the duration of the session and re-login as required, so just keep calling methods as needed and don't worry about the session expiring away from under you.
 * in ZKDescribeSObject there's a helper method to get the ZKDescribeField given the fields name.
 * In ZKSObject the fieldsToNull collection is managed for you, if you add a field to the fieldsToNull collection (via setFieldToNull) it'll automatically remove any field value, also you can just set the field value directly to nil (aka null) in setFieldValue:field: and it'll automatically translate that into a fieldsToNull call for you.
 * ZKQueryResult implements the NSTableView informal data source interface, so you can easily show a queries results in a table view (just like SoqlX does)
 * You can ask the ZKSforceClient object to automatically cache describe results for you by calling setCacheDescribes


Usage is really straight forward, create an instance of the ZKSforceClient class, call login, then call the other operations as needed, e.g.

        // Login and find the URL to the new Task UI Page.
        ZKSforceClient *sforce = [[ZKSforceClient alloc] init];
        [sforce login:username password:password];
        ZKDescribeSObject *taskDescribe = [sforce describeSObject:@"Task"];
        NSLog(@"url for the new Task page is %@", [taskDescribe urlNew]);	
        [sforce release];


        // Login and create a new contact for Simon Fell, and check the result
        ZKSforceClient *sforce = [[ZKSforceClient alloc] init];
        [sforce login:username password:password];
        ZKSObject *contact = [ZKSObject withType:@"Contact"];
        [contact setFieldValue:@"Fell" field:@"LastName"];
        [contact setFieldValue:@"Simon" field:@"FirstName"];
        NSArray *results = [sforce create:[NSArray arrayWithObject:contact]];
        ZKSaveResult *sr = [results objectAtIndex:0];
        if ([sr success])
	    NSLog(@"new contact id %@", [sr id]);
        else
	    NSLog(@"error creating contact %@ %@", [sr statusCode], [sr message]);
        [sforce release];


## Project setup

In order to support usage on both OSX & iPhone OS (so iPhone, iPod Touch, iPad), the library now uses libxml as its XML parser rather than NSXML, which isn't fully implemented on iPhone OS. Once you've added all the .h & .m files to your project, you'll need to goto the build settings and add /usr/include/libxml2 to the Header Search Paths, and add libxml2.dylib to the linked frameworks section, and then you should be good to go.