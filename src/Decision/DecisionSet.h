#ifndef DECISION_DECISION_SET_H
#define DECISION_DECISION_SET_H

#include "Decision/EComparisonMode.h"
#include "Decision/EDecisionTarget.h"

namespace Decision
{
	class DecisionSet
	{
	private:
		double mThreshold1;
		double mThreshold2;
		EDecisionTarget mDecisionTarget;
		EComparisonMode mComparisonMode;

	public:
		DecisionSet(double threashold1, double threashold2, EDecisionTarget decisionTarget, EComparisonMode comparisonMode);

		void setThreshold1(double threshold1);
		void setThreshold2(double threshold2);
		void setDecisionTarget(EDecisionTarget decisionTarget);
		void setComparisonMode(EComparisonMode comparisonMode);

		double getThreshold1() const;
		double getThreshold2() const;
		EDecisionTarget getDecisionTarget() const;
		EComparisonMode getComparisonMode() const;
	};
}  // namespace Decision
#endif
