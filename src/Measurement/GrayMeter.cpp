#include "GrayMeter.h"

namespace Measurement
{
	GrayMeter::GrayMeter()
	{
	}

	GrayMeter::~GrayMeter()
	{
	}

	void GrayMeter::execute()
	{
		static int counter = 0;
		const int blackValue = mCourseInformation->getBlackValue();
		const int whiteValue = mCourseInformation->getWhiteValue();
		const int grayValue  = (blackValue + whiteValue) / 2;
		const int brightness = mCurrentDeviceInformation->getBrightness();
		if((grayValue - mAcceptRange / 2 <= brightness) && (brightness <= grayValue + mAcceptRange / 2))
		{
			counter++;
		}
		else
		{
			counter = 0;
		}
		mRunInformation->setIsGrayDetected(mLeastAcceptCount < counter);
	}

	void GrayMeter::setAcceptRange(const int acceptRange)
	{
		mAcceptRange = acceptRange;
	}

	void GrayMeter::setLeastAcceptCount(const int leastAcceptCount)
	{
		mLeastAcceptCount = leastAcceptCount;
	}

	void GrayMeter::setCourseInformation(Information::CourseInformation* courseInformation)
	{
		mCourseInformation = courseInformation;
	}

	void GrayMeter::setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation)
	{
		mCurrentDeviceInformation = currentDeviceInformation;
	}

	void GrayMeter::setRunInformation(Information::RunInformation* runInformation)
	{
		mRunInformation = runInformation;
	}

}  // namespace Measurement
