//classic.cpp
#include <iostream>
#include <cstring>
#include "classic.h"

Classic::Classic(const char * sg, const char * pf, const char * lb, int sl, double pt)
	: Cd(pf, lb, sl, pt)
{
	songs = new char [std::strlen(sg) + 1];
	std::strcpy(songs, sg);
}

Classic::Classic(const Classic & c)
	: Cd(c)
{
	songs = new char [std::strlen(c.songs) + 1];
	std::strcpy(songs, c.songs);
}

Classic::Classic()
	: Cd()
{
	songs = new char [10];
	std::strcpy(songs, "No songs");
}

Classic::~Classic()
{
	delete [] songs;
}

void Classic::Report() const
{
	this -> Cd::Report();
	std::cout << "Songs: "  << songs << std::endl;
	std::cout << std::endl;
}

Classic & Classic::operator=(const Classic & c)
{
	this -> Cd::operator=(c);
	delete [] songs;
	songs = new char [std::strlen(c.songs) + 1];
	std::strcpy(songs, c.songs);
}