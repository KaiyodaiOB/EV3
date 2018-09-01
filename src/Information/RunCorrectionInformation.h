#ifndef INFORMATION_RUN_CORRECTION_INFORMATION_H
#define INFORMATION_RUN_CORRECTION_INFORMATION_H

namespace Information
{
	class RunCorrectionInformation
	{
	private:
		const double mCoefficientForRightMotorPwm;
		const double mCoefficientForLeftMotorPwm;
		const int    mStandardVoltage_mV;

	public:
		RunCorrectionInformation(double coefficientForRightMotorPwm = 1.0, double coefficientForLeftMotorPwm = 1.0, int standardVoltage_mV = 7000);
		double getCoefficientForRightMotorPwm() const;
		double getCoefficientForLeftMotorPwm()  const;
		int    getStandardVoltage_mV() const;
	};
}  // namespace Information
#endif
