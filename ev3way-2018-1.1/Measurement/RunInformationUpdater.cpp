#include "RunInformationUpdater.h"

namespace Measurement
{
	RunInformationUpdater::RunInformationUpdater()
	{
	}

	RunInformationUpdater::~RunInformationUpdater()
	{
		std::vector<iManualMeter*>().swap(mManualMeters);
	}

	void RunInformationUpdater::initialize()
	{
		mRunInformation->setMileage_mm(0);
		mRunInformation->setDirection_deg(0);
	}
	
	void RunInformationUpdater::execute()
	{
		for(auto itr = mManualMeters.begin(); itr != mManualMeters.end(); itr++)
		{
			(*itr)->execute();
		}
	}

	void RunInformationUpdater::setRunInformation(Information::RunInformation* runInformation)
	{
		mRunInformation = runInformation;
	}

	void RunInformationUpdater::addManualMeter(iManualMeter* iManualMeter)
	{
		mManualMeters.push_back(iManualMeter);
	}
}  // namespace Measurement
