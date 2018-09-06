#ifndef INFORMATION_TAIL_ANGLE_INFORMATION_H
#define INFORMATION_TAIL_ANGLE_INFORMATION_H

#include "Information/ETailAngleType.h"

namespace Information
{
	class TailAngleInformation
	{
	private:
		int mAngleResting_deg;
		int mAngleStartDash_deg;
		int mAngleInvertedPendulumRunning_deg;
		int mAngle3PointGroundedRunning_deg;
		int mAnglePassUnderGate_deg;

	public:
		TailAngleInformation(int angleResting_deg = 0);
		void setAngle_deg(ETailAngleType tailAngleType, int angle_deg);
		int  getAngle_deg(ETailAngleType tailAngleType) const;
	};
}  // namespace Information
#endif
