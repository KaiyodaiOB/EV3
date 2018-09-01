#include "Decision/EFormingCondition.h"
#include "Execute/Section.h"

namespace Execute
{
	Section::Section() :
		mMeasurement(nullptr),
		mDecision(nullptr),
		mFormingCondition(Decision::eMeetAllDicisions),
		mDecisionSets(),
		mRun(nullptr),
		mRunSet(nullptr),
		mPID(nullptr)
	{
		mDecisionSets = new std::vector<Decision::DecisionSet*>;
	}
	
	Section::~Section()
	{
		for(auto itr = mDecisionSets->begin(); itr != mDecisionSets->end(); itr++)
		{
			delete *itr;
		}
		delete mDecisionSets;
		delete mRunSet;
		delete mPID;
	}

	void Section::measure()
	{
		mMeasurement->execute();
	}

	bool Section::decide()
	{
		return mDecision->execute(mFormingCondition, mDecisionSets);
	}

	void Section::initialize()
	{
		mMeasurement->initialize();
	}

	void Section::run()
	{
		mRun->execute(mRunSet, mPID);
	}
	
	void Section::setMeasurement(Measurement::Measurement* measurement)
	{
		mMeasurement = measurement;
	}

	void Section::setDecision(Decision::Decision* decision)
	{
		mDecision = decision;
	}

	void Section::setFormingCondition(Decision::EFormingCondition formingCondition)
	{
		mFormingCondition = formingCondition;
	}

	void Section::addDecisionSet(Decision::DecisionSet* decisionSet)
	{
		mDecisionSets->push_back(decisionSet);
	}

	void Section::setRun(Run::Run* run)
	{
		mRun = run;
	}

	void Section::setRunSet(Run::RunSet* runSet)
	{
		mRunSet = runSet;
	}

	void Section::setPID(Run::PID* pid)
	{
		mPID = pid;
	}
}  // namespace Execute
