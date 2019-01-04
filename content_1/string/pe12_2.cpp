//pe12_2.cpp -- test class String
//compile with string.cpp
#include <iostream>
using namespace std;
#include "string.h"

int main()
{
	String s1 = " and i am a c++ student .";
	String s2 = "Please enter your name: ";
	String s3;
	cout << s2;		//overloaded << operator
	cin >> s3;			//overloaded >> operator
	s2 = "My name is " + s3;	//overloaded = , + operator
	cout << s2 << " .\n";
	s2 = s2 + s1;
	s2.StringUp();		//converts string to uppercase
	cout << "The string\n" << s2 << "\ncontains " 
	<< s2.AppearTimes('A') << " 'A' characters in it .\n";
	s1 = "red";		//String(const char *)
				//then String & operator(String &)
	String rgb[3] = {s1, "green", "blue"};
	cout << "Enter the number of a primary color for mixing light: ";
	String ans;
	bool success = false;
	while (cin >> ans)
	{
		ans.StringLow();	//converts string to lowercase
		for (int i = 0; i < 3; i++)
		{
			if (ans == rgb[i])	//overloaded == operator
			{
				cout << "That's right !\n";
				success = true;
				break;
			}
		}
		if (success)
			break;
		else
			cout << "Try again !\n";
	}
	cout << "Bye !\n";
	return 0;
}
