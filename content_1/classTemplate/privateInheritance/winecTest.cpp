//winecTest.cpp -- using Wine class with containment
//compile with string.cpp and winec.cpp
#include "winec.h"
#include "string.h"

int main(void)
{
	using std::cin;
	using std::cout;
	using std::endl;
	
	cout << "Enter name of wine: ";
	String lable;
	cin >> lable;
	cout << "Enter number of years: ";
	int years;
	cin >> years;
	Wine holding(lable, years);	//store lable, years  given arrays years elements
	holding.GetBottles();		//solicit input for year, bottle count
	holding.Show();		//display object contents

	const int YRS = 3;
	int y[YRS] = {1993, 1995, 1998};
	int b[YRS] = {49, 69, 70};
	//create  new object initiate using data in arrays y and b
	Wine more("Grushing Grape Red", YRS, y, b);
	more.Show();
	cout << "Total bottles for " << more.Lable() << " : " << more.Sum() << endl;
	cout << "Bye\n";
	return 0;
}