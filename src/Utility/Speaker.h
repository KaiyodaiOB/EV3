#ifndef UTILITY_SPEAKER_H
#define UTILITY_SPEAKER_H

#include <cstdint>

namespace Utility
{
	class Speaker
	{
	private:
		uint16_t mFrequency;

	public:
		Speaker();
		void playTone(const int32_t time_msec) const;
	};
}  // namespace Utility
#endif
