#include "Run/ETurnSelectionType.h"
#include "Run/Run.h"

namespace Run
{
	Run::Run() :
		mInvertedPendulumBalancer(nullptr),
		mTailController(nullptr),
		mRightMotorDriver(nullptr),
		mLeftMotorDriver( nullptr),
		mCourseInformation(nullptr),
		mCurrentDeviceInformation(nullptr),
		mRunCorrectionInformation(nullptr),
		mTailAngleInformation(nullptr)
	{
	}

	void Run::execute(RunSet* runset, PID* runPID)
	{
		if(runset->getIsTailControlEnable())
		{
			int targetAngle      = mTailAngleInformation->getAngle_deg(runset->getTailAngleType());
			int tailEncoderValue = mCurrentDeviceInformation->getTailMotorCount_deg();
			mTailController->execute(targetAngle, tailEncoderValue);
		}
		int rightPwm = 0;
		int leftPwm  = 0;
		calculatePwm(runset, runPID, rightPwm, leftPwm);
		mRightMotorDriver->setPWM(rightPwm);
		mLeftMotorDriver->setPWM( leftPwm);
	}

	void Run::setInvertedPendulumBalancer(InvertedPendulumBalancer* invertedPendulumBalancer)
	{
		mInvertedPendulumBalancer = invertedPendulumBalancer;
	}

	void Run::setTailController(TailController* tailController)
	{
		mTailController = tailController;
	}

	void Run::setRightMotorDriver(Driver::MotorDriver* rightMotorDriver)
	{
		mRightMotorDriver = rightMotorDriver;
	}
	
	void Run::setLeftMotorDriver(Driver::MotorDriver* leftMotorDriver)
	{
		mLeftMotorDriver = leftMotorDriver;
	}

	void Run::setCourseInformation(Information::CourseInformation* courseInformation)
	{
		mCourseInformation = courseInformation;
	}

	void Run::setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation)
	{
		mCurrentDeviceInformation = currentDeviceInformation;
	}

	void Run::setRunCorrectionInformation(Information::RunCorrectionInformation* runCorrectionInformation)
	{
		mRunCorrectionInformation = runCorrectionInformation;
	}

	void Run::setTailAngleInformation(Information::TailAngleInformation* tailAngleInformation)
	{
		mTailAngleInformation = tailAngleInformation;
	}

	void clipPwm(int& pwm)
	{
		if(     pwm < -100) { pwm = -100; }
		else if(pwm >  100) { pwm =  100; }
	}
	
	void Run::calculatePwm(RunSet* runset, PID* runPID, int& rightPwm, int& leftPwm)
	{
		int forward = runset->getForward();
		int turn    = 0;
		switch(runset->getTurnSelectionType())
		{
			case eUseSpecifiedValue:
				turn = runset->getTurn();
				break;
			case eCalculateToTraceLine:
				{
					double valueCurrent =  mCurrentDeviceInformation->getBrightness();
					double valueTarget  = (mCourseInformation->getBlackValue() + mCourseInformation->getWhiteValue()) / 2 + runset->getTargetColorOffset();
					turn = runPID->execute(valueCurrent, valueTarget);
				}
				break;
			default:
				break;
		}
		if(runset->getIsInvertedPendulumControlEnable())
		{
			int gyroAnglerVelocity_dps = mCurrentDeviceInformation->getGyroAnglerVelocity_dps();
			int rightMotorCount_deg    = mCurrentDeviceInformation->getRightMotorCount_deg();
			int leftMotorCount_deg     = mCurrentDeviceInformation->getLeftMotorCount_deg();
			int standardVoltage_mV     = mRunCorrectionInformation->getStandardVoltage_mV();
			mInvertedPendulumBalancer->setCommand(forward, turn);
			mInvertedPendulumBalancer->update(gyroAnglerVelocity_dps, rightMotorCount_deg, leftMotorCount_deg, standardVoltage_mV);
			rightPwm = mInvertedPendulumBalancer->getPwmRight();
			leftPwm  = mInvertedPendulumBalancer->getPwmLeft();
		}
		else
		{
			rightPwm = forward + turn / 2;
			leftPwm  = forward - turn / 2;
		}
		if(runset->getIsStraightCorrectionEnable())
		{
			rightPwm *= mRunCorrectionInformation->getCoefficientForRightMotorPwm();
			leftPwm  *= mRunCorrectionInformation->getCoefficientForLeftMotorPwm();
		}
		int standardVoltage_mV = mRunCorrectionInformation->getStandardVoltage_mV();
		int voltage_mV         = mCurrentDeviceInformation->getVoltage_mV();
		rightPwm = rightPwm * standardVoltage_mV / voltage_mV;
		leftPwm  = leftPwm  * standardVoltage_mV / voltage_mV;
		clipPwm(rightPwm);
		clipPwm(leftPwm);
	}
}  // namespace Run
