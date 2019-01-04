//vintage.cpp
#include "vintage.h"
#include <cstring>

VintagePort::VintagePort()
	: Port()
{
	nickname = new char [10];
	std::strcpy(nickname, "none");
	year = 0;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y)
	: Port(br, "vintage", b), year{y}
{
	nickname = new char [std::strlen(nn) + 1];
	std::strcpy(nickname, nn);
}

VintagePort::VintagePort(const VintagePort & v)
	: Port(v), year{v.year}
{
	nickname = new char [std::strlen(v.nickname) + 1];
	std::strcpy(nickname, v.nickname);
}

VintagePort & VintagePort::operator=(const VintagePort & v)
{
	if (this == & v)
		return *this;
	Port::operator=(v);
	delete [] nickname;
	nickname = new char [std::strlen(v.nickname) + 1];
	std::strcpy(nickname, v.nickname);
	year = v.year;
	return *this;
}

void VintagePort::Show() const
{
	Port::Show();
	cout << "Nickname: " << nickname << endl
	<< "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & v)
{
	os << (Port &) v;
	os << v.nickname << ", " << v.year;
	return os;
}

