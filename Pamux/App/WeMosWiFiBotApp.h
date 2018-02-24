#ifndef WEMOS_WIFI_BOT_APP_H
#define WEMOS_WIFI_BOT_APP_H

#include "../Lib/ArduinoApp.h"

namespace Pamux
{
	class WeMosWiFiBotApp : public ArduinoApp
	{
	public:
		WeMosWiFiBotApp();
		override ~WeMosWiFiBotApp();
	
	public:
		static WeMosWiFiBotApp instance;

	public:
		override void setupImpl();
		override void loopImpl();
		override void firstLoopImpl();

	};	
}

#endif