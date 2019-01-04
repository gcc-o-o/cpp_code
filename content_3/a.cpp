#include <iostream>

class A
{
	int i;	
public:
	A(){}
	virtur void print() {std::cout<<"i="<<i<<std::endl; }
};

class B : public A
{
	virtur void print() {std::cout<< "B::print()\n"}

}

int main()
{
	A a;
	B b;
	a.print();
	b.print();
	return 0;
}