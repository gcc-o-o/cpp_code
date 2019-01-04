//winec.cpp -- definition for class Wine
#include "winec.h"
#include <iostream>

void Wine::GetBottles()
{
	int size = ((PairArray &) * this).first().size();
	std::cout << "Enter " << (const String &) *this << " for " << size << " year(s)\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter year: ";
		while (! (std::cin >> ((PairArray &) * this).first()[i]))
		{
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Try again\n";
		}
		std::cout << "Enter bottles for that year: ";
		while (! (std::cin >> ((PairArray &) * this).second()[i]))
		{
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Try again\n";
		}
	}
}

void Wine::Show()
{
	using std::cout;
	using std::endl;
	cout << "Wine: " << (const String &) *this<< endl;
	cout.width(10);
	cout << "year";
	cout.width(10);
	cout << "bottle(s)" << endl;
	int size = ((PairArray &) * this).first().size();
	for (int i = 0; i < size; i++)
	{
		cout.width(10);
		cout << ((PairArray &) * this).first()[i];
		cout.width(10);
		cout << ((PairArray &) * this).second()[i] << endl;
	}
}
