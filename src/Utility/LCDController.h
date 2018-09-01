#ifndef UTILITY_LCD_CONTROLLER_H
#define UTILITY_LCD_CONTROLLER_H

#include <cstdint>
#include "ev3api.h"

namespace Utility
{
	class LCDController
	{
	private:
		lcdfont_t  mFont;
		lcdcolor_t mBackgroundColor;

	public:
		LCDController(lcdfont_t font = EV3_FONT_MEDIUM, lcdcolor_t backgroundColor = EV3_LCD_WHITE);
		void cascadeString(const int32_t lineIndex, const char* str) const;
		void resetDisplay() const;
	};
}  // namespace Utility
#endif
