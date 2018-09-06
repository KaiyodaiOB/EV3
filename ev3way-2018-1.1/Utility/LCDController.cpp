#include "LCDController.h"

namespace Utility {
	LCDController::LCDController(lcdfont_t font, lcdcolor_t backgroundColor) :
		mFont(font), mBackgroundColor(backgroundColor)
	{
		ev3_lcd_set_font(mFont);
	}
	
	void LCDController::cascadeString(const int32_t lineIndex, const char* str) const
	{
		int32_t fontWidth = 0, fontHeight = 0;
		ev3_font_get_size(mFont, &fontWidth, &fontHeight);
		ev3_lcd_draw_string(str, 0, lineIndex * fontHeight);
	}

	void LCDController::resetDisplay() const
	{
		ev3_lcd_fill_rect(0, 0, EV3_LCD_WIDTH, EV3_LCD_HEIGHT, mBackgroundColor);
	}
}
