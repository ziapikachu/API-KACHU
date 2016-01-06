/**
* ZIA API-KACHU (Epitech 2018)
*/

#ifndef					_ICONFIGVALUE_H
#define					_ICONFIGVALUE_H

#include				<string>

#include				"IAPIObject.h"

namespace				APIKachu
{
  /**
  * @brief Configuration value
  * @details Contains a value and provides conversions to different types
  */
  class					IConfigValue : public virtual IAPIObject
  {
    public:
      IConfigValue() = default;
      virtual ~IConfigValue() = default;

      virtual int8			asInt8() const = 0;
      virtual int16			asInt16() const = 0;
      virtual int32			asInt32() const = 0;
      virtual int64			asInt64() const = 0;
      virtual uint8			asUint8() const = 0;
      virtual uint16			asUint16() const = 0;
      virtual uint32			asUint32() const = 0;
      virtual uint64			asUint64() const = 0;
      virtual const std::string		&asString() const = 0;
  };
}

#endif					//_ICONFIGVALUE_H
