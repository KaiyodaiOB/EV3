#include "TouchSensorDriver.h"

namespace Driver
{
	TouchSensorDriver::TouchSensorDriver(enum ePortS port)
	{
		mTouchSensor = new ev3api::TouchSensor(port);
	}

	TouchSensorDriver::~TouchSensorDriver()
	{
		delete mTouchSensor;
	}

	bool TouchSensorDriver::isPressed()
	{
		return mTouchSensor->isPressed();
	}
}  // namespace Driver
