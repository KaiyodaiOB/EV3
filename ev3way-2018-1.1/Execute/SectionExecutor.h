#ifndef EXECUTE_SECTION_EXECUTOR_H
#define EXECUTE_SECTION_EXECUTOR_H

#include "Execute/Section.h"
#include "../Utility/LCDController.h"
#include <vector>

namespace Execute
{
	class SectionExecutor
	{
	private:
		std::vector<Section*>* mSections;
		Utility::LCDController mLCDController;
	public:
		SectionExecutor();
		~SectionExecutor();
		void execute();
		void addSection(Section* section);
	};
}  // namespace Execute
#endif
