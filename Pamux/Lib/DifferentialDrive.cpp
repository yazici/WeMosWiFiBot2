#include "DifferentialDrive.h"
#include "I2C.h"

namespace Pamux
{
	uint8_t LEFT_MOTOR = 0;
	uint8_t RIGHT_MOTOR = 1;

	DifferentialDrive::DifferentialDrive() 
		: _speed(200.0f), leftMotor(LEFT_MOTOR), rightMotor(RIGHT_MOTOR)
	{

	}

	void DifferentialDrive::setupImpl()
	{
		leftMotor.setup();
		rightMotor.setup();
	}

	void DifferentialDrive::stop()
	{
		leftMotor.setMotorState(DCMotor::Stop, 100.0f);
		rightMotor.setMotorState(DCMotor::Stop, 100.0f);
	}

	void DifferentialDrive::goForward()	
	{
		leftMotor.setMotorState(DCMotor::CW, _speed);
		rightMotor.setMotorState(DCMotor::CW, _speed);
	}
	
	void DifferentialDrive::goBackward()
	{
		leftMotor.setMotorState(DCMotor::CCW, _speed);
		rightMotor.setMotorState(DCMotor::CCW, _speed);
	}
	
	void DifferentialDrive::turnLeft()
	{
		leftMotor.setMotorState(DCMotor::CCW, _speed);
		rightMotor.setMotorState(DCMotor::CW, _speed);
	}
	
	void DifferentialDrive::turnRight() 
	{
		leftMotor.setMotorState(DCMotor::CW, _speed);
		rightMotor.setMotorState(DCMotor::CCW, _speed);
	}
}