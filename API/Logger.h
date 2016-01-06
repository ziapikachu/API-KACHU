#ifndef				_ALOGGER_H_
#define				_ALOGGER_H_

#include			<cstdio>

#include			"IAPIObject.h"

namespace			APIKachu
{
  /**
  * @brief Base class for message displaying
  * @details Logger for outputting messages to the console or a file 
  */
  class				Logger : public virtual IAPIObject
  {
    public:
      /**
      * @brief Type of a message to be logged
      * @details Specifies different types of messages ; used as a bitmask in the configuration (see documentation for configuration)
      */
      enum			LogType : uint8
      {
	LOG_TYPE_NONE		= 0x00,
	LOG_TYPE_BASIC		= 0x01,
	LOG_TYPE_ERROR		= 0x02,
	LOG_TYPE_DEBUG		= 0x04,
	LOG_TYPE_DETAIL		= 0x08,
	LOG_TYPE_ALL		= 0xFF
      };

      /**
      * @brief Constructor for the logger
      * @details Constructs the logger and assigns a type for filtering incoming messages
      * @param uint8 logtype - bitmask specifying message types to display
      */
      Logger(uint8 logType) :
	m_logType(logType),
	m_file(nullptr)
      {
      }

      /**
      * @brief Destructor for the logger
      */
      virtual ~Logger() = default;

      /**
      * @brief Setter for the log type
      * @param unit8 newLogType - bitmask specifying message types to display
      */
      virtual void		setLogType(uint8 newLogType)
      {
	m_logType = newLogType;
      }

      /**
      * @brief Setter for the log file
      * @param FILE *file - log file ; null redirect to stdout or stderr for errors
      */
      void			setFile(FILE *file)
      {
	m_file = file;
      }

      /**
      * @brief Outputs a basic message
      * @details Only outputs a message if the logger's log type contains LOG_TYPE_BASIC
      * @param const char * format - printf-type format
      * @param ... - arguments for the format
      */
      template <typename... Args>
      void			outBasic(const char *format, const Args&... args)
      {
	if (!(m_logType & LOG_TYPE_BASIC))
	  return;
	if (m_file)
	  fprintf(m_file, format, args...);
	else
	{
	  fprintf(stdout, format, args...);
	  fflush(stdout);
	}
      }

      /**
      * @brief Outputs an error message
      * @details Only outputs a message if the logger's log type contains LOG_TYPE_ERROR
      * @param const char * format - printf-type format
      * @param ... - arguments for the format
      */
      template <typename... Args>
      void			outError(const char *format, const Args&... args)
      {
	if (!(m_logType & LOG_TYPE_ERROR))
	  return;
	if (m_file)
	  fprintf(m_file, format, args...);
	else
	{
	  fprintf(stderr, format, args...);
	  fflush(stderr);
	}
      }

      /**
      * @brief Outputs a debug message
      * @details Only outputs a message if the logger's log type contains LOG_TYPE_DEBUG
      * @param const char * format - printf-type format
      * @param ... - arguments for the format
      */
      template <typename... Args>
      void			outDebug(const char *format, const Args&... args)
      {
	if (!(m_logType & LOG_TYPE_DEBUG))
	  return;
	if (m_file)
	  fprintf(m_file, format, args...);
	else
	{
	  fprintf(stdout, format, args...);
	  fflush(stdout);
	}
      }

      /**
      * @brief Outputs a detail message
      * @details Only outputs a message if the logger's log type contains LOG_TYPE_DETAIL
      * @param const char * format - printf-type format
      * @param ... - arguments for the format
      */
      template <typename... Args>
      void			outDetail(const char *format, const Args&... args)
      {
	if (!(m_logType & LOG_TYPE_DETAIL))
	  return;
	if (m_file)
	  fprintf(m_file, format, args...);
	else
	{
	  fprintf(stdout, format, args...);
	  fflush(stdout);
	}
      }

      /**
      * @brief Getter for the log type
      */
      virtual uint8		getLogType() const
      {
	return (m_logType);
      }

    private:
      uint8			m_logType;
      FILE			*m_file;
  };
}

#endif				/* _ALOGGER_H_ */
