//usetime0.cpp use the first draft of the Time class
//compile usetime0.cpp and mytime0.cpp toghter
#include <iostream>
#include "mytime0.h"

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
	total = coding.Sum(fixing);
	total.Show();
	return 0;
}