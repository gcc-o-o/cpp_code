//usetime1.cpp use the second draft of the Time class
//compile usetime1.cpp and mytime1.cpp toghter
#include <iostream>
#include "mytime1.h"

int main()
{
	using std::cout;
	using std::endl;
	Time planning, coding{3, 40}, fixing{3, 50}, total;
	
	cout << "planning"<< endl;
	planning.Show();
	cout << "coding"<< endl;
	coding.Show();
	cout << "fixing" << endl;
	fixing.Show();
	cout << "total"<<endl;
	total = coding.operator+(fixing);
	total.Show();
	Time morefixing{1, 10};
	cout << "morefixing" << endl;
	morefixing.Show();
	cout << "morefixing + fixing" << endl;
	(total = morefixing + fixing).Show();
	return 0;
}