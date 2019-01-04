//usenmsp.cpp using name space 
#include <iostream>
#include "namesp.h"

void other(void);
void anther(void);

int main(void)
{
	other();
	anther();
	return 0;
}

void other(void)
{
	using namespace person;
	Person a;
	getPerson(a);
	showPerson(a);
}

void anther(void)
{
	using debt::Debt;
	Debt a;
	debt::getDebt(a);
	debt::showDebt(a);
}