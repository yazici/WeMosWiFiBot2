#include "WemosMotor.h"
#include "i2c.h"


namespace Pamux
{

	const uint8_t	DEFAULT_WEMOS_MOTOR_I2C = 0x30;
	const uint16_t	DEFAULT_WEMOS_MOTOR_PWM_FREQUENCY = 1000;


	WemosMotor::WemosMotor(uint8_t motorId)
		: WemosMotor(DEFAULT_WEMOS_MOTOR_I2C, DEFAULT_WEMOS_MOTOR_PWM_FREQUENCY, motorId)
	{

	}


	WemosMotor::WemosMotor(uint8_t i2cAddress, uint32_t pwmFrequency, uint8_t motorId)
		: DCMotor(i2cAddress, pwmFrequency, motorId)
	{
		setPwmFrequency(pwmFrequency);
	}

	void WemosMotor::setPwmFrequency(uint32_t pwmFrequency)
	{
		I2C::instance.transmit(_i2cAddress, pwmFrequency);
		delay(100);
	}

	void WemosMotor::setMotorState(DCMotor::States state, float pwm)
	{
		uint16_t normalizedPwm = uint16_t(pwm * 100);

		if (normalizedPwm > 10000)
		{
			normalizedPwm = 10000;
		}

		uint8_t data[4] = {
			_motorId | (uint8_t)0x10,
			(uint8_t)state,
			(uint8_t)(normalizedPwm >> 8),
			(uint8_t)normalizedPwm
		};

		I2C::instance.transmit(_i2cAddress, 4, data);

		delay(100);
	}
}