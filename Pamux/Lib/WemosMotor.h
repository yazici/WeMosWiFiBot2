#ifndef __WEMOS_MOTOR_H
#define __WEMOS_MOTOR_H

#include "DCMotor.h"

namespace Pamux
{
	class WemosMotor : public DCMotor {

	public:
		WemosMotor(uint8_t motorId);
		WemosMotor(uint8_t i2cAddress, uint32_t pwmFrequency, uint8_t motorId);

	public:
		void setPwmFrequency(uint32_t pwmFrequency);

		override void setMotorState(DCMotor::States state, float pwm);

	};
}

#endif


