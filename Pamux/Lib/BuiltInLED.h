#ifndef BUILT_IN_LED_H
#define BUILT_IN_LED_H

#include "Object.h"

namespace Pamux
{
	class BuiltInLED : public Object
	{
	public:
		static BuiltInLED instance;

		static void Setup()
		{
			instance.setup();
		}

		static void Loop()
		{
			instance.loop();
		}

	private:
		uint8_t state;
		unsigned long lastStateToggleMillis;
		void toggleState();

	public:
		override void setupImpl();
		override void loopImpl();
	};
}

#endif