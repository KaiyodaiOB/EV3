#include "DeviceInformation.h"

namespace Information
{
	DeviceInformation::DeviceInformation() :
		mGyroAngle_deg(0),
		mGyroAnglerVelocity_dps(0),
		mGyroOffset(0),
		mSonarDistance_cm(0),
		mIsTouchSensorPressed(false),
		mBrightness(0),
		mRightMotorCount_deg(0),
		mLeftMotorCount_deg(0),
		mTailMotorCount_deg(0),
		mVoltage_mV(0)
	{
	}

	void DeviceInformation::setGyroAngle_deg(int gyroAngle_deg)
	{
		mGyroAngle_deg = gyroAngle_deg;
	}

	int  DeviceInformation::getGyroAngle_deg() const
	{
		return mGyroAngle_deg;
	}

	void DeviceInformation::setGyroAnglerVelocity_dps(int gyroAnglerVelocity_dps)
	{
		mGyroAnglerVelocity_dps = gyroAnglerVelocity_dps;
	}

	int  DeviceInformation::getGyroAnglerVelocity_dps() const
	{
		return mGyroAnglerVelocity_dps;
	}

	void DeviceInformation::setGyroOffset(int gyroOffset)
	{
		mGyroOffset = gyroOffset;
	}

	int  DeviceInformation::getGyroOffset() const
	{
		return mGyroOffset;
	}

	void DeviceInformation::setSonarDistance_cm(int sonarDistance_cm)
	{
		mSonarDistance_cm = sonarDistance_cm;
	}

	int  DeviceInformation::getSonarDistance_cm() const
	{
		return mSonarDistance_cm;
	}

	void DeviceInformation::setIsTouchSensorPressed(bool isPressed)
	{
		mIsTouchSensorPressed = isPressed;
	}

	bool DeviceInformation::getIsTouchSensorPressed() const
	{
		return mIsTouchSensorPressed;
	}

	void DeviceInformation::setBrightness(int brightness)
	{
		mBrightness = brightness;
	}

	int  DeviceInformation::getBrightness() const
	{
		return mBrightness;
	}
	
	void DeviceInformation::setRightMotorCount_deg(int count)
	{
		mRightMotorCount_deg = count;
	}

	int  DeviceInformation::getRightMotorCount_deg() const
	{
		return mRightMotorCount_deg;
	}

	void DeviceInformation::setLeftMotorCount_deg(int count)
	{
		mLeftMotorCount_deg = count;
	}

	int  DeviceInformation::getLeftMotorCount_deg() const
	{
		return mLeftMotorCount_deg;
	}

	void DeviceInformation::setTailMotorCount_deg(int count)
	{
		mTailMotorCount_deg = count;
	}

	int  DeviceInformation::getTailMotorCount_deg() const
	{
		return mTailMotorCount_deg;
	}

	void DeviceInformation::setVoltage_mV(int voltage_mV)
	{
		mVoltage_mV = voltage_mV;
	}

	int  DeviceInformation::getVoltage_mV() const
	{
		return mVoltage_mV;
	}
}  // namespace Information
