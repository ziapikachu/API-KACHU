/**
* ZIA API-KACHU (Epitech 2018)
*/


#ifndef				_IMODULE_H
#define				_IMODULE_H

#include			"IAPIObject.h"
#include			"IHttpRequest.h"

namespace			APIKachu
{
  class				IServer;
  class				IHttpTransaction;

  /**
  * @brief Bitmask representing the steps of processing in which the module will be executed
  * @details See on the documentation's main page for other informations
  */
  enum				eModuleType : uint8
  {
    MODULE_TYPE_NONE		= 0x00,
    MODULE_TYPE_CONNECTION	= 0x01,
    MODULE_TYPE_ON_READ		= 0x02,
    MODULE_TYPE_INIT		= 0x04,
    MODULE_TYPE_PARSING		= 0x08,
    MODULE_TYPE_PROCESS		= 0x10,
    MODULE_TYPE_POST_PROCESS	= 0x20,
    MODULE_TYPE_ON_WRITE	= 0x40,
    MODULE_TYPE_END		= 0x80,
    MODULE_TYPE_ALL		= 0xFF
  };

  /**
  * @brief Flags specifying how the return type of exec will be used
  * @details None = the return type will have no impact on the request
  * Required = if the return type is false, send the response and stop processing further
  * Sufficient = if the return type is true, check other required modules and send the response
  * Required | Sufficient = if the return type is true, send the response and stop processing further
  * @param uint16 status
  */
  enum				eModuleFlags : uint8
  {
    MODULE_FLAGS_NONE		= 0x00,
    MODULE_FLAGS_REQUIRED	= 0x01,
    MODULE_FLAGS_SUFFICIENT	= 0x02	
  };

  /**
  * @brief Base interface for a module
  * @details Implements the basic methods to be used by the server
  */
  class				IModule : public virtual IAPIObject
  {
    public: 
      IModule() = default;
      virtual ~IModule() = default;
      /**
      * @brief Method to be used by the server on each HTTP query received
      * @details Edits the IHttpTransaction and returns true on success and false on failure
      * If the module has the required flag, it must set the response to an appropriate error status code on failure 
      * @param IHttpTransaction * - the transaction on which the module will apply
      */
      virtual bool		exec(IHttpTransaction *) = 0;
    
      /**
       * @brief Method to be used when the server is started
       * @details Return true on success, false on failure
       * @param IServer *
       */
      virtual bool		init(IServer *) = 0;
	  
      /**
      * @brief Getter for the module's type
      * @details Specifies as a bitmask the possible steps of execution for the module
      * See documentation for eModuleType
      */
      virtual uint8		getModuleType() const = 0;
      

      /**
      * @brief Getter for the module's flags
      * @details See documentation for eModuleFlags
      */
      virtual uint8		getModuleFlags() const = 0;
      

      /**
      * @brief Getter for the module's handled methods
      * @details Specifies as a bitmask the methods on which the module will be executed
      * @details See documentation for eHttpMethod 
      */
      virtual uint8		getHandledMethods() const = 0;
  };
}

extern "C"
{
  /*
  * @brief Module creator function to be called by the server when loading it
  * @details Returns a pointer to the module created
  * @details This should be used with dlsym and other similar functions
  */
  APIKachu::IModule		*getModule();
}

#endif				//_IMODULE_H