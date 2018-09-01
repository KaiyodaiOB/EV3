#ifndef DECISION_DECISION_H
#define DECISION_DECISION_H

#include "Decision/DecisionSet.h"
#include "Decision/EFormingCondition.h"
#include "Information/DeviceInformation.h"
#include "Information/RunInformation.h"
#include <vector>

namespace Decision
{
	class Decision
	{
	private:
		Information::DeviceInformation* mCurrentDeviceInformation;
		Information::RunInformation*    mRunInformation;

	public:
		Decision();
		bool execute(EFormingCondition formingCondition, std::vector<DecisionSet*>* decisionSets);

		void setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation);
		void setRunInformation(          Information::RunInformation*    runInformation);
	};
}  // namespace Decision
#endif
