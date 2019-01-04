#include <iostream>
using namespace std;
int warming=1;
int a;
void update(int);
void local();

int main(void)
{
	cout<<"global warming "<<warming<<endl;
	update(2);
	cout<<"updating warming "<<warming<<endl;
	local();
	return 0;
}