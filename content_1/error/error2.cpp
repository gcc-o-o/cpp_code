//error1.cpp -- using an exception
#include <iostream>

double hmean(double a, double b);

int main(void)
{
	std::cout << "Enter teo numbers: ";
	double x, y, r;
	while (std::cin >> x >> y)
	{
		try{
		r = hmean(x, y);
		}
		catch (const char * s)
		{
			std::cout << s << std::endl;
			std::cout << "Enter next set of numbers <q to quit>: ";
			continue;
		}
		std::cout << "Harmonic mean of " << x << " and " << y
		<< " is " << r << std::endl;
		std::cout << "Enter next set of numbers <q to quit>: ";
	}
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
	{
		throw "Untenable arguments to hmean().";
	}
	return 2.0 * a * b /(a + b);
}
