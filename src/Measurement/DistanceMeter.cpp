#include <math.h>
#include "DistanceMeter.h"

namespace Measurement
{
	DistanceMeter::DistanceMeter() :
		iManualMeter()
	{
	}

	DistanceMeter::~DistanceMeter()
	{
	}

	void DistanceMeter::execute()
	{
		int angularVariationRight_deg = mCurrentDeviceInformation->getRightMotorCount_deg() - mPreviousDeviceInformation->getRightMotorCount_deg();
		int angularVariationLeft_deg  = mCurrentDeviceInformation->getLeftMotorCount_deg()  - mPreviousDeviceInformation->getLeftMotorCount_deg();
		double amountOfMovement_mm = M_PI * mEV3BodyInformation->getWheelDiameter_mm() * ((angularVariationRight_deg + angularVariationLeft_deg) / 2) / 360;
		mRunInformation->setMileage_mm(           amountOfMovement_mm + mRunInformation->getMileage_mm());
		mRunInformation->setMileageAccumulated_mm(amountOfMovement_mm + mRunInformation->getMileageAccumulated_mm());
	}
	
	void DistanceMeter::setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation)
	{
		mCurrentDeviceInformation = currentDeviceInformation;
	}

	void DistanceMeter::setPreviousDeviceInformation(Information::DeviceInformation* previousDeviceInformation)
	{
		mPreviousDeviceInformation = previousDeviceInformation;
	}

	void DistanceMeter::setEV3BodyInformation(Information::EV3BodyInformation* ev3BodyInformation)
	{
		mEV3BodyInformation = ev3BodyInformation;
	}

	void DistanceMeter::setRunInformation(Information::RunInformation* runInformation)
	{
		mRunInformation = runInformation;
	}
}  // namespace Measurement
