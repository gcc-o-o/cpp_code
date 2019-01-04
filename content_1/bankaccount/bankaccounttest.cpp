//bankaccounttest.cpp
#include "bankaccount.h"

int main(void)
{
	BankAccount usera{"usera", "1234", 220};
	usera.show();
	usera.deposit(10);
	usera.show();
	usera.withdraw(20);
	usera.show();
	return 0;
}