#ifndef INFORMATION_RUN_INFORMATION_H
#define INFORMATION_RUN_INFORMATION_H

namespace Information
{
	class RunInformation
	{
	private:
		double mMileage_mm;
		double mDirection_deg;
		double mMileageAccumulated_mm;
		double mDirectionAccumulated_deg;
		double mVelocity_mmps;
		bool mIsGrayDetected;

	public:
		RunInformation();
		void   setMileage_mm(double mileage_mm);
		double getMileage_mm() const;
		void   setDirection_deg(double direction_deg);
		double getDirection_deg() const;
		void   setMileageAccumulated_mm(double mileageAccumulated_mm);
		double getMileageAccumulated_mm() const;
		void   setDirectionAccumulated_deg(double directionAccumulated_deg);
		double getDirectionAccumulated_deg() const;
		void   setVelocity_mmps(double velocity);
		double getVelocity_mmps() const;
		void setIsGrayDetected(bool isGrayDetected);
		bool getIsGrayDetected() const;
	};
}  // namespace Information
#endif
