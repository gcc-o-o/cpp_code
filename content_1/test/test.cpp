#include <iostream>

template <typename T>
void Swap(T &a, T &b);

template <typename T>
void Swap(T a[], T b[], int size);

const int size=2;

int main(void)
{
	using namespace std;
	int d1=1, d2=2;
	int a1[size], a2[size];
	Swap(d1, d2);
	Swap(a1, a2, size);
	return 0;
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
	;
}