/**
* ZIA API-KACHU (Epitech 2016)
*/

#ifndef				_IHTTPREQUEST_H
#define				_IHTTPREQUEST_H

#include			<string>

#include			"IHttpQuery.h"

namespace			APIKachu
{
  /**
  * @brief Different methods possible for a request
  * @details Used as a bitmask for modules (see documentation for IModule::getHandledMethods())
  */
  enum 				eHttpMethod : uint8
  {
    METHOD_UNKNOWN		= 0x00,
    METHOD_GET			= 0x01,
    METHOD_POST			= 0x02,
    METHOD_HEAD			= 0x04,
    METHOD_CONNECT		= 0x08,
    METHOD_TRACE		= 0x10,
    METHOD_PUT			= 0x20,
    METHOD_PATCH		= 0x40,
    METHOD_DELETE		= 0x80,
    METHOD_ALL			= 0xFF
  };

  /**
  * @brief Contains a request sent by a client
  * @details Inherits IHttpQuery
  */
  class				IHttpRequest : public virtual IHttpQuery
  {
    public:
      IHttpRequest();
      virtual ~IHttpRequest();

      /**
      * @brief Getter for the http method of the request
      * @details See documentation for eHttpMethod
      */
      virtual eHttpMethod	getMethod() const = 0;
	  
      /**
      * @brief Getter for the URN of the request
      */
      virtual const std::string	&getURN() const = 0;
  };
}

#endif				//_IHTTPREQUEST_H