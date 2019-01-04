//usestock1.cpp  class Stock constructors and destructor added
#include "stock20.h"
#include <iostream>

int main(void)
{
	const int size=2;
	Stock stocks[2]{
		Stock("stock1", 1, 1.1),
		Stock("stock2", 2, 2.2),
	};
	for (int i=0; i<size; i++)
		stocks[i].show();
	Stock*top=&stocks[0];
	top->thebigger(stocks[1]).show();
}