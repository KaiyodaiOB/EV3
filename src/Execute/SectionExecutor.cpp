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
		std::vector<Section*> tmp;
		tmp.swap(*mSections);
	}

	bool SectionExecutor::execute()
	{
		bool isFinished = false;
		static auto itr = mSections->begin();
		Section* currentSection = *itr;
		currentSection->measure();
		if(currentSection->decide() == true)
		{
			auto next = itr + 1;
			if(next == mSections->end())
			{
				isFinished = true;
				goto RETURN;
			}
			else
			{
				itr++;
				currentSection = *itr;
				currentSection->initialize();
			}
		}
		currentSection->run();
	RETURN:
		return isFinished;
	}

	void SectionExecutor::addSection(Section* section)
	{
		mSections->push_back(section);
	}
}  // namespace Execute
