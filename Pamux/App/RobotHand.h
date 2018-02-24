#ifndef ROBOT_HAND_H
#define ROBOT_HAND_H

#include "../Lib/Object.h"

namespace Pamux
{
	uint16_t STRETCHED = 800;
	uint16_t CURLED = 100;

	uint8_t pinky = 0;
	uint8_t ring = 1;
	uint8_t middle = 2;
	uint8_t point = 3;
	uint8_t thumb = 4;

	class RobotHand : public Object
	{

	public:
		RobotHand() {}
		override ~RobotHand() {}

	public:
		override void setupImpl();
		override void loopImpl();

	private:
		void openPalm();
		void fist();
		void setAllFingers(uint16_t on, uint16_t off);
	};
}

#endif