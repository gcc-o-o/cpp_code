//stone2.cpp -- testing class Stonewt
//compile with stonewt1.cpp
#include <iostream>
using std::cout;
#include "stonewt1.h"

void display(Stonewt st, int times);

int main()
{
	Stonewt incognito{20.0};
	incognito.show_pds();
	incognito.show_stn();
	cout << "incognito * 3\n";
	incognito = incognito * 3.0;
	incognito.show_pds();
	incognito.show_stn();
}
