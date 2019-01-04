//acctabc.h -- bank account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>

//abstract bass class
class AcctABC
{
private:
	std::string fullName;
	long acctNum;
	double balance;
protected:
	struct Formatting
	{
		std::ios_base::fmtflags flag;
		std::streamsize pr;	
	};
	const std::string & FullName() const {return fullName;}
	long AcctNum() const {return acctNum;}
	Formatting SetFormat() const;
	void Restore(Formatting & f) const;
public:
	AcctABC(const std::string & s = "NulllBody", long an = -1, 
		double bal = 0.0);
	void Deposit(double amt);
	virtual void Withdraw(double amt) =0;		//pure virtual function
	double Balance() const {return balance;}
	virtual void ViewAcct() const =0;		//pure virtual function
	virtual ~AcctABC() {}
};

//Brass Account class
class Brass : public AcctABC
{
public:
	Brass(const std::string & s = "NullBody", long an = -1,
		double bal = 0.0)
		:AcctABC(s, an, bal) {}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass() {}
};

//BrassPlus Account class
class BrassPlus : public AcctABC
{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const std::string & s, long an = -1, double bal = 0.0,
		double ml = 500.0, double r = 0.1);
	BrassPlus(const Brass & b, double ml = 500, double r = 0.1);
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	void ResetMax(double m) {maxLoan = m;}
	void ResetRate(double r) {rate = r;}
	void ResetOwes() {owesBank = 0;}
	virtual ~BrassPlus() {}
};

#endif