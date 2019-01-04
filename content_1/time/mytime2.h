//mytime2.h Time class before opetator overloading
#ifndef MYTIME2_H_
#define MYTIME2_H_

class Time
{
public:
	Time();
	Time(int h, int m);
	void AddHr(int h);
	void AddMin(int m);
	void Reset(int h=0, int m=0);
	Time operator+(const Time &t) const;
	Time operator-(const Time &t) const;
	Time operator*(const double mult) const;
//just an example friend function operator*
	friend Time operator*(const double mult, const Time &t);
	void Show() const;
private:
	int hours;
	int minutes;
};

#endif