//test.cpp -- test class Complex
#include <iostream>
using namespace std;
#include "complex0.h"	//to avoid confusion with <complex.h>

int main()
{
	Complex a{3.0, 4.0};
	Complex c;
	cout << "enter complex number (q to quit) ;\n";
	while (cin >> c)
	{
		cout << "c is " << c << "\n";
		cout << "complex conjugate is " << ~c << "\n";
		cout << "a is " << a << "\n";
		cout << "a + c is " << a + c << "\n"
		<< "a - c is " << a - c << "\n"
		<< "a * c is " << a * c << "\n"
		<< "2 * c is " << 2 * c << "\n"
		<< "enter complex number (q to quit) ;\n";
	}
	cout << "done !\n";
	return 0;
}
