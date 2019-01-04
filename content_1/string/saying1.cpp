//saying1.cpp --useing pointer to String class
//compile with string.cpp
#include <iostream>
#include <ctime>		//for time()
#include <cstdlib>		//for srand() rand()
#include "string.h"
using std::cout;
using std::cin;
static const int ArSize = 5;
static const int MaxLen = 100;

String external{"external"};

int main()
{
	String name;
	cout << "what's your name\n";
	cin >> name;
	cout << name << " enter up to " <<ArSize << " short sayings <empty to quit>\n";
	int total;
	String sayings[ArSize];
	char temp[MaxLen];
	for (total = 0; total < ArSize; total++)
	{
		cout << total + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;
		if (! cin || temp[0] == '\0')
			break;
		sayings[total] = temp;
	}
	String * shortest = & sayings[0];
	String * first = & sayings[0];
	if (total > 0)
	{
		for (int i = 1; i < total; i++)
		{
			if (sayings[i].length() < shortest -> length())
				shortest = & sayings[i];
			if (sayings[i] < *first)
				first = & sayings[i];
		}
		cout << "shortest saying: " << *shortest << "\n";
		cout << "first alphabetically: " << *first << "\n";
		srand(time(0));
		int choice = rand() % total;
		String * favorite = new String {sayings[choice]};
		cout << "my favorite saying: " << *favorite << "\n";
		delete favorite;
	}
	else
		cout << "nothing input\n";
	cout << "done !\n";
	return 0;
	cout << "end of main()\n";
}