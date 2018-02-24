#ifndef LOGGER_BASE_H
#define LOGGER_BASE_H

#include "Object.h"

namespace Pamux
{
	abstract class Logger : public Object
	{
	public:
		
		static Logger *instance;

		static void Setup() 
		{
			instance->setup();
		}

		static void Print(const char *str)
		{ 
			instance->printImpl(str);
		}

		static void PrintLn(const char *str)
		{
			instance->printImpl(str);
			instance->printLnImpl();
		}
	
		static void PrintHex(uint8_t number)
		{
			instance->printHexImpl(number);
		}

		static void PrintHexLn(uint8_t number)
		{
			instance->printHexImpl(number);
			instance->printLnImpl();
		}

		static void Print(uint32_t number)
		{
			instance->printDecImpl(number);
		}

		static void PrintLn(uint32_t number)
		{
			instance->printDecImpl(number);
			instance->printLnImpl();
		}

	protected:
		virtual void printLnImpl()  pure;
		virtual void printImpl(const char *str)  pure;
		virtual void printHexImpl(uint8_t number)  pure;
		virtual void printDecImpl(uint32_t number)  pure;
	};
}

#endif