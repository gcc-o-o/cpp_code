//usebrass2.cpp
//compile with brass.cpp
#include <iostream>
#include "brass.h"
const int CLIENTS = 4;

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	Brass * p_clients[CLIENTS];
	std::string temp;
	long tempnum;
	double tempbal;
	char kind;
	
	for (int i = 0; i < CLIENTS; i++)
	{
		cout << "Enter client's name: ";
		getline(cin, temp);
		cout << "Enter client's account number: ";
		cin >> tempnum;
		cout << "Enter opening balance: $ ";
		cin >> tempbal;
		cout << "Enter 1 Brass Account or "
		<< "2 for BrassPlus Account: ";
		while (cin >> kind && (kind != '1' && kind != '2'))
			cout << "Enter either 1 or 2" << endl;
		if (kind == '1')
			p_clients[i] = new Brass(temp, tempnum, tempbal);
		else
		{
			double tempmax, temprate;
			cout << "Enter the overdraft limit: $ ";
			cin >> tempmax;
			cout << "Enter the interest rate "
			<< "as a decimal fractioin: ";
			cin >> temprate;
			p_clients[i] = new BrassPlus{temp, tempnum, tempbal,
						tempmax, temprate};
		}
		while (cin.get() != '\n')
			continue;
	}
	cout << endl;
	for (int i =  0; i < CLIENTS; i++)
	{
		p_clients[i] -> ViewAcct();
		cout << endl;
	}
	for (int i = 0; i < CLIENTS; i++)
	{
		delete p_clients[i];		// free memory
	}
	cout << "Done \n";
	return 0;
}