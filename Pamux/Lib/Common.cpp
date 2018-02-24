#include "Common.h"

//#include "NoOpLogger.h"
#include "SerialLogger.h"
namespace Pamux
{
	Logger* Logger::instance = new SerialLogger();
}