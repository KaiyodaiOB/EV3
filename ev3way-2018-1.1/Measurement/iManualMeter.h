#ifndef MEASUREMENT_I_MANUAL_METER_H
#define MEASUREMENT_I_MANUAL_METER_H

namespace Measurement
{
	class iManualMeter
	{
	public:
		iManualMeter();
		virtual ~iManualMeter();
		virtual void execute() = 0;
	};
}  // namespace Measurement
#endif
