#include "Speaker.h"
#include "ev3api.h"

namespace Utility {
	Speaker::Speaker() :
		mFrequency(NOTE_G6)
	{
	}
	
	void Speaker::playTone(const int32_t time_msec) const
	{
		ev3_speaker_play_tone(mFrequency, time_msec);
	}
}
