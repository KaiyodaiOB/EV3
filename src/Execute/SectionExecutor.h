#ifndef EXECUTE_SECTION_EXECUTOR_H
#define EXECUTE_SECTION_EXECUTOR_H

#include "Execute/Section.h"
#include <vector>

namespace Execute
{
	class SectionExecutor
	{
	private:
		std::vector<Section*>* mSections;

	public:
		SectionExecutor();
		~SectionExecutor();
		bool execute();
		void addSection(Section* section);
	};
}  // namespace Execute
#endif
