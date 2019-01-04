//error3.cpp -- using exception classes
#include "exc_mean.h"
#include <cmath>
#include <iostream>

double hmean(double a, double b);
double gmean(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	double a, b;
	while (cin >> a >> b)
	{
		try{
			cout << "harmonic mean of " << a << " and " << b << " is "
			<< hmean(a, b) << endl;
			cout << "geometric mean of " << a << " and " << b << " is "
			<< gmean(a, b) << endl;
		}
		catch(bad_hmean & bh)
		{
			bh.mesg();
			continue;
		}
		catch(bad_gmean & bg)
		{
			cout << bg.mesg();
			break;
		}
	}
	return 0;
}

double hmean(double a, double b)
{
	if (a == -b)
		throw bad_hmean(a, b);
	return 2 * a * b/(a + b);
}

double gmean(double a, double b)
{
	if (a < 0 || b < 0)
		throw bad_gmean(a, b);
	return std::sqrt(a * b);
}
