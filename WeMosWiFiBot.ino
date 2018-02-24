#include "Pamux/App/WeMosWiFiBotApp.h"

using namespace Pamux;

ArduinoApp &app = WeMosWiFiBotApp::instance;

void setup() 
{
	app.setup();
}

void loop()
{
	app.loop();
}
