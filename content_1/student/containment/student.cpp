//student.cpp -- Student class using containment
//compile with string.cpp
#include "student.h"

std::ostream & Student::arr_out(std::ostream & os) const
{
	int i;
	int size = scores.size();
	if (size > 0)
	{
		for (i = 0; i < size; i++)
		{
			os << scores[i] << " ";
			if (i % 6 == 5)
				os << std::endl;
		}
		if (i % 6 == 0)
			os << std::endl;
	}
	else
		os << "Empty array\n";
	return os;
}

double Student::Average() const
{
	if (scores.size() > 0)
		return scores.sum() / scores.size();
	else
		return 0;
}

const String & Student::Name() const
{
	return name;
}

double Student::operator[](int i) const
{
	return scores[i];
}

double & Student::operator[](int i)
{
	return scores[i];
}

//friend method
std::istream & operator>>(std::istream & is, Student & st)
{
	is >> st.name;
	return is;
}

std::istream & getline(std::istream & is, Student & st)
{
	getline(is, st.name);
	return is;
}

std::ostream & operator<<(std::ostream & os, const Student & st)
{
	os << "Scores for " << st.name << std::endl;
	st.arr_out(os);
	return os;
}