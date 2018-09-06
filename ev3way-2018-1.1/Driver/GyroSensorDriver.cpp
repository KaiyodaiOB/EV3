#include "GyroSensorDriver.h"

namespace Driver
{
	GyroSensorDriver::GyroSensorDriver(enum ePortS port)
	{
		mGyroSensor = new ev3api::GyroSensor(port);
	}
	
	GyroSensorDriver::~GyroSensorDriver()
	{
		delete mGyroSensor;
	}
	
	void GyroSensorDriver::setOffset(int offset)
	{
		mGyroSensor->setOffset(offset);
	}
	
	void GyroSensorDriver::reset()
	{
		mGyroSensor->reset();
	}
	
	int GyroSensorDriver::getAnglerVelocity()
	{
		return mGyroSensor->getAnglerVelocity();
	}
	
	int GyroSensorDriver::getAngle()
	{
		return mGyroSensor->getAngle();
	}
}  // namespace Driver
