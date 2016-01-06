/**
* ZIA API-KACHU (Epitech 2018)
*/

#ifndef				_IHTTPCLIENT_H
#define				_IHTTPCLIENT_H

#include			<cstdlib>

#include			"IAPIObject.h"

namespace			APIKachu
{
  class				IHttpResponse;
  class				IIPAddress;

  /**
  * @brief Base interface for a client sending a request
  */
  class				IHttpClient : public virtual IAPIObject
  {
    public:
      IHttpClient() = default;
      virtual ~IHttpClient() = default;

      /**
      * @brief Sends a response to the client
      * @details Returns -1 on error or the number of bytes sent
      * @param const IHttpResponse &response - the response to be sent
      */
      virtual size_t		send(const IHttpResponse &response) = 0;

      /**
      * @brief Getter for the IP address
      */
      virtual const IIPAddress	&getIPAddress() const = 0;
  };
}

#endif //_IHTTPCLIENT_H
