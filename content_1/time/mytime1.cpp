//mytime1.cpp implementing Time class methods
#include <iostream>
#include "mytime1.h"

Time::Time()
{
	hours = minutes = 0;
}
	
Time::Time(int h, int m)
{
	hours = h;
	minutes = m;
}

void Time::AddHr(int h)
{
	hours = h;
}

void Time::AddMin(int m)
{
	minutes += m;
	hours +=minutes / 60;
	minutes %= 60;
}

void Time::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}
Time Time::operator+(const Time &t)
{
	Time temp;
	temp.hours = hours + t.hours;
	temp.minutes = minutes + t.minutes;
	temp.hours += temp.minutes / 60;
	temp.minutes %= 60;
	return temp;
}
void Time::Show() const
{
	std::cout << hours << " hours  " << minutes << " minutes" << std::endl;
}