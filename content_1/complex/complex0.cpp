//complex0.cpp -- implementation of class Complex
#include "complex0.h"
using std::cin;
using std::cout;
using namespace std;

Complex Complex::operator +(const Complex & c) const
{
	return Complex(r + c.r, i + c.i);
}


Complex Complex::operator -(const Complex & c) const
{
	return Complex(r - c.r, i - c.i);
}


Complex Complex::operator *(const Complex & c) const
{
	return Complex(r * c.r - i * c.i, r * c.i + i * c.r);
}

Complex operator *(double d, Complex & c)
{
	return Complex(d * c.r, d * c.i);
}

Complex Complex::operator ~() const
{
	return Complex(r, -i);
}
ostream & operator<<(ostream & os, const Complex & c)
{
	os << "( " << c.r << " , " << c.i << "i )";
	return os;
}

istream & operator>>(istream & is, Complex & c)
{
	cout << "real: ";
	is >> c.r;
	if (is)
	{
		cout << "\nimaginary: ";
		is >> c.i;
	}
	return is;
}


