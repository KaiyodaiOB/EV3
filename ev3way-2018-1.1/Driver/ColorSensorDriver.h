#ifndef DRIVER_COLOR_SENSOR_DRIVER_H
#define DRIVER_COLOR_SENSOR_DRIVER_H

#include <ColorSensor.h>
#include <Port.h>

namespace Driver
{
	class ColorSensorDriver
	{
	private:
		ev3api::ColorSensor* mColorSensor;

	public:
		ColorSensorDriver(enum ePortS port);
		~ColorSensorDriver();
		int getBrightness();

	};
}  // namespace Driver
#endif
