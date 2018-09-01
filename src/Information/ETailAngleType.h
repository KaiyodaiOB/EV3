#ifndef INFORMATION_E_TAIL_ANGLE_TYPE_H
#define INFORMATION_E_TAIL_ANGLE_TYPE_H

namespace Information
{
	typedef enum
	{
		eResting = 0,
		eStartDash,
		eInvertedPendulumRunning,
		e3PointGroundedRunning,
		ePassUnderGate,
		eNumETailAngleType
	} ETailAngleType;
}  // namespace Information
#endif
