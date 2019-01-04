//usestock0.cpp
#include "stock00.h"

int main(void)
{
	Stock fluffy_the_cat;
	fluffy_the_cat.acquire("candy", 1, 1.1);
	fluffy_the_cat.show();
	fluffy_the_cat.buying(2, 2.2);
	fluffy_the_cat.show();
	fluffy_the_cat.sell(1, 2.2);
	fluffy_the_cat.show();
	fluffy_the_cat.update(3.3);
	fluffy_the_cat.show();
	return 0;
}