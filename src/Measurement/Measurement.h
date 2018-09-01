#ifndef MEASUREMENT_MEASUREMENT_H
#define MEASUREMENT_MEASUREMENT_H

#include "Measurement/RunInformationUpdater.h"
#include "Measurement/DeviceInformationUpdater.h"

namespace Measurement
{
	class Measurement
	{
	private:
		RunInformationUpdater*    mRunInformationUpdater;
		DeviceInformationUpdater* mDeviceInformationUpdater;

	public:
		Measurement();
		~Measurement();
		void initialize();
		void execute();

		void setRunInformationUpdater(   RunInformationUpdater*    runInformationUpdater);
		void setDeviceInformationUpdater(DeviceInformationUpdater* deviceInformationUpdater);
	};
}  // namespace Measurement
#endif
