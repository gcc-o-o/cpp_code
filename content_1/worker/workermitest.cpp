//workermitest.cpp -- testing multiple inheritance class SingerWaiter
//compile with string.cpp and workermi.cpp
#include "workermi.h"
#include <cstring>

const int SIZE = 5;
void clean()
{
	using std::cin;
	while (cin && cin.get() != '\n')
		continue;
}

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strchr;
	
	Worker * lolas[SIZE];
	int ct;
	for (ct = 0; ct < SIZE; ct++)
	{
		char choice;
		cout << "Enter the employee category:\n"
			<< "w: Waiter\ts: Singer\n"
			<< "t: Singer waiter\tq: quit" << endl;
		cin >> choice;
		while (strchr("wstq", choice) == NULL)
		{
			cout << "Enter the employee category:\n"
				<< "w: Waiter\ts: Singer\n"
				<< "t: Singer waiter\tq: quit" << endl;
			cin >> choice;
		}
		if (choice == 'q')
			break;
		switch (choice)
		{
			case 'w':	lolas[ct] = new Waiter; break;
			case 's':	lolas[ct] = new Singer; break;
			case 't':	lolas[ct] = new SingerWaiter; break;
		}
		clean();
		lolas[ct] -> Set();
	}
	cout << "Here is your staff:\n";
	int i;
	for (i = 0; i < SIZE; i++)
	{
		cout << endl;
		lolas[i] -> Show();
	}
	for (i = 0; i < SIZE; i++)
		delete lolas[i];
	cout << "Done\n";
	return 0;
}