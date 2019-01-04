//brass.h -- bank account classes
#ifndef BRASS_H_
#define BRASS_H_
#include <string>
using std::string;

class Brass
{
private:
	string fullName;
	long acctNum;
	double balance;
public:
	Brass(const string & fn = "none", long an = 0, double b = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt);
	double Balance() const; 
	virtual void ViewAcct() const;
	virtual ~Brass(){}
};

//brass pluss account class
class BrassPlus : public Brass
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const string & fn = "none", long an = 0, double b = 0.0,
		double ml = 500, double r = 0.11125);
	BrassPlus(const Brass & b, double ml = 500, double r = 0.11125);
	virtual void ViewAcct() const;
	virtual void Withdraw(double amt);
	void ResetMax(double ml){maxLoan = ml;}
	void ResetRate(double r){rate = r;}
	void ResetOwes(){owesBank = 0;}
};

#endif