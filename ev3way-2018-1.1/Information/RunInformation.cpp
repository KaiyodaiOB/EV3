#include "RunInformation.h"

namespace Information
{
	RunInformation::RunInformation() :
		mMileage_mm(0.0),
		mDirection_deg(0.0),
		mMileageAccumulated_mm(0.0),
		mDirectionAccumulated_deg(0.0),
		mVelocity_mmps(0.0),
		mIsGrayDetected(false)
	{
	}
	
	void   RunInformation::setMileage_mm(double mileage_mm)
	{
		mMileage_mm = mileage_mm;
	}

	double RunInformation::getMileage_mm() const
	{
		return mMileage_mm;
	}

	void   RunInformation::setDirection_deg(double direction_deg)
	{
		mDirection_deg = direction_deg;
	}

	double RunInformation::getDirection_deg() const
	{
		return mDirection_deg;
	}

	void   RunInformation::setMileageAccumulated_mm(double mileageAccumulated_mm)
	{
		mMileageAccumulated_mm = mileageAccumulated_mm;
	}

	double RunInformation::getMileageAccumulated_mm() const
	{
		return mMileageAccumulated_mm;
	}

	void   RunInformation::setDirectionAccumulated_deg(double directionAccumulated_deg)
	{
		mDirectionAccumulated_deg = directionAccumulated_deg;
	}

	double RunInformation::getDirectionAccumulated_deg() const
	{
		return mDirectionAccumulated_deg;
	}

	void   RunInformation::setVelocity_mmps(double velocity_mmps)
	{
		mVelocity_mmps = velocity_mmps;
	}

	double RunInformation::getVelocity_mmps() const
	{
		return mVelocity_mmps;
	}

	void RunInformation::setIsGrayDetected(bool isGrayDetected)
	{
		mIsGrayDetected = isGrayDetected;
	}

	bool RunInformation::getIsGrayDetected() const
	{
		return mIsGrayDetected;
	}
}  // namespace Information
