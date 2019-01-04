#include <iostream>
using namespace std;
int main()
{
	unsigned u = 10, u2 = 42;
	int i = 10, i2 = 42;
	cout << u2 - u <<endl
	<< u - u2 <<endl
	<< i2 - i << endl
	<< i - i2 << endl
	<< i - u <<endl
	<< u - i << endl;
}