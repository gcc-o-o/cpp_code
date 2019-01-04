//useClassic.cpp -- using class Classic
#include <iostream>
using namespace std;
#include "classic.h"		//which will contain #include "cd.h"

void Bravo(const Cd & disk);

int main(void)
{
	Cd c1("Beatles", "Capitol", 14, 35.5);
	Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
		"Alfred Brende", "Philips", 2, 57.17);
	Cd * pcd = & c1;
	cout << "Usiing object directly: \n";
	c1.Report();	//use Cd method
	c2.Report();	//use Classic method

	cout << "Using type Cd * pointer to objects: \n";
	pcd -> Report();	//use Cd method for Cd objects
	pcd = & c2;
	pcd -> Report();	//use Classic method for Classic objects
	
	cout << "Calling a function with a Cd referance argument: \n";                              
	Bravo(c1);
	Bravo(c2);

	cout << "Testing Assigment: \n";
	Classic copy;
	copy = c2;
	copy.Report();
	
	return 0;
}

void Bravo(const Cd & disk)
{
	disk.Report();
}

