#include "Measurement.h"
#include "../Utility/LCDController.h"

namespace Measurement
{
	Measurement::Measurement()
	{
	}

	Measurement::~Measurement()
	{
	}
	
	void Measurement::initialize()
	{
		mRunInformationUpdater->initialize();
	}

	void Measurement::execute()
	{
		mLCDController.cascadeString(4, "measure");
		mDeviceInformationUpdater->execute();
		mRunInformationUpdater->execute();
	}

	void Measurement::setRunInformationUpdater(RunInformationUpdater* runInformationUpdater)
	{
		mRunInformationUpdater = runInformationUpdater;
	}

	void Measurement::setDeviceInformationUpdater(DeviceInformationUpdater* deviceInformationUpdater)
	{
		mDeviceInformationUpdater = deviceInformationUpdater;
	}
}  // namespace Measurement
