//use_tv.cpp -- using class Tv and class Remote
//compile with tv.cpp
#include "tv.h"
#include <iostream>

int main(void)
{
	using std::cout;
	Tv t4;
	cout << "Initial settings for 4\" TV\n";
	t4.settings();
	t4.onoff();
	t4.chanup();
	cout << "\nAdjusted settings for 4\" TV:\n";
	t4.chanup();
	cout << "\nAdjusted settings for 4\" TV:\n";
	t4.settings();
	
	Remote grey;
	
	grey.set_channel(t4, 10);
	grey.volup(t4);
	grey.volup(t4);
	cout << "\n4\"settings after using remote:\n";
	t4.settings();
	
	Tv t5(Tv::On, 5);
	t5.set_mode();
	grey.set_channel(t5, 5);
	cout << "\n5\"settings:";
	t5.settings();
	grey.chanup(t5);
	cout << "\n5\"settings:";
	t5.settings();
	return 0;
}