#include		"Logger.h"

#ifdef			_WIN32
# include		<Windows.h>
#endif

APIKachu::Logger::Logger(uint8 logType) :
  m_logType(logType),
  m_file(nullptr)
{
}

APIKachu::Logger::~Logger()
{
}

void		APIKachu::Logger::setLogType(uint8 newLogType)
{
  m_logType = newLogType;
}

void		APIKachu::Logger::setFile(FILE *file)
{
  m_file = file;
}

uint8		APIKachu::Logger::getLogType() const
{
  return (m_logType);
}
