//Benevolent order of programmer port -- BOP port
#ifndef PORT_H_
#define PORT_H_
#include <iostream>
using namespace std;
class Port
{
private:
	char * brand;
	char style[20];	//i.e.tawny, ruby, vintage
	int bottles;
public:
	Port(const char * br = "none", const char * st = "none", int b = 0);
	Port(const Port & p);			//copy constructor
	virtual ~Port() {delete [] brand;}
	Port & operator=(const Port & p);
	Port & operator+=(int b);		//adds b to bottles
	Port & operator-=(int b);		//subtract b from bottles if available
	int BottlesCount() const {return bottles;}
	virtual void Show() const;
	friend ostream & operator<<(ostream & os, const Port & p);
};

#endif

