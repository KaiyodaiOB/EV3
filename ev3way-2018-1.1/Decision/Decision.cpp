//#include "Decision/Decision.h"
#include "Decision.h"
#include "Decision/EComparisonMode.h"
#include "Decision/EDecisionTarget.h"
#include "../Utility/LCDController.h"

namespace Decision
{
	Decision::Decision()
	{
	}

	bool getValue(DecisionSet* decisionSet,
				  Information::DeviceInformation* currentDeviceInformation,
				  Information::RunInformation*    runInformation,
				  double& value,
				  bool&   valueBool)
	{
		bool isValid = true;
		switch(decisionSet->getDecisionTarget())
		{
			case eMileage:
				value = runInformation->getMileage_mm();
				break;
			case eDirection:
				value = runInformation->getDirection_deg();
				break;
			case eMileageAccumulated:
				value = runInformation->getMileageAccumulated_mm();
				break;
			case eDirectionAccumulated:
				value = runInformation->getDirectionAccumulated_deg();
				break;
			case eVelocity:
				value = runInformation->getVelocity_mmps();
				break;
			case eGrayDetectionStatus:
				valueBool = runInformation->getIsGrayDetected();
				break;
			case eGyroAngle:
				value = currentDeviceInformation->getGyroAngle_deg();
				break;
			case eGyroAnglerVelocity:
				value = currentDeviceInformation->getGyroAnglerVelocity_dps();
				break;
			case eSonarDistance:
				value = currentDeviceInformation->getGyroOffset();
				break;
			case eSonarSignal:
				valueBool = currentDeviceInformation->getSonarSignal();
				break;
			case eTouchStatus:
				valueBool = currentDeviceInformation->getIsTouchSensorPressed();
				break;
			case eColorValue:
				value = currentDeviceInformation->getBrightness();
				break;
			case eTailAngle:
				value = currentDeviceInformation->getTailMotorCount_deg();
				break;
			default:
				isValid = false;
				break;
		}
		return isValid;
	}

	bool compare(EComparisonMode comparisonMode, double target, double threshold1, double threshold2, bool& isTargetSuccess)
	{
		bool isValid = true;
		switch(comparisonMode)
		{
			case eLessThanThreshold1:
				isTargetSuccess = (target < threshold1);
				break;
			case eFromThreshold1ToThreshold2:
				isTargetSuccess = (!(target < threshold1) && !(threshold2 < target));
				break;
			case eMoreThanThreshold2:
				isTargetSuccess = (threshold2 < target);
				break;
			case eIsTrue:
			default:
				isValid = false;
				break;
		}
		return isValid;
	}

	bool compare(EComparisonMode comparisonMode, bool target, bool& isTargetSuccess)
	{
		bool isValid = true;
		switch(comparisonMode)
		{
			case eIsTrue:
				isTargetSuccess = (target == true);
				break;
			case eLessThanThreshold1:
			case eFromThreshold1ToThreshold2:
			case eMoreThanThreshold2:
			default:
				isValid = false;
				break;
		}
		return isValid;
	}
	
	bool compare(DecisionSet* decisionSet,double value, bool valueBool, bool& isTargetSuccess)
	{
		bool isValid = true;
		switch(decisionSet->getDecisionTarget())
		{
			case eMileage:
			case eDirection:
			case eMileageAccumulated:
			case eDirectionAccumulated:
			case eVelocity:
			case eGyroAngle:
			case eGyroAnglerVelocity:
			case eSonarDistance:
			case eColorValue:
			case eTailAngle:
				isValid = compare(decisionSet->getComparisonMode(), value, decisionSet->getThreshold1(), decisionSet->getThreshold2(), isTargetSuccess);
				break;
			case eGrayDetectionStatus:
			case eSonarSignal:
			case eTouchStatus:
				isValid = compare(decisionSet->getComparisonMode(), valueBool, isTargetSuccess);
				break;
			default:
				isValid = false;
				break;
		}
		return isValid;
	}

	bool Decision::execute(EFormingCondition formingCondition, std::vector<DecisionSet*>* decisionSets)
	{
		bool isSuccess;
		if(     formingCondition == eMeetAllDicisions)   { isSuccess = true; }
		else if(formingCondition == eMeetSingleDicision) { isSuccess = false; }
		else { return false; }
		for(auto itr = decisionSets->begin(); itr != decisionSets->end(); itr++)
		{
			mLCDController.cascadeString(5, "for loop     ");
			double value   = 0.0;
			bool valueBool = false;
			bool isValid   = true;
			isValid = getValue(*itr, mCurrentDeviceInformation, mRunInformation, value, valueBool);
			if(!isValid) { return false; }
			bool isTargetSuccess = false;
			isValid = compare(*itr, value, valueBool, isTargetSuccess);
			if(!isValid) { return false; }
			if(     formingCondition == eMeetAllDicisions)   { isSuccess &= isTargetSuccess; }
			else if(formingCondition == eMeetSingleDicision) { isSuccess |= isTargetSuccess; }
		}
		mLCDController.cascadeString(5, "Decision     ");
		int valueLCD;
		double valueL = 0.0;
		bool valueBoolL = false;
		auto itrL = decisionSets->begin();
		itrL += 10;
		valueLCD = getValue(*itrL, mCurrentDeviceInformation, mRunInformation, valueL, valueBoolL);
			if (valueL == 1) {
				mLCDController.cascadeString(4, "d touch press = 1");
			}
			else if (valueL == 0) {
				mLCDController.cascadeString(4, "d touch pressg = 0");
			}
			else {
				mLCDController.cascadeString(4, "d touch press = ?");
			}
			
		return isSuccess;
	}

	void Decision::setCurrentDeviceInformation(Information::DeviceInformation* currentDeviceInformation)
	{
		mCurrentDeviceInformation = currentDeviceInformation;
	}
	
	void Decision::setRunInformation(Information::RunInformation* runInformation)
	{
		mRunInformation = runInformation;
	}
}  // namespace Decision
