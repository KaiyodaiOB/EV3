#include <string>
#include "DirectionMeter.h"

namespace Measurement
{
	DirectionMeter::DirectionMeter()
	{
	}

	DirectionMeter::~DirectionMeter()
	{
	}

	void DirectionMeter::execute()
	{
		int angularVariationRight_deg = mCurrentDeviceInformation->getRightMotorCount_deg() - mPreviousDeviceInformation->getRightMotorCount_deg();
		int angularVariationLeft_deg  = mCurrentDeviceInformation->getLeftMotorCount_deg()  - mPreviousDeviceInformation->getLeftMotorCount_deg();
		int angularDifference_deg     = angularVariationRight_deg - angularVariationLeft_deg;
		double variationOfDirection_deg = mEV3BodyInformation->getWheelDiameter_mm() * angularDifference_deg / (2 * mEV3BodyInformation->getWheelDistance_mm());
		mRunInformation->setDirection_deg(           variationOfDirection_deg + mRunInformation->getDirection_deg());
		mRunInformation->setDirectionAccumulated_deg(variationOfDirection_deg + mRunInformation->getDirectionAccumulated_deg());
	}
	
	void DirectionMeter::setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation)
	{
		mCurrentDeviceInformation = currentDeviceInformation;
	}
	
	void DirectionMeter::setPreviousDeviceInformation(Information::DeviceInformation* previousDeviceInformation)
	{
		mPreviousDeviceInformation = previousDeviceInformation;
	}
	
	void DirectionMeter::setEV3BodyInformation(Information::EV3BodyInformation* ev3BodyInformation)
	{
		mEV3BodyInformation = ev3BodyInformation;
	}
	
	void DirectionMeter::setRunInformation(Information::RunInformation* runInformation)
	{
		mRunInformation = runInformation;
	}
}  // namespace Measurement
