//cow.cpp -- implementation for class Cow
#include "cow.h"
#include <cstring>
#include <iostream>

Cow::Cow() :name{"\0"}, hobby{nullptr}, weight{0}
{
	hobby = new char [1];
	hobby[0] = '\0';
}

Cow::Cow(const char * nm, const char * hb, double wt)
{
	std::strcpy(name, nm);
	hobby = new char [std::strlen(hb) + 1];
	std::strcpy(hobby, hb);
	weight = wt;
}

Cow::Cow(const Cow & c)
{
	std::strcpy(name, c.name);
	hobby = new char [std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
}

Cow::~Cow()
{
	delete [] hobby;
}

Cow & Cow::operator=(const Cow & c)
{
	std::strcpy(name, c.name);
	delete [] hobby;
	hobby = new char [std::strlen(c.hobby) + 1];
	std::strcpy(hobby, c.hobby);
	weight = c.weight;
	return *this;
}

void Cow::show()
{
	std::cout << "name: " << name << std::endl
	<< "hobby: " << hobby << std::endl
	<< "weight: " << weight << std::endl;
}