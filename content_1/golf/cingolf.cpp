#include<iostream>

const int ArrSize=5;

int main(void)
{
	using namespace std;
	cout<<"enter 5 numbers"<<endl;
	int arr[ArrSize];
	int i=0;
	while (i<ArrSize)
	{
		while (!(cin>>arr[i]))
		{
			cin.clear();
			while (cin.get()!='\n')
				continue;
			cout<<"now continue to enter the num"<<endl;
		}
		i++;
	}
	for (int j=0; j<i; j++)
	{
		cout<<arr[j]<<endl;
	}
	return 0;
}