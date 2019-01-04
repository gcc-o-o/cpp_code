//textin3.cpp read chars to end of file

#include<iostream>
#include<stdio.h>

int main(void)
{
	using namespace std;
	char ch;
	int count=0;
	cout<<"enter some characters"<<endl;
	cin.get(ch);
	while(cin.fail()==false)
	{
		//if(ch!='\n')
		{
			cout<<ch;
			count+=1;
			cin.get(ch);
		}
/*
		else
		{
			//cout<<endl<<" in else ";
			cin.get(ch);
		}
*/
	}
	cout<<endl<<count<<" characters read"<<endl;
	return 0;
}