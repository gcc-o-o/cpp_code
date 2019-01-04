//more looping with for

#include<iostream>

const int ArrSize=15;

int main(void)
{
	using namespace std;
	long long factorial[ArrSize]{1,1};
	for (int i=2; i<ArrSize; i++)
		factorial[i]=factorial[i-1]*i;
	for (int i=0; i<ArrSize; i++)
		cout<<factorial[i]<<endl;
	
	return 0;
}