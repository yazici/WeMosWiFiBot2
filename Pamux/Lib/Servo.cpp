#include "Servo.h"

#include <Adafruit_PWMServoDriver.h>

namespace Pamux
{

	const uint8_t I2C_Servo1 = 0x40;
	const uint8_t I2C_Servo2 = 0x70;


	Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

	Servo* Servo::instance = new Servo();

	void Servo::setupImpl()
	{
		pwm.begin();
		pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
		delay(10);
	}


	Servo::Servo()
	{
	}


	Servo::~Servo()
	{
	}

	// you can use this function if you'd like to set the pulse length in seconds
	// e.g. setServoPulse(0, 0.001) is a ~1 millisecond pulse width. its not precise!
	void Servo::setPulse(uint8_t n, double pulse) {
		double pulselength;

		pulselength = 1000000;   // 1,000,000 us per second
		pulselength /= 60;   // 60 Hz
		Serial.print(pulselength); Serial.println(" us per period");
		pulselength /= 4096;  // 12 bits of resolution
		Serial.print(pulselength); Serial.println(" us per bit");
		pulse *= 1000000;  // convert to us
		pulse /= pulselength;
		Serial.println(pulse);
		pwm.setPWM(n, 0, pulse);
	}

	void setPWM(uint8_t num, uint16_t on, uint16_t off)
	{
		pwm.setPWM(num, on, off);
	}






	//uint8_t servonum = 0;
	//void loopServos()
	//{
	//	//scanI2C();
	//
	//	// Drive each servo one at a time
	//	debugger.println(servonum);
	//	for (uint16_t pulselen = SERVOMIN; pulselen < SERVOMAX; pulselen++) {
	//		pwm.setPWM(servonum, 0, pulselen);
	//	}
	//
	//	delay(500);
	//	for (uint16_t pulselen = SERVOMAX; pulselen > SERVOMIN; pulselen--) {
	//		pwm.setPWM(servonum, 0, pulselen);
	//	}
	//
	//	delay(500);
	//
	//	servonum++;
	//	if (servonum > 7) servonum = 0;
	//}

}