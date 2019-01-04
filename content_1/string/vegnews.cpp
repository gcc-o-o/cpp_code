//vegnews.cpp --using new and delete operator with StringBad class
//compile with stringbad.cpp
#include <iostream>
#include "stringbad.h"
using std::cout;
using std::endl;

void callme1(StringBad & st);		//passed by reference
void callme2(StringBad st);			//passed by value

int main(void)
{
	cout << "main() accessing" << endl;
	{
		cout << "starting an inner block" << endl;
		StringBad headline1 = "headline1";
		StringBad headline2 = "headline2";
		StringBad defaultstr;
		callme1(headline1);
		callme2(headline2);
		cout << "StringBad report = headline1;" << endl;
		StringBad report = headline1;
		cout << "cout << report << endl;" <<endl;
		cout << report << endl;
		cout << "report = headline2;" << endl;
		report = headline2;
		cout << "cout << report << endl;" <<endl;
		cout << report << endl
			<< "exiting main()" << endl;
	}
	cout << "end of main()" << endl;
}

void callme1(StringBad & st)
{
	cout << "string passed by reference" << endl
		<< "\"" << st << "\""<< endl;
}

void callme2(StringBad st)
{
	cout << "string passed by value" << endl
		<< "\"" << st << "\""<< endl;
}