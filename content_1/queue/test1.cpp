#include <iostream>
using std::cout;
class B
{
private:
	int a;
public:
	B() {a = 1;}
};

typedef B Item;

class A
{
private:
	struct node {Item b; node * ptr;};
public:
	A() {}
	void allot();
};

void A::allot()
{
	node * ptr = new node;
	cout << "newed\n";
}

int main()
{
	A a;
	a.allot();
	return 0;
}