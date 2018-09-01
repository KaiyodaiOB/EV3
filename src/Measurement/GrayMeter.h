#ifndef MEASUREMENT_GRAY_METER_H
#define MEASUREMENT_GRAY_METER_H

#include "Information/CourseInformation.h"
#include "Information/DeviceInformation.h"
#include "Information/RunInformation.h"

#include "Measurement/iManualMeter.h"

namespace Measurement
{
	class GrayMeter : public iManualMeter
	{
	private:
		int mAcceptRange;
		int mLeastAcceptCount;
		Information::CourseInformation* mCourseInformation;
		Information::DeviceInformation* mCurrentDeviceInformation;
		Information::RunInformation*    mRunInformation;

	public:
		GrayMeter();
		~GrayMeter();
		void execute();
		
		void setAcceptRange(     const int acceptRange);
		void setLeastAcceptCount(const int leastAcceptCount);
		void setCourseInformation(       Information::CourseInformation* courseInformation);
		void setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation);
		void setRunInformation(          Information::RunInformation*    runInformation);
	};
}  // namespace Measurement
#endif
