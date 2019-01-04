//worker0.cpp -- working classes methods
//compile with string.cpp
#include <iostream>
#include "worker0.h"
using std::cout;
using std::cin;
using std::endl;

//class Worker methods
Worker::~Worker() {}		//must implement virtual destructor, even if pure

void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin, fullname);
	cout << "Enter employee id: ";
	cin >> id;
	while (cin && cin.get() != '\n')
		continue;
}

void Worker::Show() const
{
	cout << "Worker's name: " << fullname << endl
	<< "Employee id: " << id << endl;
}

//class Waiter methods
void Waiter::Set()
{
	Worker::Set();
	cout << "Enter waiter's panache rating: ";
	cin >> panache;
	while (cin && cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout << "Category: waiter" << endl;
	Worker::Show();
	cout << "Panache rating: " << panache << endl;
}

//class Singer methods
const char * Singer::pv[] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
	Worker::Set();
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

void Singer::Show() const
{
	cout << "Category: singer" << endl;
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}