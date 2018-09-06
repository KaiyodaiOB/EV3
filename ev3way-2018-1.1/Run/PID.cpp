#include "PID.h"

namespace Run
{
	PID::PID(double kp, double ki, double kd) :
		mKp(kp), mKi(ki), mKd(kd), mErrorOld(0.0), mErrorNew(0.0), mIntegral(0.0), mTimeSec(0.004)
	{
	}

	int PID::execute(double valueCurrent, double valueTarget)
	{
		mErrorOld  = mErrorNew;
		mErrorNew  = valueCurrent - valueTarget;
		mIntegral += mKi * (mErrorNew + mErrorOld) * mTimeSec / 2.0;
		double proportional = mKp * (mErrorNew - mErrorOld);
		double integral     = mIntegral;
		double derivative   = mKd * (mErrorNew - mErrorOld) / mTimeSec;
		return proportional + integral + derivative;
	}
}  // namespace Run
