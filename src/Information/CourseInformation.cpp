#include "CourseInformation.h"

namespace Information
{
	static const int WHITE_VALUE_DEFAULT = 40;
	static const int BLACK_VALUE_DEFAULT = 0;

	CourseInformation::CourseInformation() :
		mWhiteValue(WHITE_VALUE_DEFAULT),
		mBlackValue(BLACK_VALUE_DEFAULT)
	{
	}

	void CourseInformation::setWhiteValue(int whiteValue)
	{
		mWhiteValue = whiteValue;
	}

	void CourseInformation::setBlackValue(int blackValue)
	{
		mBlackValue = blackValue;
	}

	int CourseInformation::getWhiteValue() const
	{
		return mWhiteValue;
	}

	int CourseInformation::getBlackValue() const
	{
		return mBlackValue;
	}
}  // namespace Information
