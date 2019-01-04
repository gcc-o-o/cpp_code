//dma.cpp -- dma class methods
#include "dma.h"
#include <cstring>

//BaseDMA class methods
BaseDMA::BaseDMA(const char * l, int r)
{
	lable = new char [std::strlen(l) + 1];
	std::strcpy(lable, l);
	rating = r;
}

BaseDMA::BaseDMA(const BaseDMA & b)
{
	lable = new char [std::strlen(b.lable) + 1];
	std::strcpy(lable, b.lable);
	rating = b.rating;
}

BaseDMA::~BaseDMA()
{
	delete [] lable;
}

BaseDMA & BaseDMA::operator=(const BaseDMA & b)
{
	if (this == & b)
		return *this;
	delete [] lable;
	lable = new char [std::strlen(b.lable) + 1];
	std::strcpy(lable, b.lable);
	rating = b.rating;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const BaseDMA & b)
{
	os << "Lable: " << b.lable << std::endl;
	os << "rating: " << b.rating << std::endl;
	return os;
}

//LackDMA class methods
LackDMA::LackDMA(const char * c, const char * l, int r)
	: BaseDMA(l, r)
{
	std::strncpy(color, c, COL_LEN -1);
	color[COL_LEN - 1] = '\0';
}

LackDMA::LackDMA(const char * c, const BaseDMA & b)
	: BaseDMA(b)
{
	std::strncpy(color, c, COL_LEN -1);
	color[COL_LEN - 1] = '\0';
}

std::ostream & operator<<(std::ostream & os, const LackDMA & l)
{
	os << (const BaseDMA &) l;
	os << "color: " << l.color << std::endl;
}

//HasDMA class methods
HasDMA::HasDMA(const char * s, const char * l, int r)
	: BaseDMA(l, r)
{
	style = new char [std::strlen(s) + 1];
	std::strcpy(style, s);
}

HasDMA::HasDMA(const char * s, const BaseDMA & b)
	: BaseDMA(b)
{
	style = new char [std::strlen(s) + 1];
	std::strcpy(style, s);
}

HasDMA::HasDMA(const HasDMA & h)
	: BaseDMA(h)
{
	style = new char [std::strlen(h.style) + 1];
	std::strcpy(style, h.style);
}

HasDMA & HasDMA::operator=(const HasDMA & h)
{
	if (this == & h)
		return *this;
	this -> BaseDMA::operator=(h);
	delete [] style;
	style = new char [std::strlen(h.style) + 1];
	std::strcpy(style, h.style);
	return *this;
}

std::ostream & operator<<(std::ostream & os, const HasDMA & h)
{
	os << (const BaseDMA & ) h;
	os << "style: " << h.style << std::endl;
	return os;
}
