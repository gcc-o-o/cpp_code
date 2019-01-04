//usedma.cpp -- inheritance friends and DMA
//compile with dma.cpp
#include "dma.h"
#include <iostream>

int main(void)
{
	using std::cout;
	using std::endl;

	BaseDMA shirt{"Protablely", 8};
	LackDMA baloon{"red", "Blimpo", 4};
	HasDMA map{"Mercator", "Buffalo Keys", 5};
	cout << "Displaying BaseDMA object\n";
	cout << shirt << endl;
	cout << "Displaying LackDMA object\n";
	cout << baloon << endl;
	cout << "Displaying HasDMA object\n";
	cout << map << endl;
	LackDMA baloon2{baloon};
	cout << "Result of LackDMA copy\n";
	cout << baloon2 << endl;
	HasDMA map2;
	map2 = map;
	cout << "Result of HasDMA assignment\n";
	cout << map2 << endl;
	return 0;
}