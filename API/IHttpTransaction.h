#ifndef					IHTTPTRANSACTION_H_
#define					IHTTPTRANSACTION_H_

#include				"IAPIObject.h"

namespace				APIKachu
{
  class					IHttpClient;
  class					IHttpRequest;
  class					IHttpResponse;
  struct				ByteBuffer;
  
  /**
  * @brief Class containing informations about an HTTP transaction
  * @details Defines the request, the client sending it, and the response built by the server
  */
  class					IHttpTransaction : public virtual IAPIObject
  {
    public:
      IHttpTransaction() = default;
      virtual ~IHttpTransaction() = default;

      /**
       * @brief Setter for the http request
       * @details Should be used by the first module when parsing the request
       * @param IHttpRequest *request
       */
      virtual void			setHttpRequest(IHttpRequest *request) = 0;

      /**
       * @brief Setter for the http response
       * @details Should be used by the first module when building the response
       * @param IHttpResponse *response
       */
      virtual void			setHttpResponse(IHttpResponse *response) = 0;
      
      /**
       * @brief Getter for the client sending the request
       * @details This should be set by the server upon receiving a packet
       */
      virtual IHttpClient		*getHttpClient() = 0;

      /**
       * @brief Getter for the http request of the transaction
       * @details Returns nullptr if the request has not been parsed yet
       */
      virtual IHttpRequest		*getHttpRequest() = 0;

      /**
       * @brief Getter for the http response of the transaction
       * @details Returns nullptr if the response has not been built yet
       */
      virtual IHttpResponse		*getHttpResponse() = 0;

      /**
       * @brief Getter for the raw data of the received packet
       * @details Should be set by the server upon receiving a packet
       * @details See documentation for ByteBuffer
       */
      virtual const ByteBuffer		&getRawRequest() = 0;
  };
}

#endif