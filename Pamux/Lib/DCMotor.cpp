#include "DCMotor.h"
#include "i2c.h"

namespace Pamux
{
	DCMotor::DCMotor(uint8_t i2cAddress, uint32_t pwmFrequency, uint8_t motorId)
		: _i2cAddress(i2cAddress), _pwmFrequency(pwmFrequency), _motorId(motorId)
	{
	}



}