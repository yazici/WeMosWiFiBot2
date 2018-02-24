#ifndef SERIAL_LOGGER_H
#define SERIAL_LOGGER_H

#include "Logger.h"

namespace Pamux
{
	class SerialLogger : public Logger
	{
	public:
		override void setupImpl()
		{
			Logger::setupImpl();

			Serial.begin(250000);
			Serial.println("Serial port opened1");
		}

		override void printLnImpl()
		{
			Serial.println("");
		}

		override void printImpl(const char *str)
		{
			Serial.print(str);
		}

		override void printHexImpl(uint8_t number)
		{
			Serial.print(number, HEX);
		}
		override void printDecImpl(uint32_t number)
		{
			Serial.print(number);
		}		
	};
}
#endif