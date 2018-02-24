#ifndef ARDUINO_APP_H
#define ARDUINO_APP_H

#include "Object.h"

namespace Pamux
{
	class Logger;
	class I2C;

	abstract class ArduinoApp : public Object
	{
		
	public:
		static uint32_t FrameId;
		static bool isFirstLoop;
		
	
	public:
		virtual void setupImpl();
		virtual void loopImpl();
		virtual void firstLoopImpl();
	};

	
}

#endif