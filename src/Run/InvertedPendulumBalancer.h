#ifndef RUN_INVERTED_PENDULUM_BALANCER_H
#define RUN_INVERTED_PENDULUM_BALANCER_H

#include <cstdint>

namespace Run
{
	class InvertedPendulumBalancer
	{
	private:
		int mForward;
		int mTurn;
		int mGyroOffset;
		int8_t mRightPwm;
		int8_t mLeftPwm;

	public:
		InvertedPendulumBalancer();
		void init(int gyroOffset);
		void update(int gyroAnglerVelocity, int rightMotorCount, int leftMotorCount, int voltage_mV);
		void setCommand(int forward, int turn);
		int8_t getPwmRight() const;
		int8_t getPwmLeft()  const;
	private:
		void backlashCanceler(int& rightMotorCount, int& leftMotorCount) const;
	};
}  // namespace Run
#endif
