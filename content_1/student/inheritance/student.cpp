//student.cpp -- define a student class using private inheritance
#include "student.h"

//private method
std::ostream & Student::arr_out(std::ostream & os) const
{
	int i;
	if (ArrayDb::size() > 0)
	{
		for (int i = 0; i < ArrayDb::size(); i++)
		{
			os << ArrayDb::operator[](i) << " ";
			if (i & 5 == 4)
				os << std::endl;
		}
		if (i % 5 != 0)
			os << std::endl;
	}
	else
		os << "Empty array\n";
}

//public
double Student::Average() const
{
	if (ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else
		return 0;
}

double Student::operator[](int i) const
{
	return ArrayDb::operator[](i);
}

double & Student::operator[](int i)
{
	return ArrayDb::operator[](i);
}

const String & Student::Name() const
{
	return (const String &) *this;
}

std::istream & operator>>(std::istream & is, Student & st)
{
	is >> (String &) st;
	while (is && is.get() != '\n')
		continue;
}

std::istream & getline(std::istream & is, Student & st)
{
	getline(is, (String &) st);
}

std::ostream & operator<<(std::ostream & os, const Student & st)
{
	os << "Scores for " << (const String &) st << " :\n";
	st.arr_out(os);
}