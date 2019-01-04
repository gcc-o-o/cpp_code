//bankaccount.h
#include <string>

#ifndef BANKACCOUNT_H_
#define BANKACCOUNT_H_
class BankAccount
{
private:
	std::string name;
	std::string accnum;
	double balance;
public:
	BankAccount(const std::string client, const std::string clientnum, double bal=0.0);
	void show(void) const;
	void deposit(double cash);
	void withdraw(double cash);
};

#endif