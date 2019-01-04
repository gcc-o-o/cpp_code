//brass.cpp -- bank account class methods
#include <iostream>
#include "brass.h"
using std::cout;
using std::endl;


//format stuff here
typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;
format setFormat();
void restore(format f, precis p);

//Brass methods
Brass::Brass(const string & fn, long an, double b)
: fullName{fn}, acctNum{an}, balance{b}
{}

void Brass::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed\n"
			<<"Deposit cancelled\n";
	else
		balance += amt;
}

void Brass::Withdraw(double amt)
{
	//set up ###.## format
	format initalState = setFormat();
	precis prec = cout.precision(2);
	
	if (amt < 0)
		cout << "Withdrawal amount must be positive\n"
			<< "withdrawal cancelled\n";
	else if (amt > balance)
		cout << "Withdrawal amount of $ " << amt
			<< "exceeds your balance\n"
			<< "Withdrawal cancelled\n";
	else
		balance -= amt;
	restore(initalState, prec);
}

double Brass::Balance() const
{
	return balance;
}

void Brass::ViewAcct() const
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	cout << "client: " << fullName << endl;
	cout << "account number: " << acctNum << endl;
	cout << "balance: " << balance << endl;
	restore(initialState, prec);
}

//BrassPlus methods
BrassPlus::BrassPlus(const string & fn, long an, double b, double ml, double r)
: Brass(fn, an, b), maxLoan{ml}, rate{r}, owesBank{0}
{}

BrassPlus::BrassPlus(const Brass & p, double ml, double r)
:Brass(p), maxLoan{ml}, rate{r}, owesBank{0}		//Brass implicit copy constructor
{}

//redefine how ViewAcct() works
void BrassPlus::ViewAcct() const
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	Brass::ViewAcct();			//display base portion
	cout << "maximum loan: $" << maxLoan << endl;
	cout << "owed to bank: $" << owesBank << endl;
	//set up ###.### format
	cout.precision(3);
	cout << "rate: " << rate << endl;
	restore(initialState, prec);
}

//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{
	//set up ###.## format
	format initialState = setFormat();
	precis prec = cout.precision(2);
	
	double balan = Brass::Balance();
	if (amt <= balan)
		Brass::Withdraw(amt);
	else if (amt <= balan + maxLoan - owesBank)
	{
		double advance = amt - balan;
		owesBank += advance * (1 + rate);
		cout << "bank advance: $" << advance << endl;
		cout << "finance charge: $" << advance * rate << endl;
		Deposit(advance);
		Brass::Withdraw(amt);
	}
	else
		cout << "credit limit exceeded transaction cancelled\n";
	restore(initialState, prec);
}

//format functions
format setFormat()
{
	//set up ###.## format
	return cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
}

void restore(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}