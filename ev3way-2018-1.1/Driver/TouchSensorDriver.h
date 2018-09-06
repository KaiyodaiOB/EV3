#ifndef DRIVER_TOUCH_SENSOR_DRIVER_H
#define DRIVER_TOUCH_SENSOR_DRIVER_H

#include <TouchSensor.h>
#include <Port.h>

namespace Driver
{
class TouchSensorDriver
{
private:
	ev3api::TouchSensor* mTouchSensor;

public:
	TouchSensorDriver(enum ePortS port);
	~TouchSensorDriver();
	bool isPressed();

};

}  // namespace Driver
#endif
