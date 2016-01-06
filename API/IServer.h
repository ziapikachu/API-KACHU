/**
* ZIA API-KACHU (Epitech 2018)
*/


#ifndef				_ISERVER_H
#define				_ISERVER_H

#include			"IAPIObject.h"

namespace			APIKachu
{
  class				IConfig;
  class				Logger;

  /**
  * @brief Base interface for the server
  * @details Implements the basic methods used by the modules
  */
  class				IServer: public virtual IAPIObject
  {
    public:
      IServer() = default;
      virtual ~IServer() = default;

      /**
      * @brief Getter for the configuration of the server
      */
      virtual const IConfig	&getConfig() const = 0;
      
      /**
      * @brief Getter for the logger of the server
      */
      virtual Logger		&getLogger() = 0;
  };
}

#endif //_ISERVER_H