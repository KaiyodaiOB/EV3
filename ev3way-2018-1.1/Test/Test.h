#ifndef TEST_TEST_H
#define TEST_TEST_H

#include "Driver/ColorSensorDriver.h"
#include "Driver/GyroSensorDriver.h"
#include "Driver/MotorDriver.h"
#include "Driver/SonarSensorDriver.h"
#include "Driver/TouchSensorDriver.h"

#include "Utility/LCDController.h"
#include "Utility/Speaker.h"

namespace Test
{
	class Test
	{
	private:
		Driver::ColorSensorDriver* mColorSensorDriver;
		Driver::GyroSensorDriver*  mGyroSensorDriver;
		Driver::MotorDriver*       mRightMotorDriver;
		Driver::MotorDriver*       mLeftMotorDriver;
		Driver::MotorDriver*       mTailMotorDriver;
		Driver::SonarSensorDriver* mSonarSensorDriver;
		Driver::TouchSensorDriver* mTouchSensorDriver;

		Utility::LCDController* mLCDController;
		Utility::Speaker*       mSpeaker;

	private:
		void notifyResult(bool isSuccess);
		bool testDecision();
		bool testDriver();
		bool testExecute();
		bool testInformation();
		bool testMeasurement();
		bool testRun();
		bool testUtility();
	public:
		void execute();
		void setColorSensorDriver(Driver::ColorSensorDriver* colorSensorDriver);
		void setGyroSensorDriver(Driver::GyroSensorDriver* gyroSensorDriver);
		void setRightMotorDriver(Driver::MotorDriver* rightMotorDriver);
		void setLeftMotorDriver(Driver::MotorDriver* leftMotorDriver);
		void setTailMotorDriver(Driver::MotorDriver* tailMotorDriver);
		void setSonarSensorDriver(Driver::SonarSensorDriver* sonarSensorDriver);
		void setTouchSensorDriver(Driver::TouchSensorDriver* touchSensorDriver);
		void setLCDController(Utility::LCDController* lcdController);
		void setSpeaker(Utility::Speaker* speaker);
	};
}  // namespace Test
#endif
