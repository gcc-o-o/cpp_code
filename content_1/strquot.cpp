#include<iostream>
#include<string>

using namespace std;

string & version1(string & str1, const string & str2);
void version2(const int & ir);

int main(void)
{
	cout<<"enter a string "<<endl;
	string input, result;
	getline(cin, input);
	version1(input, "@@@@");
	cout<<"input : "<<input<<endl;
	int data;
	cout<<"enter a integer : ";
	cin>>data;
	version2( 1 );
	cout<<endl<<"data : "<<data<<endl;
	return 0;
}


string & version1(string & str1, const string & str2)
{
	str1=str1+str2+str1;
	return str1;
}

void version2(const int & ir)
{
	;
}