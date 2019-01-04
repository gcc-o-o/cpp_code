#include<iostream>

int main(void)
{
	using namespace std;
	cout<<"enter characters   enter '#' to quit"<<endl;
	char ch;
	int count=0;
	cin.get(ch);
	while(ch!='#')
	{
		cout<<ch;
		count++;
		cin.get(ch);
	}
	cout<<endl<<count<<" characters read\n";
	char arr[20];
	cin.getline(arr,20);
	cout<<arr;
	return 0;	
}