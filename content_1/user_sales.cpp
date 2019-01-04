//user_sales.cpp
#include "sales.h"

int main(void)
{
	using SALES::Sales;
	using SALES::setSales;
	Sales a, b;
	setSales(a);
	showSales(a);
	double arr[3]{11,22,33};
	setSales(b, arr, 3);
	showSales(b);
	return 0;
}