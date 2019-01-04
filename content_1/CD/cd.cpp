//cd.cpp
#include <iostream>
#include <cstring>
#include "cd.h"

Cd::Cd(const char * pf, const char * lb, int sl, double pt)
{
	performers = new char [std::strlen(pf) + 1];
	std::strcpy(performers, pf);
	lable = new char [std::strlen(lb) +1];
	std::strcpy(lable, lb);
	selections = sl;
	playtime = pt;
}

Cd::Cd(const Cd & c)
{
	performers = new char [std::strlen(c.performers) + 1];
	std::strcpy(performers, c.performers);
	lable = new char [std::strlen(c.lable) +1];
	std::strcpy(lable, c.lable);
	selections = c.selections;
	playtime = c.playtime;
}

Cd::Cd()
{
	performers = new char [10];
	lable = new char [10];
	std::strcpy(performers, "None");
	std::strcpy(lable, "None");
	selections = 0;
	playtime = 0;
}

Cd::~Cd()
{
	delete [] performers;
	delete [] lable;
}

void Cd::Report() const
{
	using std::cout;
	using std::endl;
	cout << "Performers: " << performers << endl;
	cout << "Lable: " << lable << endl;
	cout << "Selections: " << selections << endl;
	cout << "Playtime: " << playtime << endl;
}

Cd & Cd::operator=(const Cd & c)
{
	if (this == & c)
		return *this;
	delete [] performers;
	delete [] lable;
	performers = new char [std::strlen(c.performers) + 1];
	lable = new char [std::strlen(c.lable) + 1];
	std::strcpy(performers, c.performers);
	std::strcpy(lable, c.lable);
	selections = c.selections;
	playtime = c.playtime;
	return *this;
}
