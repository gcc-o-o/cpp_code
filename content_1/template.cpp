//template1.cpp
#include <iostream>

template <typename T>
void Swap(T &a, T &b);

template<typename T>
void Swap(T *a, T *b, int size);

void show(int a[], int size);

const int SIZE=4;


int main(void)
{
	using namespace std;
	int d1=1;
	int d2=2;
	int a1[SIZE]={1,2,3,4}, a2[SIZE]={5,6,7,8};
	cout<<"original d1 d2 "<<d1<<" , "<<d2<<endl;
	Swap(d1, d2);
	cout<<"swaped "<<d1<<" , "<<d2<<endl;
	cout<<"original a1 a2"<<endl;
	show(a1, SIZE);
	show(a2, SIZE);
	Swap(a1, a2 ,SIZE);
	cout<<"swaped "<<endl;
	show(a1, SIZE);
	show(a2, SIZE);
	return 0;
}


void show(int a[], int size)
{
	using namespace std;
	for (int i=0; i<size; i++)
	{
		cout<<a[i];
	}
	cout<<endl;
}

template <typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

template <typename T>
void Swap(T a[], T b[], int size)
{
	T temp;
	for (int i=0; i<size; i++)
	{
		temp=a[i];
		a[i]=b[i];
		b[i]=temp;
	}
}