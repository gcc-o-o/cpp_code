#include<iostream>

struct test
{
	int a;
	int b;
};

test & f1(test &);

int main(void)
{
	using namespace std;
	test strt {1,1};
	cout<<"strt a: "<<strt.a<<"\tb: "<<strt.b<<endl;
	f1(strt);
	cout<<"strt a: "<<strt.a<<"\tb: "<<strt.b<<endl;
	return 0;
}

test & f1(test & source)
{
	test * temp;
	//temp=new(test);
	*temp=source;
	temp->a++;
	return *temp;
}