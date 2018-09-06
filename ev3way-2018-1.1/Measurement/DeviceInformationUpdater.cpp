#include "DeviceInformationUpdater.h"

namespace Measurement
{
	DeviceInformationUpdater::DeviceInformationUpdater() :
		mColorSensorDriver(nullptr),
		mGyroSensorDriver(nullptr),
		mRightMotorDriver(nullptr),
		mLeftMotorDriver(nullptr),
		mTailMotorDriver(nullptr),
		mSonarSensorDriver(nullptr),
		mTouchSensorDriver(nullptr),
		mCurrentDeviceInformation(nullptr),
		mPreviousDeviceInformation(nullptr)
	{
	}

	void DeviceInformationUpdater::setColorSensorDriver(Driver::ColorSensorDriver* colorSensorDriver)
	{
		mColorSensorDriver = colorSensorDriver;
	}
	
	void DeviceInformationUpdater::setGyroSensorDriver(Driver::GyroSensorDriver* gyroSensorDriver)
	{
		mGyroSensorDriver = gyroSensorDriver;
	}
	
	void DeviceInformationUpdater::setRightMotorDriver(Driver::MotorDriver* rightMotorDriver)
	{
		mRightMotorDriver = rightMotorDriver;
	}
	
	void DeviceInformationUpdater::setLeftMotorDriver(Driver::MotorDriver* leftMotorDriver)
	{
		mLeftMotorDriver = leftMotorDriver;
	}
	
	void DeviceInformationUpdater::setTailMotorDriver(Driver::MotorDriver* tailMotorDriver)
	{
		mTailMotorDriver = tailMotorDriver;
	}
	
	void DeviceInformationUpdater::setSonarSensorDriver(Driver::SonarSensorDriver* sonarSensorDriver)
	{
		mSonarSensorDriver = sonarSensorDriver;
	}
	
	void DeviceInformationUpdater::setTouchSensorDriver(Driver::TouchSensorDriver* touchSensorDriver)
	{
		mTouchSensorDriver = touchSensorDriver;
	}

	void DeviceInformationUpdater::setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation)
	{
		mCurrentDeviceInformation = currentDeviceInformation;
	}

	void DeviceInformationUpdater::setPreviousDeviceInformation(Information::DeviceInformation* previousDeviceInformation)
	{
		mPreviousDeviceInformation = previousDeviceInformation;
	}

	void DeviceInformationUpdater::execute()
	{
		updatePreviousInformation();
		mCurrentDeviceInformation->setBrightness(mColorSensorDriver->getBrightness());
		mCurrentDeviceInformation->setGyroAngle_deg(mGyroSensorDriver->getAngle());
		mCurrentDeviceInformation->setGyroAnglerVelocity_dps(mGyroSensorDriver->getAnglerVelocity());
		mCurrentDeviceInformation->setRightMotorCount_deg(mRightMotorDriver->getCount());
		mCurrentDeviceInformation->setLeftMotorCount_deg(mLeftMotorDriver->getCount());
		mCurrentDeviceInformation->setTailMotorCount_deg(mTailMotorDriver->getCount());
		mCurrentDeviceInformation->setIsTouchSensorPressed(mTouchSensorDriver->isPressed());
		mCurrentDeviceInformation->setSonarDistance_cm(mSonarSensorDriver->getDistance());
		mCurrentDeviceInformation->setSonarSignal(mSonarSensorDriver->listen());
		mCurrentDeviceInformation->setVoltage_mV(ev3_battery_voltage_mV());
	}

	void DeviceInformationUpdater::updatePreviousInformation()
	{
		*mPreviousDeviceInformation = *mCurrentDeviceInformation;
	}
}  // namespace Measurement
