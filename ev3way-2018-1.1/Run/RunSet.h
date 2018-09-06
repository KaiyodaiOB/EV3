#ifndef RUN_RUN_SET_H
#define RUN_RUN_SET_H

#include "Information/ETailAngleType.h"
#include "Run/ETurnSelectionType.h"

namespace Run
{
	class RunSet
	{
	private:
		Information::ETailAngleType mTailAngleType;
		ETurnSelectionType          mTurnSelectionType;
		bool mIsInvertedPendulumControlEnable;
		bool mIsStraightCorrectionEnable;
		bool mIsTailControlEnable;
		int mForward;
		int mTurn;
		int mTargetColorOffset;

	public:
		RunSet();
		void setTailAngleType(Information::ETailAngleType type);
		void setTurnSelectionType(ETurnSelectionType type);
		void setIsInvertedPendulumControlEnable(bool isEnable);
		void setIsStraightCorrectionEnable(bool isEnable);
		void setIsTailControlEnable(bool isEnable);
		void setForward(int forward);
		void setTurn(int turn);
		void setTargetColorOffset(int offset);

		Information::ETailAngleType getTailAngleType() const;
		ETurnSelectionType          getTurnSelectionType() const;
		bool getIsInvertedPendulumControlEnable() const;
		bool getIsStraightCorrectionEnable() const;
		bool getIsTailControlEnable() const;
		int  getForward() const;
		int  getTurn() const;
		int  getTargetColorOffset() const;
	};
}  // namespace Run
#endif
