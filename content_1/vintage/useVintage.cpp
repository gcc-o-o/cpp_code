//useVintage.cpp -- use class Port and VintagePort
//compile with port.cpp and vintage.cpp
#include "vintage.h"
const int SIZE = 3;
int main(void)
{
	Port * pvin[SIZE];
	cout << "Input vin information" << endl;
	for (int i = 0; i < SIZE; i++)
	{

		char brand[20];
		char style[20];
		int bottles;
		cout << "Brand: ";
		cin >> brand;
		cout<< "Style: ";
		cin >> style;
		cout << "Bottles: ";
		cin >> bottles;								pvin[i] = new Port(brand, style, bottles);
		cout << "Chose normal vin or vintage type ('1' or '2'): ";
		int chose;
		cin >> chose;
		if (chose == 1)
		{

			cout << "Next one" << endl;
		}
		else if (chose == 2)
		{
			char nickname[20];
			int year;
			cout << "Nickname: ";
			cin >> nickname;
			cout << "Year:";
			cin >> year;
			pvin[i] = new VintagePort(brand, bottles, nickname, year);
		}
		else
		{
			cout << "Error" << endl;
			i--;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		pvin[i] -> Show();
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << *pvin[i] << endl;
	}
	return 0;
}