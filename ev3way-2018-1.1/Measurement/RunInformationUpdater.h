#ifndef MEASUREMENT_RUN_INFORMATION_UPDATER_H
#define MEASUREMENT_RUN_INFORMATION_UPDATER_H

#include <vector>
#include "Information/RunInformation.h"
#include "Measurement/iManualMeter.h"

namespace Measurement
{
	class RunInformationUpdater
	{
	private:
		std::vector<iManualMeter*>   mManualMeters;
		Information::RunInformation* mRunInformation;

	public:
		RunInformationUpdater();
		~RunInformationUpdater();
		void initialize();
		void execute();

		void setRunInformation(Information::RunInformation* runInformation);
		void addManualMeter(Measurement::iManualMeter* iManualMeter);
	};

}  // namespace Measurement
#endif
