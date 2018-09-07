#ifndef INFORMATION_DEVICE_INFORMATION_H
#define INFORMATION_DEVICE_INFORMATION_H

#include "../Utility/LCDController.h"

namespace Information
{
	class DeviceInformation
	{
	private:
		int  mGyroAngle_deg;
		int  mGyroAnglerVelocity_dps;
		int  mGyroOffset;
		int  mSonarDistance_cm;
		bool mSonarSignal;
		bool mIsTouchSensorPressed;
		int  mBrightness;
		int  mRightMotorCount_deg;
		int  mLeftMotorCount_deg;
		int  mTailMotorCount_deg;
		int  mVoltage_mV;
		Utility::LCDController mLCDController;

	public:
		DeviceInformation();
		void setGyroAngle_deg(int gyroAngle_deg);
		int  getGyroAngle_deg() const;
		void setGyroAnglerVelocity_dps(int gyroAnglerVelocity_dps);
		int  getGyroAnglerVelocity_dps() const;
		void setGyroOffset(int gyroOffset);
		int  getGyroOffset() const;
		void setSonarDistance_cm(int sonarDistance_cm);
		int  getSonarDistance_cm() const;
		void setSonarSignal(bool sonarSignal);
		bool getSonarSignal() const;
		void setIsTouchSensorPressed(bool isPressed);
		bool getIsTouchSensorPressed() const;
		void setBrightness(int brightness);
		int  getBrightness() const;
		void setRightMotorCount_deg(int count);
		int  getRightMotorCount_deg() const;
		void setLeftMotorCount_deg(int count);
		int  getLeftMotorCount_deg() const;
		void setTailMotorCount_deg(int count);
		int  getTailMotorCount_deg() const;
		void setVoltage_mV(int voltage_mV);
		int  getVoltage_mV() const;
	};
}  // namespace Information
#endif
