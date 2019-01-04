//usestock1.cpp  class Stock constructors and destructor added
#include "stock10.h"
#include <iostream>

int main(void)
{
	Stock stock1("stock1", 1, 1.1);
	stock1.show();
	Stock stock2=Stock("stock2", 2, 2.2);
	stock2.show();
	std::cout<<"assigning stock1 to stock2\n";
	stock2=stock1;
	std::cout<<"show stock1 stock2\n";
	stock1.show();
	stock2.show();
	std::cout<<"stock1 revised\n";
	stock1=Stock();
	stock1.show();
	return 0;
}