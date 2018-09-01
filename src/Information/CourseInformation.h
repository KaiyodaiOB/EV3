#ifndef INFORMATION_COURSE_INFORMATION_H
#define INFORMATION_COURSE_INFORMATION_H

namespace Information
{
	class CourseInformation
	{
	private:
		int mWhiteValue;
		int mBlackValue;

	public:
		CourseInformation();
		void setWhiteValue(int whiteValue);
		void setBlackValue(int blackValue);
		int getWhiteValue() const;
		int getBlackValue() const;
	};
}  // namespace Information
#endif
