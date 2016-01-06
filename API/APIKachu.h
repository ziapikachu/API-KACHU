#ifndef			_APIKachu_H_
# define		_APIKachu_H_

# include		<stdint.h>

/*! \mainpage APIKachu
* 
* Welcome to APIKachu's documentation. You can find a list of classes and their methods in the toolbar above.
* 
* To create a module, you have to implement the IModule interface and its methods accordingly. You'll find more details in the documentation of the class.
* 
* First of all, when the server receives a new connection, it should create an instance of IHttpClient containing the IP address of the client as an IIPAddress. This is to be used later on by the modules if needed.
* Note that all enabled modules with the MODULE_TYPE_CONNECTION type set will be called at that time. You can for example set up an SSL connection here within a module.
* 
* When the server receives a request from a known client, it has to create an IHttpTransaction containing the client sending it, and set its ByteBuffer to the content of the received packet. This is when modules with MODULE_TYPE_ON_READ will be executed.
* At this point, the server should create the IHttpRequest, set it in the IHttpTransaction object, and pass this to modules with MODULE_TYPE_INIT.
* The next step is parsing the headers ; this should be done by one of the modules with MODULE_TYPE_PARSING set.
* After this, the server has to create the IHttpResponse, and set it in the IHttpTransaction object : this is when the content of the response will get filled, with the MODULE_TYPE_PROCESS modules. You have to create a module retrieving the content of the file there and fill the ByteBuffer within the IHttpResponse.
* Modules with their type set to MODULE_TYPE_POST_PROCESS will get executed right after.
* The response is almost ready to be sent by then ; modules with MODULE_TYPE_ON_WRITE will be executed, and then the server can send the response.
* Lastly, after the response is sent, modules with MODULE_TYPE_END sent will be executed on the transaction, potentially doing last actions.
* 
* The execution routine of the modules returns a boolean, whose behaviour changes with the module's eModuleFlags.
* A flag of MODULE_FLAGS_NONE specifies that the return value should be ignored, and have no impact on the execution of other modules.
* The MODULE_FLAGS_REQUIRED flag specifies that if the return value is false, the execution of modules should be stopped and the response sent directly (the module has to set the appropriate error code).
* If the MODULE_FLAGS_SUFFICIENT is set, a return value of true specifies that only other modules with MODULE_FLAG_REQUIRED should be executed before sending the response.
* Last, if both of those are set, a return value of true means that the execution of other modules should be stopped and the request sent directly.
* Please note that in each of those cases, the modules of type MODULE_TYPE_ON_WRITE and MODULE_TYPE_END should still be executed.
*/

typedef uint64_t	uint64;
typedef uint32_t	uint32;
typedef uint16_t	uint16;
typedef uint8_t		uint8;
typedef int64_t		int64;
typedef int32_t		int32;
typedef int16_t		int16;
typedef int8_t		int8;

# ifdef			_WIN32
// Disabling "inheritance by dominance" on visual studio
#  pragma		warning(disable : 4250)
# endif

#endif
