//arraytp.h -- array class template
#ifndef ARRAYTP_H_
#define ARRAYTP_H_

#include <iostream>
#include <cstdlib>

template<class T, int n>
class Array
{
private:
	T arr[n];
public:
	Array() {}
	Array(const T & t);
	~Array() {}
	virtual T operator[](int i) const;
	virtual T & operator[](int i);
};

template<class T, int n>
Array<T, n>::Array(const T & t)
{
	for (int i = 0; i < n; i++)
		arr[i] = t;
}


template<class T, int n>
T Array<T, n>::operator[](int i) const
{
	if (i < 0 || i > n)
	{
		std::cerr << "Error in array limit " << i
		<< " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return arr[i];
}


template<class T, int n>
T & Array<T, n>::operator[](int i)
{
	if (i < 0 || i > n)
	{
		std::cerr << "Error in array limit " << i
		<< " is out of range\n";
		std::exit(EXIT_FAILURE);
	}
	return arr[i];
}

#endif