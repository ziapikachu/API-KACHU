/**
* ZIA API-KACHU (Epitech 2018)
*/


#ifndef				_IHTTPQUERY_H
#define				_IHTTPQUERY_H

#include			<map>
#include			<string>
#include			<vector>

#include			"IAPIObject.h"

namespace			APIKachu
{
  /**
  * @brief Container for a raw byte array
  */
  struct			ByteBuffer
  {
    char			*data;
    uint32			size;
  };

  /**
  * @brief Base class for an HTTP query
  * @details Inherited by IHttpResponse and IHttpRequest
  */
  class				IHttpQuery : public virtual IAPIObject
  {
    public:
      IHttpQuery() = default;
      virtual ~IHttpQuery() = default;

      /**
      * @brief Associative container for http headers 
      * @details Key and values are strings
      */
      typedef std::map<std::string, std::string>	tHeaders;

      /**
      * @brief Getter for the http headers
      * @details See documentation for tHeaders
      */
      virtual const tHeaders	&getHeaders() const = 0;

      /**
      * @brief Getter for the content of the query
      * @details See documentation for ByteBuffer
      */
      virtual const ByteBuffer	&getByteBuffer() const = 0;

      /**
      * @brief Getter for the content of the query
      * @details See documentation for ByteBuffer
      */
      virtual ByteBuffer	&getByteBuffer() = 0;
      
      /**
      * @brief Getter for the http version of the query
      */
      virtual const std::string	&getHTTPVersion() const = 0;
  };
}

#endif				//_IHTTPQUERY_H
