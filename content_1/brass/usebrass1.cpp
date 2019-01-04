//usebrass1.cpp -- using bank account classes
//compile with brass.cpp
#include <iostream>
#include "brass.h"

int main()
{
	using std::cout;
	using std::endl;

	Brass piggy{"porcelot piggy", 381299, 4000.00};
	BrassPlus hoggy{"horatio hoggy", 382288, 3000.00};
	piggy.ViewAcct();
	cout << endl;
	hoggy.ViewAcct();
	cout << endl;
	cout << "Depositing $1000 to hoggy account: \n";
	hoggy.Deposit(1000.0);
	cout << "New balance: $" << hoggy.Balance() << endl;
	cout << "Withdrawing $4200 from the biggy account: \n";
	piggy.Withdraw(4200.0);
	cout << "Withdrawing $4200 from the higgy account: \n";
	hoggy.Withdraw(4200.00);
	hoggy.ViewAcct();
	return 0;
}