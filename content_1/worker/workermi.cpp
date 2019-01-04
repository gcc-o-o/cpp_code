//workermi.cpp -- working classes methods
//compile with string.cpp
#include <iostream>
#include "workermi.h"
using std::cout;
using std::cin;
using std::endl;

//class Worker methods
void Worker::Get()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter employee id: ";
	cin >> id;
	while (cin && cin.get() != '\n')
		continue;
}

void Worker::Data() const
{
	cout << "Worker's name: " << fullname << endl
	<< "Employee id: " << id << endl;
}

Worker::~Worker() {}		//must implement virtual destructor, even if pure

void Worker::Set()
{
	Get();
}

void Worker::Show() const
{
	Data();
}

//class Waiter methods
void Waiter::Get()
{
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin && cin.get() != '\n')
		continue;
}

void Waiter::Data() const
{
	cout << "Panache rating: " << panache << endl;
}

void Waiter::Set()
{
	Worker::Get();
	Waiter::Get();
}

void Waiter::Show() const
{
	cout << "Category: waiter" << endl;
	Worker::Data();
	Waiter::Data();
}

//class Singer methods
const char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Get()
{
	cout << "Enter number for singer's vocal range: " << endl;
	int i;
	for (i = 0; i < vtypes; i++)
	{
		cout << i << " " << pv[i] << "  ";
		if (i % 3 == 2)
			cout << endl;
	}	
	if (i % 3 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= vtypes))
		cout << "Please enter a number >= 0 and <" << vtypes << endl;
	while (cin && cin.get() != '\n')
		continue;
}

void Singer::Data() const
{
	cout << "Vocal range: " << pv[voice] << endl;
}

void Singer::Set()
{
	Worker::Get();
	Singer::Get();
}

void Singer::Show() const
{
	cout << "Category: singer" << endl;
	Worker::Data();
	Singer::Data();
}

//class SingerWaiter methods
void SingerWaiter::Set()
{
	Worker::Get();
	Singer::Get();
	Waiter::Get();
}

void SingerWaiter::Show() const
{
	cout << "Category: SingerWaiter" << endl;
	Worker::Data();
	Singer::Data();
	Waiter::Data();
}
