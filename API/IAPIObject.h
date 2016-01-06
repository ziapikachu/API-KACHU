/**
 * ZIA API-KACHU (Epitech 2016)
 */


#ifndef			_IAPIOBJECT_H
#define 		_IAPIOBJECT_H

#include		"APIKachu.h"

namespace		APIKachu
{
  /**
  * @brief Specifies the API from which an object comes
  * @details Interface that covers the entirety of the API 
  */
  class			IAPIObject
  {
    public:
      IAPIObject() = default;
      virtual ~IAPIObject() = default;

      /**
      * @brief The identifier of the API
      * @details This should be a unique magic number that identifies your API so that a module can know which API an object comes from.
      * Note that this actually using this is not required, but you must still put a unique number here.
      */
      virtual uint32	getAPIMagic() const = 0;

      /**
      * @brief The version of the API
      * @details Complements the magic number with a version of that API.
      */
      virtual uint32	getAPIVersion() const = 0;
  };
}

#endif			//_IAPIOBJECT_H