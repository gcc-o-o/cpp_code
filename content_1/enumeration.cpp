//enumeration.cpp test enumeration syntax
#include <iostream>

class cls
{
private:
	const int month=1;
	enum {month1=1};
public:
	void show();
};

int main(void)
{
	enum color{red, yellow, blue};
	enum class choice{egg, small, large};
	color c1=color(1);
	int i=red+yellow;
	color c2=red;
	std::cout<<c2;
	cls cls1;
	return 0;
}


void cls::show()
{
	std::cout<<std::endl<<month1;
}