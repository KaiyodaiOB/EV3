#ifndef MEASUREMENT_DEVICE_INFORMATION_UPDATER_H
#define MEASUREMENT_DEVICE_INFORMATION_UPDATER_H

#include "Driver/ColorSensorDriver.h"
#include "Driver/GyroSensorDriver.h"
#include "Driver/MotorDriver.h"
#include "Driver/SonarSensorDriver.h"
#include "Driver/TouchSensorDriver.h"

#include "Information/DeviceInformation.h"

namespace Measurement
{
	class DeviceInformationUpdater
	{
	private:
		Driver::ColorSensorDriver* mColorSensorDriver;
		Driver::GyroSensorDriver*  mGyroSensorDriver;
		Driver::MotorDriver*       mRightMotorDriver;
		Driver::MotorDriver*       mLeftMotorDriver;
		Driver::MotorDriver*       mTailMotorDriver;
		Driver::SonarSensorDriver* mSonarSensorDriver;
		Driver::TouchSensorDriver* mTouchSensorDriver;

		Information::DeviceInformation* mCurrentDeviceInformation;
		Information::DeviceInformation* mPreviousDeviceInformation;

	public:
		DeviceInformationUpdater();
		void setColorSensorDriver(Driver::ColorSensorDriver* colorSensorDriver);
		void setGyroSensorDriver( Driver::GyroSensorDriver*  gyroSensorDriver);
		void setRightMotorDriver( Driver::MotorDriver* rightMotorDriver);
		void setLeftMotorDriver(  Driver::MotorDriver* leftMotorDriver);
		void setTailMotorDriver(  Driver::MotorDriver* tailMotorDriver);
		void setSonarSensorDriver(Driver::SonarSensorDriver* sonarSensorDriver);
		void setTouchSensorDriver(Driver::TouchSensorDriver* touchSensorDriver);
		void setCurrentDeviceInformation( Information::DeviceInformation* currentDeviceInformation);
		void setPreviousDeviceInformation(Information::DeviceInformation* previousDeviceInformation);
		void execute();
	private:
		void updatePreviousInformation();
	};
}  // namespace Measurement
#endif
