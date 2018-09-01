#include "TailController.h"

namespace Run
{
	TailController::TailController() :
		mTailMotorDriver(nullptr), mPID(nullptr)
	{
	}

	void TailController::execute(int targetAngle, int tailEncoderValue)
	{
		int pwm = mPID->execute(tailEncoderValue, targetAngle);
		if(-100 > pwm) { pwm = -100; }
		if( 100 < pwm) { pwm =  100; }
		mTailMotorDriver->setPWM(pwm);
	}

	void TailController::setTailMotorDriver(Driver::MotorDriver* tailMotorDriver)
	{
		mTailMotorDriver = tailMotorDriver;
	}

	void TailController::setPID(PID* pid)
	{
		mPID = pid;
	}
}  // namespace Run
