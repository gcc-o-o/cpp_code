//c-type charr and cpp string class

#include<iostream>
#include<cstring>
#include<string>

int main(void)
{
	using namespace std;
	char charry[20];
	string str;
	cout<<"the length of charry : "<<strlen(charry)<<endl;
	cout<<"the length of str : "<<str.size()<<endl;
	cout<<"enter infor to charry"<<endl;
	cin.getline(charry,20);
	cout<<"you input is : "<<charry<<endl
	<<"length is : "<<strlen(charry)<<endl;
	cout<<"enter infor to str"<<endl;
	getline(cin,str);
	cout<<"your inputer is : "<<str<<endl
	<<"length is : "<<str.size()<<endl;
	return 0;
}