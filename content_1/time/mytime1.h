//mytime1.h Time class before opetator overloading
#ifndef MYTIME1_H_
#define MYTIME1_H_

class Time
{
public:
	Time();
	Time(int h, int m);
	void AddHr(int h);
	void AddMin(int m);
	void Reset(int h=0, int m=0);
	Time operator+(const Time &t);
	void Show() const;
private:
	int hours;
	int minutes;
};

#endif