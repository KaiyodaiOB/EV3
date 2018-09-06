#ifndef DRIVER_GYRO_SENSOR_DRIVER_H
#define DRIVER_GYRO_SENSOR_DRIVER_H

#include <GyroSensor.h>
#include <Port.h>

namespace Driver
{
	class GyroSensorDriver
	{
	private:
		ev3api::GyroSensor* mGyroSensor;

	public:
		GyroSensorDriver(enum ePortS port);
		~GyroSensorDriver();
		void setOffset(int offset);
		void reset();
		int getAnglerVelocity();
		int getAngle();
	};
}  // namespace Driver
#endif
