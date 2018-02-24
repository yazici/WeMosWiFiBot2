#ifndef DIFFERENTIAL_DRIVE_H
#define DIFFERENTIAL_DRIVE_H

#include "ArduinoApp.h"
#include "WemosMotor.h"

namespace Pamux
{
	class DifferentialDrive : public Object
	{
	private:
		float _speed;

	private:
		WemosMotor leftMotor;
		WemosMotor rightMotor;
	
	public:
		DifferentialDrive();

	public:
		override void setupImpl();
		
	public:
		void stop();
		void goForward();
		void goBackward();
		void turnLeft();
		void turnRight();
	};
}

#endif