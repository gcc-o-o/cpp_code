//acctabc.cpp -- Bank Account classes methods
#include "acctabc.h"
using std::cout;
using std::endl;
using std::ios_base;
using std::string;


//Abstract Base Class
AcctABC::AcctABC(const string & s, long an, double bal)
	: fullName{s}, acctNum{an}, balance{bal}
{

}

void AcctABC::Deposit(double amt)
{
	if (amt < 0)
		cout << "Negative deposit not allowed, "
		<< "deposit is cancelled\n";
	else
		balance += amt;
}

void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

//Abstract Base Class protected methods
AcctABC::Formatting AcctABC::SetFormat() const
{
	//set up ###.## format
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}

void AcctABC::Restore(Formatting & f) const
{
	cout.setf(f.flag);
	cout.precision(f.pr);
}

//Brass Account Class methods
void Brass::Withdraw(double amt)
{
	if (amt < 0)
		cout << "Withdrawal amount must be positive, "
		<< "withdrawal cancellled\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else
		cout << "Withdrawal amount of $" << amt
		<< " exceeds your balance, "
		<< "withdraw cancelled\n";
}

void Brass::ViewAcct() const
{
	Formatting f = SetFormat();
	cout << "Full name: " << FullName() << endl
	<< "Account number: " << AcctNum() << endl
	<< "Balance: $" << Balance() << endl;
	Restore(f);
}

//BrassPlus Account Class methods
BrassPlus::BrassPlus(const string & s, long an, double bal, double ml, double r)
	: AcctABC(s, an, bal), maxLoan{ml}, rate{r}
{}

BrassPlus::BrassPlus(const Brass & b, double ml, double r)
	: AcctABC(b), maxLoan{ml}, rate{r}
{}

void BrassPlus::Withdraw(double amt)
{
	Formatting f = SetFormat();
	if (amt < 0)
		cout << "Withdrawal amount must be positive, "
		<< "withdrawal cancelled\n";
	else if (amt <= Balance())
		AcctABC::Withdraw(amt);
	else if (amt <= Balance() + maxLoan - owesBank)
	{
		double advance = amt - Balance();
		owesBank += advance * (1 + rate);
		cout << "Bank advance: $" << advance << endl;
		cout << "finance charge: $" << advance * rate << endl;
		Deposit(advance);
		AcctABC::Withdraw(amt);
	}
	else
		cout << "Credit limit exceeded, transaction concelled." << endl;
}

void BrassPlus::ViewAcct() const
{
	Formatting f = SetFormat();
	
	cout << "BrassPluss client: "  << FullName() << endl;
	cout << "Account number: " << AcctNum() << endl;
	cout << "Balance: $" << Balance() << endl;
	cout << "Maximum loan: $" << maxLoan << endl;
	cout << "Owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Load rate: " << rate << endl;
	Restore(f);
}
