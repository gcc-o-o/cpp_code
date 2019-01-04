//exc_mean.h -- exception classes for hmean() gmean()
#ifndef EXC_MEAN_H_
#define EXC_MEAN_H_
#include <iostream>

class bad_hmean
{
private:	
	double v1;
	double v2;
public:
	bad_hmean(double a, double b) : v1(a), v2(b)
	{
		std::cout << "bad_hmean created\n";
	}
	void mesg();
	~bad_hmean()
	{
		std::cout << "bad_hmean destroyed\n";
	}
};

class bad_gmean
{
public:
	double v1;
	double v2;
	bad_gmean(double a, double b) : v1(a), v2(b)
	{
		std::cout << "bad_gmean() created\n";
	}
	const char * mesg();
	~bad_gmean()
	{
		std::cout << "bad_gmean() destroyed\n";
	}
};

inline void bad_hmean::mesg()
{
	std::cout << "hmean( " <<  v1 << ", " << v2 << " ); "
	<< "invalid arguments: a = -b.\n";
}

inline const char * bad_gmean::mesg()
{
	return "gmean() arguments should be >= 0\n";
}

#endif