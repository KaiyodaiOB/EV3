#include "RunCorrectionInformation.h"

namespace Information
{
	RunCorrectionInformation::RunCorrectionInformation(double coefficientForRightMotorPwm, double coefficientForLeftMotorPwm, int standardVoltage_mV) :
		mCoefficientForRightMotorPwm(coefficientForRightMotorPwm),
		mCoefficientForLeftMotorPwm( coefficientForLeftMotorPwm),
		mStandardVoltage_mV(standardVoltage_mV)
	{
	}

	double RunCorrectionInformation::getCoefficientForRightMotorPwm() const
	{
		return mCoefficientForRightMotorPwm;
	}

	double RunCorrectionInformation::getCoefficientForLeftMotorPwm()  const
	{
		return mCoefficientForLeftMotorPwm;
	}

	int RunCorrectionInformation::getStandardVoltage_mV() const
	{
		return mStandardVoltage_mV;
	}
}  // namespace Information
