//placement_new1.cpp -- using new, placement new no delete
#include <iostream>
#include <string>
using namespace std;

const static int BUF = 512;

class Test
{
private:
	string name;
	int num;
public:
	Test(const string & s = "Test", int n = 0)
	{
		name = s;
		num = n;
		cout << name << " constructed\n";
	}
	~Test(){cout << name << " destoryed\n";}
	void show(){cout << name << " , " << num << endl;}
};

int main()
{
	char * ptr = new char [BUF];

	Test * p1 = new (ptr) Test{"p1 in buffer"};
	Test * p2 = new Test {"p2 in heap"};
	
	cout << "constent" << endl;
	p1->show();
	p2->show();
	cout << endl;

	cout << "p1: " << (void *)p1 << "\tp2: " << (void *)p2 << endl;

	Test * p3 = new (ptr) Test {"p3 in buffer"};
	Test * p4 = new Test {"p4 in heap"};


	cout << "p3: " << (void *)p3 << "\tp4: " << (void *)p4 << endl;

	cout << "constent" << endl;
	p1->show();
	p2->show();
	cout << endl;

	delete p2;
	delete p4;

	delete [] ptr;
	return 0;
}
