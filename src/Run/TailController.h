#ifndef RUN_TAIL_CONTROLLER_H
#define RUN_TAIL_CONTROLLER_H

#include "Driver/MotorDriver.h"
#include "Run/PID.h"

namespace Run
{
	class TailController
	{
	private:
		Driver::MotorDriver* mTailMotorDriver;
		PID* mPID;

	public:
		TailController();
		void execute(int targetAngle, int tailEncoderValue);
		void setTailMotorDriver(Driver::MotorDriver* tailMotorDriver);
		void setPID(PID* pid);
	};
}  // namespace Run
#endif
