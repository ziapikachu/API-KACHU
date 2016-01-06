/**
* ZIA API-KACHU (Epitech 2016)
*/

#ifndef			_IHTTPRESPONSE_H
#define			_IHTTPRESPONSE_H

#include		"IHttpQuery.h"

namespace		APIKachu
{
  /**
  * @brief Contains a response to be sent to a client
  * @details Inherits IHttpQuery
  */
  class			IHttpResponse : public virtual IHttpQuery
  {
    public:
      IHttpResponse() = default;
      virtual ~IHttpResponse() = default;

      /**
      * @brief Setter for the status code of the response
      * @param uint16 status
      */
      virtual void	setStatus(uint16 status) = 0;

      /**
      * @brief Getter for the status code of the response
      * @return uint16
      */
      virtual uint16	getStatus() const = 0;
  };
}

#endif			//_IHTTPRESPONSE_H