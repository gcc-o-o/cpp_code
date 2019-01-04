//usetime2.cpp using the third draft of Time class
//compile usetime2.cpp and mytime2.cpp toghter
#include <iostream>
#include "mytime2.h"

int main(void)
{
	using std::cout;
	using std::endl;
	
	Time total, weeding{2, 30}, waxing{3, 40}, diff, adjusted;
	
	cout << "total" << endl;
	total.Show();
	cout << "weeding time" << endl;
	weeding.Show();
	cout << "waxing time" << endl;
	waxing.Show();
	cout << "weeding + waxing" << endl;
	total = weeding + waxing;
	total.Show();
	cout << "waxing - weeding" << endl;
	diff = waxing - weeding;
	diff.Show();
	cout << "waxing * 3.2"<< endl;
	adjusted = 3.2 * waxing;
	//adjusted = waxing *3.2;
	adjusted.Show();
	return 0;
}