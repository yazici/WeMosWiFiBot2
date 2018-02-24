#ifndef NO_OP_LOGGER_H
#define NO_OP_LOGGER_H

#include "Logger.h"

namespace Pamux
{
	class NoOpLogger : public Logger
	{
	public:
		override void setupImpl()
		{

		}

		override void printLnImpl()
		{

		}

		override void printImpl(const char *str)
		{

		}

		override void printHexImpl(uint8_t number)
		{

		}
		override void printDecImpl(uint32_t number)
		{

		}
	};
}
#endif