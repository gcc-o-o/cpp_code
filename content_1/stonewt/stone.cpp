//stone.cpp -- testing class Stonewt
//compile with stonewt.cpp
#include <iostream>
using std::cout;
#include "stonewt.h"

void display(Stonewt st, int times);

int main()
{
	short size = 1;
	Stonewt incognito = 11;
	Stonewt celebrity {12.12};
	Stonewt detective {13};
	Stonewt present{short(size)};
	cout << "incognito weight \n";
	incognito.show_pds();
	incognito.show_stn();
	cout << "celebrity weight\n";
	celebrity.show_pds();
	cout << "detective weight\n";
	detective.show_pds();
	detective.show_stn();
	cout << "present weight\n";
	present.show_pds();
	present.show_stn();
	cout << "display detective\n";
	display(14 , 2);
	return 0;
}

void display(Stonewt st, int times)
{
	for (int i = 0; i < times; i++)
		st.show_pds(), st.show_stn();
}