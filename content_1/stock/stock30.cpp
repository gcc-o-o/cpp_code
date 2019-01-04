//stock30.cpp	implementing Stock class
//version 30
#include <cstring>
#include <iostream>
#include "stock30.h"

Stock::Stock(): shares{0}, share_val{0}, total_val{0}		//default constructor
{
	//std::cout<<"default constructor called\n";
	char default_name[20] = "no name";
	company = new char[std::strlen(default_name) + 1];
	std::strcpy(company, default_name);
}

Stock::Stock(const char * co, long n, double pr)
{
	int length = std::strlen(co) +1;
	company = new char[length];
	std::strcpy(company, co);
	
	//std::cout<<"constructor "<<company<<" called"<<std::endl;
	if (n < 0)
	{
		std::cout<< "membr of shares can't be negative"
		<< company << " shares set to 0\n";
		shares = 0;
	}
	else
		shares = n;
	share_val = pr;
	set_tot();
}

Stock::~Stock()
{
	//std::cout<<"destructor "<<company<<" called\n";
	delete [] company;
}

void Stock::buying(long num, double price)
{
	if (num < 0)
	{
		std::cout<< "number of shares purchased can't be negative, "
		<< "transacton aborted.\n";
	}
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void Stock::sell(long num, double price)
{
	if (num < 0)
	{
		std::cout<< "number of shares sold can't be negative, "
		<< "transaction is aborted.\n";
	}
	else if (shares < num)
	{
		std::cout<< "you can't sale more than you have, "
		<<"transaction is aborted.\n";
	}
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void Stock::update(double price)
{
	share_val = price;
	set_tot();
}

std::ostream & operator<<(std::ostream  & os, const Stock & obj)
{
	os << "company: " << obj.company
	<< "\nshares: " << obj.shares
	<< "\nshare value: " << obj.share_val
	<< "\ntotal value: " << obj.total_val << "\n";
}

const Stock & Stock::thebigger(const Stock &obj) const
{
	if (obj.total_val < total_val)
		return *this;
	else
		return obj;
}