#ifndef RUN_PID_H
#define RUN_PID_H

namespace Run
{
	class PID
	{
	private:
		double mKp;
		double mKi;
		double mKd;
		double mErrorOld;
		double mErrorNew;
		double mIntegral;
		double mTimeSec;

	public:
		PID(double kp = 1.0, double ki = 0.0, double kd = 0.0);
		int execute(double valueCurrent, double valueTarget);
	};
}  // namespace Run
#endif
