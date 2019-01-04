#include<iostream>

const int ArrSize=10;

int main(void)
{
	using namespace std;
	double donation[ArrSize];
	double sum=0;
	cout<<"enter up to 10 values"<<endl;
	int i=0;
	int count=0;
	int average=0;
	while (i<ArrSize&&cin>>donation[i])
	{
		sum+=donation[i];
		i++;
	}
	cout<<"value num: "<<i<<endl
	<<"average: "<<(average=sum/i)<<endl
	<<"big than average: "<<endl;
	for (int j=0; j<i; j++)
	{
		if (average<donation[j])
			cout<<donation[j]<<" ";
	}
	cout<<endl;
	char a;
	cin.get(a);
	return 0;
}