#include "RunSet.h"

namespace Run
{
	RunSet::RunSet() :
		mTailAngleType(Information::eResting),
		mTurnSelectionType(eUseSpecifiedValue),
		mIsInvertedPendulumControlEnable(false),
		mIsStraightCorrectionEnable(false),
		mIsTailControlEnable(false),
		mForward(0),
		mTurn(0),
		mTargetColorOffset(0)
	{
	}

	void RunSet::setTailAngleType(Information::ETailAngleType type)
	{
		mTailAngleType = type;
	}
	
	void RunSet::setTurnSelectionType(ETurnSelectionType type)
	{
		mTurnSelectionType = type;
	}

	void RunSet::setIsInvertedPendulumControlEnable(bool isEnable)
	{
		mIsInvertedPendulumControlEnable = isEnable;
	}

	void RunSet::setIsStraightCorrectionEnable(bool isEnable)
	{
		mIsStraightCorrectionEnable = isEnable;
	}

	void RunSet::setIsTailControlEnable(bool isEnable)
	{
		mIsTailControlEnable = isEnable;
	}

	void RunSet::setForward(int forward)
	{
		mForward = forward;
	}

	void RunSet::setTurn(int turn)
	{
		mTurn = turn;
	}

	void RunSet::setTargetColorOffset(int offset)
	{
		mTargetColorOffset = offset;
	}

	Information::ETailAngleType RunSet::getTailAngleType() const
	{
		return mTailAngleType;
	}

	ETurnSelectionType RunSet::getTurnSelectionType() const
	{
		return mTurnSelectionType;
	}

	bool RunSet::getIsInvertedPendulumControlEnable() const
	{
		return mIsInvertedPendulumControlEnable;
	}

	bool RunSet::getIsStraightCorrectionEnable() const
	{
		return mIsStraightCorrectionEnable;
	}

	bool RunSet::getIsTailControlEnable() const
	{
		return mIsTailControlEnable;
	}

	int RunSet::getForward() const
	{
		return mForward;
	}

	int RunSet::getTurn() const
	{
		return mTurn;
	}

	int RunSet::getTargetColorOffset() const
	{
		return mTargetColorOffset;
	}
}  // namespace Run
