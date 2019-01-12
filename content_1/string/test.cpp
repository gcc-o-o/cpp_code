//test.cpp
//compile with string.cpp
#include "String.h"
#include <iostream>
using namespace std;
int main()
{
	char ct[10] = "wwwwwwwww";
	cout << "ct: " << ct << endl;
	cout << "Input test!: ";
	cin.get(ct,100);
	cout << ct[0] << endl;
	cout << "ct: " << ct << endl;
	cout << "&ct[2]: " << &ct[2] << endl;
	while (! cin.get(ct,100))
	{
		cout<<"failure ! cin.get(c-type)." << endl;
		cout << "before: " << ct[0] << endl;
		cin.clear();
		cout << "behind: " << ct[0] << endl;
		cout << "ct: " << ct << endl;
		cout << "cin.clear()." << endl;
		while(cin.get()!='\n')
			continue;
	}
	while(cin.get()!='\n')
		continue;
	cout << ct << endl;
	cin.getline(ct,1);
	cout << ct << endl;
	cout << "end" << endl;
	return 0;
}