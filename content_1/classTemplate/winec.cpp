//winec.cpp -- definition for class Wine
#include "winec.h"
#include <iostream>

void Wine::GetBottles()
{
	int size = yearsBottles.first().size();
	std::cout << "Enter " << lable << " for " << size << " year(s)\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "Enter year: ";
		while (! (std::cin >> yearsBottles.first()[i]))
		{
			while (std::cin.get() != '\n')
				continue;
			std::cout << "Try again\n";
		}
		std::cout << "Enter bottles for that year: ";
		while (! (std::cin >> yearsBottles.second()[i]))
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
	cout << "Wine: " << lable << endl;
	cout.width(10);
	cout << "year";
	cout.width(10);
	cout << "bottle(s)" << endl;
	int size = yearsBottles.first().size();
	for (int i = 0; i < size; i++)
	{
		cout.width(10);
		cout << yearsBottles.first()[i];
		cout.width(10);
		cout << yearsBottles.second()[i] << endl;
	}
}
