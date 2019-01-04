#include<iostream>
#include<string>

int main(void)
{
	using namespace std;
	string input;
	cout<<"enter a string"<<endl;
	cin>>input;
	for (int i=input.size()-1; i>=0; i--)
		cout<<input[i];

	return 0;
}