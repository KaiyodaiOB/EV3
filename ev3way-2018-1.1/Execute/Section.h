#ifndef EXECUTE_SECTION_H
#define EXECUTE_SECTION_H

#include "Decision/Decision.h"
#include "Decision/DecisionSet.h"
#include "Decision/EFormingCondition.h"
#include "Measurement/Measurement.h"
#include "Run/PID.h"
#include "Run/Run.h"
#include "Run/RunSet.h"
#include <vector>

namespace Execute
{
	class Section
	{
	private:
		Measurement::Measurement*   mMeasurement;
		Decision::Decision*         mDecision;
		Decision::EFormingCondition mFormingCondition;
		std::vector<Decision::DecisionSet*>* mDecisionSets;
		Run::Run*    mRun;
		Run::RunSet* mRunSet;
		Run::PID*    mPID;

	public:
		Section();
		~Section();
		void measure();
		bool decide();
		void initialize();
		void run();

		void setMeasurement(Measurement::Measurement* measurement);
		void setDecision(Decision::Decision* decision);
		void setFormingCondition(Decision::EFormingCondition formingCondition);
		void addDecisionSet(Decision::DecisionSet* decisionSet);
		void setRun(Run::Run* run);
		void setRunSet(Run::RunSet* runSet);
		void setPID(Run::PID* pid);
	};
}  // namespace Execute
#endif
