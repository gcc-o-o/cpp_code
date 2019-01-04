//cutomer.h
#ifndef CUSTOMER_H_
#define CUSTOMER_H_
#include <cstdlib>

class Customer
{
private:
	int arrive_time;		//arrive time for customer
	int process_time;		//processing time for customer
public:
	Customer(){arrive_time = process_time = 0;}
	void set(int arrive_time);			//set arrival time
	int when() const {return arrive_time;}
	int how_long() const {return process_time;}
};

#endif