#include "BuiltInLED.h"
#include "ArduinoApp.h"
#include "LoggerBase.h"

namespace Pamux
{
	BuiltInLED BuiltInLED::instance;

	void BuiltInLED::setupImpl()
	{
		lastStateToggleMillis = 0;
		state = HIGH;

		pinMode(LED_BUILTIN, OUTPUT);
	}

	void BuiltInLED::toggleState()
	{
		//Logger::println(ArduinoApp::FrameId);

		state = state == HIGH ? LOW : HIGH;

		digitalWrite(LED_BUILTIN, state);

		lastStateToggleMillis = millis();
	}

	void BuiltInLED::loopImpl()
	{
		if (millis() - lastStateToggleMillis >= 1000)
		{
			toggleState();
		}
	}
}