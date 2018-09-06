#ifndef INFORMATION_E_V3_BODY_INFORMATION_H
#define INFORMATION_E_V3_BODY_INFORMATION_H

namespace Information
{
	class EV3BodyInformation
	{
	private:
		const double mWheelDistance_mm;
		const double mWheelDiameter_mm;

	public:
		EV3BodyInformation();
		double getWheelDistance_mm() const;
		double getWheelDiameter_mm() const;
	};
}  // namespace Information
#endif
