#ifndef DRIVER_MOTOR_DRIVER_H
#define DRIVER_MOTOR_DRIVER_H

#include <Motor.h>
#include <Port.h>

namespace Driver
{
	class MotorDriver
	{
	private:
		ev3api::Motor* mMotor;

	public:
		MotorDriver(ePortM port);
		~MotorDriver();
		void reset();
		int getCount();
		void setCount(int count);
		void setPWM(int pwm);
		void stop();
	};
}  // namespace Driver
#endif
