#ifndef DRIVER_SONAR_SENSOR_DRIVER_H
#define DRIVER_SONAR_SENSOR_DRIVER_H

#include <SonarSensor.h>
#include <Port.h>

namespace Driver
{
	class SonarSensorDriver
	{
	private:
		ev3api::SonarSensor* mSonarSensor;

	public:
		SonarSensorDriver(enum ePortS port);
		~SonarSensorDriver();
		int getDistance();
		bool listen();
	};
}  // namespace Driver
#endif
