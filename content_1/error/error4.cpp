//error3.cpp -- using exception classes
//compile with string.cpp
#include "exc_mean.h"
#include "string.h"
#include <cmath>
#include <iostream>

class demo
{
private:
	String word;
public:
	demo(const String & s) : word(s) {std::cout << "demo " << word << " created\n";}
	~demo() {std::cout << "demo " << word << " destroyed" << std::endl;}
	void show() const
	{
		std::cout << "demo " << word << " lives!\n";
	}
};

double hmean(double a, double b);
double gmean(double a, double b);
double means(double a, double b);

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	{
	double a, b;
	demo dm("in block in main()");
	cout << "enter two numbers" << endl;
	while (cin >> a >> b)
	{
		try{
			cout << "mean mean of " << a << " and " << b << " is "
			<< means(a, b) << endl;
			cout << "enter next pair" << endl;
		}
		catch(bad_hmean & bh)
		{
			bh.mesg();
			continue;
		}
		catch(bad_gmean & bg)
		{
			cout << bg.mesg();
			cout << "you don't get to play anymore\n";
			break;
			//exit(EXIT_FAILURE);
		}
	}
	dm.show();
	}
	cin.get();
	cin.get();
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
	{
		bad_gmean bg(a, b);
		throw bg;
	}
	return std::sqrt(a * b);
}

double means(double a, double b)
{
	double am, hm ,gm;
	demo mesg(" in means()");
	am = (a + b) / 2.0;		//arithmetic mean
	try{
		hm = hmean(a ,b);
		gm = gmean(a, b);
	}
	catch(bad_hmean & bh)
	{
		bh.mesg();
		std::cout << "caught in means()\n";
		throw;		//rethrow the exception
	}
	mesg.show();
	return (am + hm + gm) / 3.0;	//mean mean
}
