#include "../Lib/Common.h"
#include "../Lib/Servo.h"

#include "RobotHand.h"

namespace Pamux
{
	void RobotHand::setupImpl()
	{
		SERVO.setup();
	}
	
	void RobotHand::loopImpl()
	{
		openPalm();
		delay(1500);
		fist();
		delay(1500);
	}

	void RobotHand::setAllFingers(uint16_t on, uint16_t off)
	{
		SERVO.setPWM(pinky, on, off);
		SERVO.setPWM(ring, on, off);
		SERVO.setPWM(middle, on, off);
		SERVO.setPWM(point, on, off);
		SERVO.setPWM(thumb, on, off);
	}

	void RobotHand::openPalm()
	{
		setAllFingers(0, STRETCHED);
	}

	void RobotHand::fist()
	{
		setAllFingers(0, CURLED);
	}
}