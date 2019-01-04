//tempparm.cpp -- templatea parameter
#include <iostream>
#include "stacktp.h"
template<template<typename T> class Thing>
class Crab
{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab() {}
	//assumes Thing class has push() and pop() members
	bool push(const int & i, const double & d) {return s1.push(i) && s2.push(d);}
	bool pop(int & i, double & d);
};

template<template<typename T> class Thing>
bool Crab<Thing>::pop(int & i, double & d)
{
	return s1.pop(i) && s2.pop(d);
}

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	Crab<Stack> cs;
//Stack must match template <typename T> class Thing
	int ni;
	double nb;
	cout << "Enter int double pairs such 1 1.1 (0 0 to quit)\n";
	while(cin >> ni >> nb && ni >0 && nb >0)
	{
		if(cs.push(ni, nb))
			break;
	}
	int ni1;
	double nb1;
	while(cs.pop(ni1, nb1))
		cout << "ni1: " << ni1 << "\t" << "nb1: " << nb1 << endl;
	return 0;
}