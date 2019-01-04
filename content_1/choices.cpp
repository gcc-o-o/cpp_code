//choices.cpp
#include<iostream>

template<class T>
T lesser(T a, T b)
{
	a=a<0?-a:a;
	b=b<0?-b:b;
	return a<b?a:b;
}

int lesser(int a, int b)
{
	return a<b?a:b;
}

template<class T1, class T2>
auto sum(T1 a, T2 b) ->decltype(a+b)
{
	return a+b;
}

int main(void)
{
	using namespace std;
	int i1=1, i2=-2;
	double d1=3.5, d2=-4.5;
	cout<<lesser(i1, i2)
	<<lesser<>(i1,i2)
	<<lesser<double>(i1, i2)
	<<lesser(d1, d2)
	<<lesser<int>(d1, d2)
	<<"\nsum(): "<<sum(i1, d1);
	return 0;
}