#include "ColorSensorDriver.h"

namespace Driver
{
	ColorSensorDriver::ColorSensorDriver(enum ePortS port)
	{
		mColorSensor = new ev3api::ColorSensor(port);
	}

	ColorSensorDriver::~ColorSensorDriver()
	{
		delete mColorSensor;
	}
	
	int ColorSensorDriver::getBrightness()
	{
		return mColorSensor->getBrightness();
	}
}  // namespace Driver
