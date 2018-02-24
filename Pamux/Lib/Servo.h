#ifndef SERVO_H
#define SERVO_H

#include "Object.h"

namespace Pamux
{
	class Servo : public Object
	{
	public:
		static Servo *instance;

	public:
		Servo();
		override ~Servo();

	public:
		override void setupImpl();
		// override void loopImpl();

	public:
		// you can use this function if you'd like to set the pulse length in seconds
		// e.g. setPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
		void setPulse(uint8_t n, double pulse);

		void setPWM(uint8_t num, uint16_t on, uint16_t off);
	};

	static Servo &SERVO = *Servo::instance;

}

#endif