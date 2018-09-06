#ifndef MEASUREMENT_DISTANCE_METER_H
#define MEASUREMENT_DISTANCE_METER_H

#include "Information/DeviceInformation.h"
#include "Information/EV3BodyInformation.h"
#include "Information/RunInformation.h"

#include "Measurement/iManualMeter.h"

namespace Measurement
{
	class DistanceMeter : public iManualMeter
	{
	private:
		Information::DeviceInformation*  mCurrentDeviceInformation;
		Information::DeviceInformation*  mPreviousDeviceInformation;
		Information::EV3BodyInformation* mEV3BodyInformation;
		Information::RunInformation*     mRunInformation;

	public:
		DistanceMeter();
		~DistanceMeter();
		void execute();

		void setCurrentDeviceInformation( Information::DeviceInformation*  currentDeviceInformation);
		void setPreviousDeviceInformation(Information::DeviceInformation*  previousDeviceInformation);
		void setEV3BodyInformation(       Information::EV3BodyInformation* ev3BodyInformation);
		void setRunInformation(           Information::RunInformation*     runInformation);
	};
}  // namespace Measurement
#endif
