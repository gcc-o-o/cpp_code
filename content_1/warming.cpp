#include <iostream>

extern int warming;
static int a;
extern int a;
using namespace std;
void update(int dg)
{
	warming=dg;
}

void local()
{
	int warming=10;
	cout<<"local warming "<<warming<<endl
	<<"but global warming "<< ::warming<<endl;
}