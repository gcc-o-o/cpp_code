//complex0.h
#ifndef COMPLEX0_H_
#define COMPLEX0_H_
#include <iostream>
using std::ostream;
using std::istream;
class Complex
{
private:
	double r;		//real part
	double i;		//imaginary part
public:
	Complex(double a, double b){r = a; i = b;}
	Complex(){r = i = 0;}
	~Complex(){}
	Complex operator +(const Complex & c) const;
	Complex operator -(const Complex & c) const;
	Complex operator *(const Complex & c) const;
	friend Complex operator *(double d, Complex & c);
	Complex operator ~() const;
	friend ostream & operator <<(ostream & os, const Complex & c);
	friend istream & operator >>(istream & is, Complex & c);
};	

#endif