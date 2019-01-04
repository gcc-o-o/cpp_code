//bankaccount.cpp
#include <iostream>
#include "bankaccount.h"

BankAccount::BankAccount(const std::string client, const std::string clientnum, double bal)
{
	name=client;
	accnum=clientnum;
	balance=bal;
}

void BankAccount::show(void) const
{
	std::cout<<"user name: "<<name<<std::endl
	<<"account number: "<<accnum<<std::endl
	<<"balance: "<<balance<<std::endl;
}

void BankAccount::deposit(double cash)
{
	if (cash>=0)
		balance+=cash;
}

void BankAccount::withdraw(double cash)
{
	if (cash>=0 && cash <=balance)
		balance-=cash;
}