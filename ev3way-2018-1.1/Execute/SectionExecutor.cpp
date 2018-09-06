#include "SectionExecutor.h"
#include "../Utility/LCDController.h"

namespace Execute
{
	SectionExecutor::SectionExecutor() :
		mSections()
	{
		mSections = new std::vector<Section*>;
	}
	
	SectionExecutor::~SectionExecutor()
	{
		for(auto itr = mSections->begin(); itr != mSections->end(); itr++)
		{
			delete *itr;
		}
		delete mSections;
	}

	void SectionExecutor::execute()
	{
		mLCDController.cascadeString(3, "section ongoing");
		Section* currentSection = *(mSections->begin());
		currentSection->measure();
		if(currentSection->decide() == true)
		{
			mLCDController.cascadeString(3, "section change");
			mSections->erase(mSections->begin());
			currentSection = *(mSections->begin());
			currentSection->initialize();
		}
		currentSection->run();
	}

	void SectionExecutor::addSection(Section* section)
	{
		mSections->push_back(section);
	}
}  // namespace Execute
