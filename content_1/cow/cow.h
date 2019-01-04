//cow.h
#ifndef COW_H_
#define COW_H_

class Cow
{
private:
	char name[20];
	char * hobby;
	double weight;
public:
	Cow();
	Cow(const char * nm, const char * hb, double wt);
	Cow(const Cow & c);
	~Cow();
	Cow & operator=(const Cow & c);
	void show();			//display all Cow data
};

#endif