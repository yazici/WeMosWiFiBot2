#ifndef DC_MOTOR_H
#define DC_MOTOR_H

#include "Object.h"

namespace Pamux
{
	

	class DCMotor : public Object
	{
	public:
		enum States
		{
			ShortBrake = 0,
			CCW = 1,
			CW = 2,
			Stop = 3,
			StandBy = 4
		};


	protected:
		uint8_t _i2cAddress;
		uint32_t _pwmFrequency;
		uint8_t _motorId;

	protected:
		DCMotor(uint8_t i2cAddress, uint32_t _pwmFrequency, uint8_t motorId);
	
	public:
		override void setupImpl();
	
	public:
		virtual void setMotorState(DCMotor::States state, float pwm) pure;
	};
}


#endif