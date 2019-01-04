//tempover.cpp template overloading
#include<iostream>

template<typename Type>
void ShowArr(Type a[], int size);

template<typename Type>
void ShowArr(Type* a[], int size);

int main(void)
{
	int a1[4]{1,2,3,4};
	double a2[4]{5,6,7,8};
	double* pa[4];
	for (int i=0; i<4; i++)
		pa[i]=&a2[i];
	ShowArr(a1,4);
	ShowArr(a2,4);
	ShowArr(pa,4);
	return 0;
}

template<typename Type>
void ShowArr(Type a[], int size)
{
	using namespace std;
	cout<<"template A\n";
	for (int i=0; i<size; i++)
		cout<<a[i]<<" , ";
	cout<<endl;
}

template<typename Type>
void ShowArr(Type* a[], int size)
{
	using namespace std;
	cout<<"template B\n";
	for (int i=0; i<size; i++)
		cout<<*a[i]<<" , ";
	cout<<endl;
}