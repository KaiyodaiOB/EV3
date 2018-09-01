#include "SectionExecutor.h"

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
		Section* currentSection = *(mSections->begin());
		currentSection->measure();
		if(currentSection->decide() == true)
		{
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
