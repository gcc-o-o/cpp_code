#include <iostream>
#include <string>

int main(){
	using namespace std;
	char str[30] = "This is c-type string";
	string one("this is one string");	//1th constructor
	cout << one << endl;
	string two(10, 't');		//2th constructor
	cout << two << endl;
	string three(two);		//3th
	cout << three << endl;
	string four();		//4th
	cout << four << endl;
	string five(one, 5);		//5th
	cout << five << endl;
	string six(str, str+9);		//6th
	cout << six << endl;
	string seven(&str[10], &str[19]);
	cout << seven << endl;
	string eight(seven, 3);	//7th
	cout << eight << endl;
	return 0;
}