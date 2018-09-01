#ifndef DECISION_E_DECISION_TARGET_H
#define DECISION_E_DECISION_TARGET_H

namespace Decision
{
	typedef enum
	{
		eMileage = 0,
		eDirection,
		eMileageAccumulated,
		eDirectionAccumulated,
		eVelocity,
		eGrayDetectionStatus,
		eGyroAngle,
		eGyroAnglerVelocity,
		eSonarDistance,
		eSonarSignal,
		eTouchStatus,
		eColorValue,
		eTailAngle
	} EDecisionTarget;
}  // namespace Decision
#endif
