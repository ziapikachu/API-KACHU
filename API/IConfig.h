/**
* ZIA API-KACHU (Epitech 2018)
*/

#ifndef					_ICONFIG_H
#define					_ICONFIG_H

#include				<string>

#include				"IAPIObject.h"

namespace				APIKachu
{
  class					IConfigValue;

  /**
  * @brief Base interface for the configuration of the server
  */
  class					IConfig : public virtual IAPIObject
  {
    public:
      IConfig() = default;
      virtual ~IConfig() = default;

      /**
      * @brief Loads the configuration file
      * @details Returns true if the loading has succeeded
      * @param std::string path
      */
      virtual bool			load(const std::string &path) = 0;

      /**
      * @brief Checks the existence of a value in the configuration file
      * @details Returns true if the value exists
      * @param std::string key
      */
      virtual bool			hasValue(const std::string &key) = 0;

      /**
      * @brief Retrieves a value from the configuration file
      * @details Users should always check if the value exists beforehand ; behaviour is undefined otherwise
      * @param std::string key
      */
      virtual const IConfigValue	&getValue(const std::string &key) = 0;
  };
}

#endif					// _ICONFIG_H