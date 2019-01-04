//test1.cpp
#include <iostream>
using namespace std;

class Test
{
private:
	int i = 30;
	int j = 40;
public:
	Test() :i(10), j(20) {}
	Test(int k) :i(k) {}
	void show() {cout << "i: " << i << " j: " << j << endl;}
};

int main()
{
	Test t1;
	t1.show();
	Test t2(2);
	t2.show();
	return 0;
}

