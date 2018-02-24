
#include "ArduinoApp.h"
#include "BuiltInLED.h"
#include "Logger.h"
#include "I2C.h"

namespace Pamux
{
	uint32_t ArduinoApp::FrameId = -1;
	bool ArduinoApp::isFirstLoop = true;

	void ArduinoApp::setupImpl()
	{
		FrameId = -1;

		Object::setupImpl();

		Logger::Setup();

		BuiltInLED::Setup();
		I2C::Setup();
	}

	void ArduinoApp::loopImpl()
	{
		++FrameId;
		if (isFirstLoop)
		{
			isFirstLoop = false;
			firstLoopImpl();
		}
		BuiltInLED::Loop();
	}

	void ArduinoApp::firstLoopImpl()
	{
	}
}