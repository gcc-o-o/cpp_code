//newexcp.cpp -- test the bad_alloc exception
#include <iostream>
#include <cstdlib>		//for exit(), EXIT_FAILURE
#include <new>				//for the bad_alloc class
using namespace std;

struct Big{
	double stuff[20000];
};

int main(void)
{
	Big * pb;
	try{
		cout << "Trying to get a big block of memory." << endl;
		pb = new Big[10000];
		new Big[10000];
		cout << "Got past the new request." << endl;
	}
	catch(bad_alloc & ba){
		cout << "caught bad_alloc exception." << endl;
		cout << ba.what() << endl;
		exit(EXIT_FAILURE);
	}
	cout << "Memory successfully allocated." << endl;
	pb[0].stuff[0] = 2;
	cout << pb[0].stuff[0] << endl;
	delete [] pb;
	return 0;
}