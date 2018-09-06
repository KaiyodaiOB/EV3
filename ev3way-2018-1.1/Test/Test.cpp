#include "Test.h"
#include "ev3api.h"

namespace Test {
	void Test::notifyResult(bool isSuccess)
	{
		ledcolor_t color = isSuccess ? LED_GREEN : LED_RED;
		ev3_led_set_color(color);
		mSpeaker->playTone(250);
		ev3_led_set_color(LED_OFF);
		tslp_tsk(250);
	}
	
	bool Test::testDecision()
	{
		return true;
	}

	bool Test::testDriver()
	{
		bool isSuccess = false;
		{
			mTouchSensorDriver;
		}
		{
			mColorSensorDriver;
		}
		{
			mGyroSensorDriver;
		}
		{
			mRightMotorDriver;
		}
		{
			mLeftMotorDriver;
		}
		{
			mTailMotorDriver;
		}
		{
			mSonarSensorDriver;
		}
		isSuccess = true;
	RETURN:
		return isSuccess;
	}

	bool Test::testExecute()
	{
		return true;
	}

	bool Test::testInformation()
	{
		return true;
	}

	bool Test::testMeasurement()
	{
		return true;
	}

	bool Test::testRun()
	{
		return true;
	}

	bool Test::testUtility()
	{
		return true;
	}

	void Test::execute()
	{
		bool isSuccess = false;
		if(!testUtility()) { goto NOTIFY; }
		if(!testDriver())  { goto NOTIFY; }
		if(!testInformation()) { goto NOTIFY; }
		if(!testMeasurement()) { goto NOTIFY; }
		if(!testRun())      { goto NOTIFY; }
		if(!testDecision()) { goto NOTIFY; }
		if(!testExecute())  { goto NOTIFY; }
		isSuccess = true;
	NOTIFY:
		notifyResult(isSuccess);
	}

	void Test::setColorSensorDriver(Driver::ColorSensorDriver* colorSensorDriver)
	{
		mColorSensorDriver = colorSensorDriver;
	}

	void Test::setGyroSensorDriver(Driver::GyroSensorDriver* gyroSensorDriver)
	{
		mGyroSensorDriver = gyroSensorDriver;
	}

	void Test::setRightMotorDriver(Driver::MotorDriver* rightMotorDriver)
	{
		mRightMotorDriver = rightMotorDriver;
	}

	void Test::setLeftMotorDriver(Driver::MotorDriver* leftMotorDriver)
	{
		mLeftMotorDriver = leftMotorDriver;
	}

	void Test::setTailMotorDriver(Driver::MotorDriver* tailMotorDriver)
	{
		mTailMotorDriver = tailMotorDriver;
	}

	void Test::setSonarSensorDriver(Driver::SonarSensorDriver* sonarSensorDriver)
	{
		mSonarSensorDriver = sonarSensorDriver;
	}

	void Test::setTouchSensorDriver(Driver::TouchSensorDriver* touchSensorDriver)
	{
		mTouchSensorDriver = touchSensorDriver;
	}

	void Test::setLCDController(Utility::LCDController* lcdController)
	{
		mLCDController = lcdController;
	}
	
	void Test::setSpeaker(Utility::Speaker* speaker)
	{
		mSpeaker = speaker;
	}
}