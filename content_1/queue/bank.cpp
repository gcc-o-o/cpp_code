//bank.cpp -- using Queue interface
//compile with queue.cpp customer.cpp
#include <iostream>
#include <cstdlib>			//for srand() rand()
#include <ctime>			//for time()
#include "queue.h"
const int MINUTES_PER_HOUR = 60;

bool newcustomer(double x);			//x is minutes per customer

int main()
{
	using std::cin;
	using std::cout;
	using std::endl;

	Item item;				//new customer temperary data
	long served = 0;			//served customer
	long turnaways = 0;			//turned away by full queue
	int cumulation = 0;			//cumulative customers
	int wait_time = 0;			//time untill auto teller is free

	cout << "case study, bank of automatic teller machine\n";
	cout << "enter the time (hours) of the simulation\n";
	int hours;					//hours of simulation
	cin >> hours;
	long cycles = hours * MINUTES_PER_HOUR;	//number of cycles
	cout << "enter average number of customers per hour\n";
	int perhour;				//customers per hour
	cin >> perhour;
	double min_per_customer = MINUTES_PER_HOUR / perhour;
	cout << "enter the size of the queue\n";
	int qs;					//maximum number of queue
	cin >> qs;
	Queue line(qs);
	std::srand(std::time(0));
	while (cycles > 0)
	{
		if (newcustomer(min_per_customer))
		{
			if (! line.IsFull())
			{
				item.set(cycles);
				line.EnQueue(item);
				cout << line.QueueCount() << " ";
			}
			else
				turnaways++;
			cumulation++;
		}
		if (wait_time <= 0)
		{
			if (! line.IsEmpty())
			{
				line.DeQueue(item);
				wait_time = item.how_long();
				served++;
			}
		}
		wait_time--;
		cycles--;
	}

	//report result
	cout << endl << "served: " << served << endl
	<< "turn aways: " << turnaways << endl
	<< "average number of served customer per hour: " << served / hours << endl
	<< "cumulation: " << cumulation << endl;
	return 0;
}

bool newcustomer(double x)
{
	return (std::rand() * x / RAND_MAX < 1);
}
