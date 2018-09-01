#include <math.h>
#include "VelocityMeter.h"

namespace Measurement
{
	VelocityMeter::VelocityMeter()
	{
	}

	VelocityMeter::~VelocityMeter()
	{
	}

	void VelocityMeter::execute()
	{
		int angularVariationRight_deg = mCurrentDeviceInformation->getRightMotorCount_deg() - mPreviousDeviceInformation->getRightMotorCount_deg();
		int angularVariationLeft_deg  = mCurrentDeviceInformation->getLeftMotorCount_deg()  - mPreviousDeviceInformation->getLeftMotorCount_deg();
		double amountOfMovement_mm = M_PI * mEV3BodyInformation->getWheelDiameter_mm() * ((angularVariationRight_deg + angularVariationLeft_deg) / 2) / 360;
		double time_sec = 0.004;
		double velocity = amountOfMovement_mm / time_sec;
		mRunInformation->setVelocity_mmps(velocity);
	}

	void VelocityMeter::setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation)
	{
		mCurrentDeviceInformation = currentDeviceInformation;
	}
	
	void VelocityMeter::setPreviousDeviceInformation(Information::DeviceInformation* previousDeviceInformation)
	{
		mPreviousDeviceInformation = previousDeviceInformation;
	}
	
	void VelocityMeter::setEV3BodyInformation(Information::EV3BodyInformation* ev3BodyInformation)
	{
		mEV3BodyInformation = ev3BodyInformation;
	}
	
	void VelocityMeter::setRunInformation(Information::RunInformation* runInformation)
	{
		mRunInformation = runInformation;
	}
}  // namespace Measurement
