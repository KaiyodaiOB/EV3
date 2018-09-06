#ifndef RUN_RUN_H
#define RUN_RUN_H

#include "Driver/MotorDriver.h"
#include "Information/CourseInformation.h"
#include "Information/DeviceInformation.h"
#include "Information/RunCorrectionInformation.h"
#include "Information/TailAngleInformation.h"
#include "Run/InvertedPendulumBalancer.h"
#include "Run/PID.h"
#include "Run/RunSet.h"
#include "Run/TailController.h"
#include "Utility/LCDController.h"

namespace Run
{
	class Run
	{
	private:
		InvertedPendulumBalancer* mInvertedPendulumBalancer;
		TailController* mTailController;
		Driver::MotorDriver* mRightMotorDriver;
		Driver::MotorDriver* mLeftMotorDriver;
		Information::CourseInformation* mCourseInformation;
		Information::DeviceInformation* mCurrentDeviceInformation;
		Information::RunCorrectionInformation* mRunCorrectionInformation;
		Information::TailAngleInformation*     mTailAngleInformation;
		Utility::LCDController mLCDController;

	public:
		Run();
		void execute(RunSet* runset, PID* runPID);

		void setInvertedPendulumBalancer(InvertedPendulumBalancer* invertedPendulumBalancer);
		void setTailController(TailController* tailController);
		void setRightMotorDriver(Driver::MotorDriver* rightMotorDriver);
		void setLeftMotorDriver( Driver::MotorDriver* leftMotorDriver);
		void setCourseInformation(Information::CourseInformation* courseInformation);
		void setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation);
		void setRunCorrectionInformation(Information::RunCorrectionInformation* runCorrectionInformation);
		void setTailAngleInformation(Information::TailAngleInformation* tailAngleInformation);
	private:
		void calculatePwm(RunSet* runset, PID* runPID, int& rightPwm, int& leftPwm);
	};

}  // namespace Run
#endif
