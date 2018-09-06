#include "TailAngleInformation.h"

namespace Information
{
	TailAngleInformation::TailAngleInformation(int angleResting_deg) :
		mAngleResting_deg(angleResting_deg),
		mAngleStartDash_deg(0),
		mAngleInvertedPendulumRunning_deg(0),
		mAngle3PointGroundedRunning_deg(0),
		mAnglePassUnderGate_deg(0)
	{
	}

	void TailAngleInformation::setAngle_deg(ETailAngleType tailAngleType, int angle_deg)
	{
		switch(tailAngleType)
		{
			case eResting:
				mAngleResting_deg   = angle_deg;
				break;
			case eStartDash:
				mAngleStartDash_deg = angle_deg;
				break;
			case eInvertedPendulumRunning:
				mAngleInvertedPendulumRunning_deg = angle_deg;
				break;
			case e3PointGroundedRunning:
				mAngle3PointGroundedRunning_deg   = angle_deg;
				break;
			case ePassUnderGate:
				mAnglePassUnderGate_deg = angle_deg;
				break;
			default:
				break;
		}
	}

	int  TailAngleInformation::getAngle_deg(ETailAngleType tailAngleType) const
	{
		int angle_deg = 0;
		switch(tailAngleType)
		{
			case eResting:
				angle_deg = mAngleResting_deg;
				break;
			case eStartDash:
				angle_deg = mAngleStartDash_deg;
				break;
			case eInvertedPendulumRunning:
				angle_deg = mAngleInvertedPendulumRunning_deg;
				break;
			case e3PointGroundedRunning:
				angle_deg = mAngle3PointGroundedRunning_deg;
				break;
			case ePassUnderGate:
				angle_deg = mAnglePassUnderGate_deg;
				break;
			default:
				break;
		}
		return angle_deg;
	}
}  // namespace Information
