//test.cpp
//compile with cow.cpp
#include <iostream>
#include "cow.h"
using namespace std;

int main()
{
	Cow user;
	user.show();
	char name[20];
	char hobby[20];
	double weight;
	cout << "name: ";
	cin >> name;
	cout << "\nhobby: ";
	cin >> hobby;
	cout << "\nweight: ";
	cin >> weight;
	cout << "\nshow user1\n";	
	Cow user1(name, hobby ,weight);
	//cout << "ceated user1\n";
	user1.show();
	Cow user2;
	cout << "show user2\n";
	user2.show();
	user2 = user1;
	cout << "show user2\n";
	user2.show();
	return 0;	
}