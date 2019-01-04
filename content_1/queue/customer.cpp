//customer.cpp
#include "customer.h"
#include <ctime>
void Customer::set(int arrive_time) 
{
	std::srand(std::time(0));
	this -> arrive_time = arrive_time;
	process_time = std::rand() % 3 +1;
}