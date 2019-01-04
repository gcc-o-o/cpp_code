#include<iostream>

int main(void)
{
	using namespace std;
	cout<<"enter the character   '#'to quit"<<endl;
	char input;
	cin>>input;
	int count=0;
	while(input!='#')
	{
		cout<<input;
		count++;
		cin>>input;
		
	}
	cout<<endl<<count<<" charecters read\n";
	char arr[20];
	cin>>arr;
	cout<<arr;
	return 0;
}