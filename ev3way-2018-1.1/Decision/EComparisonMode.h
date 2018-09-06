#ifndef DECISION_E_COMPARISON_MODE_H
#define DECISION_E_COMPARISON_MODE_H

namespace Decision
{
	typedef enum
	{
		eLessThanThreshold1 = 0,
		eFromThreshold1ToThreshold2,
		eMoreThanThreshold2,
		eIsTrue
	} EComparisonMode;
}  // namespace Decision
#endif
