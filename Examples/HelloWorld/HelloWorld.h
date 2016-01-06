#ifndef			HELLOWORLD_H_
#define			HELLOWORLD_H_

#include		"../../API/IModule.h"

/*
  This is the parent class of every class within the implementation of the API.
*/
class			HelloObject : virtual public APIKachu::IAPIObject
{
  public:
    HelloObject();
    virtual ~HelloObject() = default;

    uint32		getAPIMagic() const;
    uint32		getAPIVersion() const;
};

/*
  Basic implementation of a module.
  Basically the goal here is to display "hello world" within the processing step of execution.
*/
class			HelloWorld : public APIKachu::IModule, public HelloObject
{
  public:
    HelloWorld();
    ~HelloWorld() = default;

    /*
      This function will be called by the server when processing an http request (see documentation for APIKachu::IHttpRequest)
      We want the displaying to happen here.
    */
    bool		exec(APIKachu::IHttpTransaction *transaction);

    /*
      The starting routine that will get executed by the server when the module is loaded.
      We are stocking the server in that function to be able to access to its logger in the exec function.
    */
    bool		init(APIKachu::IServer *server);

    /*
      Returns the step of execution where the module will be used (see documentation for APIKachu::IModule::getModuleType())
      Our module doesn't do anything, so we could execute it anywhere in the execution chain.
    */
    uint8		getModuleType() const;

    /*
      Returns how the return value of the exec function will be interpreted (see documentation for APIKachu::IModule::getModuleFlags())
      As our module is just for testing, we can set this to APIKachu::MODULE_FLAGS_NONE to completely ignore the return type.
    */
    uint8		getModuleFlags() const;

    /*
      Returns the methods that the module can handle. (see documentation for APIKachu::IModule::getHandledMethods())
      We can set this to APIKachu::METHOD_ALL for testing.
    */
    uint8		getHandledMethods() const;
		
  private:
    APIKachu::IServer	*m_server;
};

#endif

