//saying.cpp -- using expanded String class
//compile with string.cpp
#include <iostream>
#include "string.h"
using std::cout;
using std::cin;
using std::endl;

int main()
{
	const static int ArSize = 10;
	String sayings[ArSize];
	String name;
	cout << "what is your name\n";
	cin >> name;
	cout << name << " please enter up to " << ArSize
	<< " short sayings, empty line to quit\n";
	int total;
	for (total = 0; total < ArSize; total++)
	{
		cin >> sayings[total];	
		if (! cin)
			break;
	}
	if (total)
	{
		cout << "if (total)\n";
		int shortest = 0;
		int first = 0;
		for (int i = 1; i< total; i++)
		{
			cout << "in for\n";
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			cout << "in first\n";
			if (sayings[i] < sayings[first])
				first = i;
			cout << "end for\n";
		}
		cout << "shortest  saying: " << sayings[shortest] << endl
		<< "first alphabetically: " << sayings[first] << endl
		<< "this program used " << String::HowMany() << " String object{s}"
		<< endl;
	}
	else
		cout << "nothing input\n";
	return 0;
}