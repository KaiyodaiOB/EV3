#include "MotorDriver.h"

namespace Driver
{
	MotorDriver::MotorDriver(ePortM port)
	{
		mMotor = new ev3api::Motor(port);
	}

	MotorDriver::~MotorDriver()
	{
		delete mMotor;
	}
	
	void MotorDriver::reset()
	{
		mMotor->reset();
	}
	
	int MotorDriver::getCount()
	{
		return mMotor->getCount();
	}
	
	void MotorDriver::setCount(int count)
	{
		mMotor->setCount(count);
	}
	void MotorDriver::setPWM(int pwm)
	{
		mMotor->setPWM(pwm);
	}
	
	void MotorDriver::stop()
	{
		mMotor->stop();
	}
}  // namespace Driver
