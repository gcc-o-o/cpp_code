//cd.h
#ifndef CD_H_
#define CD_H_

//base class
class Cd
{
//represents a CD disk
private:
	char * performers;
	char * lable;
	int selections;	//the number of selection
	double playtime;	//playtime  in minutes
public:
	Cd(const char * pf, const char * lb, int sl, double pt);
	Cd(const Cd & c);
	Cd();
	virtual ~Cd();
	virtual void Report() const;		//reports all CD data
	virtual Cd & operator=(const Cd & c);
};

#endif