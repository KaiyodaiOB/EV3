#include "SonarSensorDriver.h"

namespace Driver
{
	SonarSensorDriver::SonarSensorDriver(enum ePortS port)
	{
		mSonarSensor = new ev3api::SonarSensor(port);
	}

	SonarSensorDriver::~SonarSensorDriver()
	{
		delete mSonarSensor;
	}
	
	int SonarSensorDriver::getDistance()
	{
		return mSonarSensor->getDistance();
	}

	bool SonarSensorDriver::listen()
	{
		return mSonarSensor->listen();
	}
}  // namespace Driver
