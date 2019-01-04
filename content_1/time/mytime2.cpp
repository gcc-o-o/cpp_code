//mytime2.cpp implementing Time class methods
#include <iostream>
#include "mytime2.h"

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
Time Time::operator+(const Time &t) const
{
	Time temp;
	temp.hours = hours + t.hours;
	temp.minutes = minutes + t.minutes;
	temp.hours += temp.minutes / 60;
	temp.minutes %= 60;
	return temp;
}

Time Time::operator-(const Time &t) const
{
	Time diff;
	long ltime = 0,  rtime = 0;
	ltime = hours * 60 + minutes;
	rtime = t.hours * 60 + t.minutes;
	diff.minutes = (ltime - rtime) % 60;
	diff.hours = (ltime - rtime) / 60;
	return diff;
}

Time Time::operator*(const double mult) const
{
	Time adjusted;
	long total = hours * 60 + minutes;
	total *= mult;
	adjusted.minutes = total % 60;
	adjusted.hours = total / 60;
	return adjusted;
}

Time operator*(const double mult, const Time &t)
{
	Time adjusted;
	long total = t.hours * 60 + t.minutes;
	total *= mult;
	adjusted.minutes = total % 60;
	adjusted.hours = total / 60;
	return adjusted;
}

void Time::Show() const
{
	std::cout << hours << " hours  " << minutes << " minutes" << std::endl;
}