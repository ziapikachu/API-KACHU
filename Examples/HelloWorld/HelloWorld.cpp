#include		"../../sources/IServer.h"
#include		"../../sources/Logger.h"

#include		"HelloWorld.h"

HelloObject::HelloObject() :
  APIKachu::IAPIObject()
{
}

uint32			HelloObject::getAPIMagic() const
{
  /*
    Here we return a magic number that serves as an identifier for our implementation.
    This way we can know where a given module comes from and adapt our behaviour to it.
    You should use a unique number that is very unlikely to be used by anyone else here.
  */
  return (0x78447844);
}

uint32			HelloObject::getAPIVersion() const
{
  /*
    This serves as the version of the implementation.
    It allows us to know which version of a given api a module comes from, completing the magic number.
  */
  return (0);
}

/* ---- */

HelloWorld::HelloWorld() :
  HelloObject(),
  APIKachu::IModule()
{
}

bool			HelloWorld::exec(APIKachu::IHttpTransaction *transaction)
{
  /*
    We stocked the server as this->m_server, so we can use its getLogger() function to retrieve the logger.
    Then, outBasic serves as a printf function for a basic message (see documentation for APIKachu::Logger).
  */
  m_server->getLogger().outBasic("%s\n", "Hello world!");
  return (true);
}

bool			HelloWorld::init(APIKachu::IServer *server)
{
  /*
    We're stocking the server here so we can use it in the exec function later on.
  */
  m_server = server;
  return (true);
}

uint8			HelloWorld::getModuleType() const
{
  return (APIKachu::MODULE_TYPE_PROCESS);
}

uint8			HelloWorld::getModuleFlags() const
{
  return (APIKachu::MODULE_FLAGS_REQUIRED);
}

uint8			HelloWorld::getHandledMethods() const
{
  return (APIKachu::METHOD_ALL);
}

/*
  This is the function that will get loaded with dlsym() and other similar functions by the server.
*/
APIKachu::IModule	*getModule()
{
  return (new HelloWorld());
}