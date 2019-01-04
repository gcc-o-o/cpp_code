//mytime0.h Time class before opetator overloading
#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time
{
public:
	Time();
	Time(int h, int m);
	void AddHr(int h);
	void AddMin(int m);
	void Reset(int h=0, int m=0);
	Time Sum(const Time &t);
	void Show() const;
private:
	int hours;
	int minutes;
};

#endif