#include "Decision/DecisionSet.h"

namespace Decision
{
	DecisionSet::DecisionSet(double threshold1, double threshold2, EDecisionTarget decisionTarget, EComparisonMode comparisonMode) :
		mThreshold1(threshold1), mThreshold2(threshold2), mDecisionTarget(decisionTarget), mComparisonMode(comparisonMode)
	{
	}
	
	void DecisionSet::setThreshold1(double threshold1)
	{
		mThreshold1 = threshold1;
	}

	void DecisionSet::setThreshold2(double threshold2)
	{
		mThreshold2 = threshold2;
	}

	void DecisionSet::setDecisionTarget(EDecisionTarget decisionTarget)
	{
		mDecisionTarget = decisionTarget;
	}

	void DecisionSet::setComparisonMode(EComparisonMode comparisonMode)
	{
		mComparisonMode = comparisonMode;
	}

	double DecisionSet::getThreshold1() const
	{
		return mThreshold1;
	}

	double DecisionSet::getThreshold2() const
	{
		return mThreshold2;
	}

	EDecisionTarget DecisionSet::getDecisionTarget() const
	{
		return mDecisionTarget;
	}

	EComparisonMode DecisionSet::getComparisonMode() const
	{
		return mComparisonMode;
	}
}  // namespace Decision
