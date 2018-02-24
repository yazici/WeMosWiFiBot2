#include "WeMosWiFiBotApp.h"

//#include "../Lib/DifferentialDrive.h"
#include "../Lib/i2c.h"

#include "../Lib/Logger.h"

//DifferentialDrive dd;

#include <Wire.h>

namespace Pamux
{
	WeMosWiFiBotApp WeMosWiFiBotApp::instance;

	WeMosWiFiBotApp::WeMosWiFiBotApp()
	{
	}


	WeMosWiFiBotApp::~WeMosWiFiBotApp()
	{
	}


	void WeMosWiFiBotApp::setupImpl()
	{
		ArduinoApp::setupImpl();

		
		//dd.setup();
		
		
	}

	void WeMosWiFiBotApp::loopImpl()
	{
		ArduinoApp::loopImpl();
		
		//Logger::println(ArduinoApp::FrameId);

		
		if (ArduinoApp::FrameId == 1)
		{
			Logger::PrintLn(ArduinoApp::FrameId);
			I2C::instance.scan();
		}

		/*dd.goForward();
		delay(1000);

		dd.stop();
		delay(1000);


		dd.turnRight();
		delay(1000);

		dd.stop();
		delay(1000);*/
	}

	void WeMosWiFiBotApp::firstLoopImpl()
	{
		ArduinoApp::firstLoopImpl();
		
		Logger::PrintLn(ArduinoApp::FrameId);
		I2C::instance.scan();
	}
}