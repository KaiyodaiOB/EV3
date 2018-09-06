#include "InvertedPendulumBalancer.h"
#include "balancer.h"

namespace Run
{

	InvertedPendulumBalancer::InvertedPendulumBalancer() :
		mForward(0), mTurn(0), mGyroOffset(0), mRightPwm(0), mLeftPwm(0)
	{
	}

	void InvertedPendulumBalancer::init(int gyroOffset)
	{
		mGyroOffset = gyroOffset;
		balance_init();
	}

	void InvertedPendulumBalancer::update(int gyroAnglerVelocity, int rightMotorCount, int leftMotorCount, int voltage_mV)
	{
		backlashCanceler(rightMotorCount, leftMotorCount);
		balance_control(static_cast<float>(mForward),
						static_cast<float>(mTurn),
						static_cast<float>(gyroAnglerVelocity),
						static_cast<float>(mGyroOffset),
						static_cast<float>(leftMotorCount),
						static_cast<float>(rightMotorCount),
						static_cast<float>(voltage_mV),
						&mLeftPwm,
						&mRightPwm);
	}

	void InvertedPendulumBalancer::setCommand(int forward, int turn)
	{
		mForward = forward;
		mTurn    = turn;
	}

	int8_t InvertedPendulumBalancer::getPwmRight() const
	{
		return mRightPwm;
	}

	int8_t InvertedPendulumBalancer::getPwmLeft()  const
	{
		return mLeftPwm;
	}

	void InvertedPendulumBalancer::backlashCanceler(int& rightMotorCount, int& leftMotorCount) const
	{
		const int BACKLASH_HALF_DEG = 4;
		if(mRightPwm < 0)      { rightMotorCount += BACKLASH_HALF_DEG; }
		else if(mRightPwm > 0) { rightMotorCount -= BACKLASH_HALF_DEG; }

		if(mLeftPwm < 0)       { leftMotorCount  += BACKLASH_HALF_DEG; }
		else if(mLeftPwm > 0)  { leftMotorCount  -= BACKLASH_HALF_DEG; }
	}
}  // namespace Run
