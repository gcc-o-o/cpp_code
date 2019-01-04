//error1.cpp -- using the abort() function
#include <iostream>
#include <cstdlib>

double hmean(double a, double b);

int main(void)
{
	std::cout << "Enter teo numbers: ";
	double x, y, r;
	while (std::cin >> x >> y)
	{
		r = hmean(x, y);
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
		std::cout << "untenable arguments to hmean()." << std::endl;
		std::abort();
	}
	return 2.0 * a * b /(a + b);
}
