#include "EV3BodyInformation.h"

namespace Information
{
	EV3BodyInformation::EV3BodyInformation() :
		mWheelDistance_mm(170.0),
		mWheelDiameter_mm(100.0)
	{
	}
	
	double EV3BodyInformation::getWheelDistance_mm() const
	{
		return mWheelDistance_mm;
	}

	double EV3BodyInformation::getWheelDiameter_mm() const
	{
		return mWheelDiameter_mm;
	}
}  // namespace Information
