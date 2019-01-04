//stock20.cpp	implementing Stock class
//version 20
#include <iostream>
#include "stock20.h"

Stock::Stock()	//default constructor
{
	std::cout<<"default constructor called\n";
	company="no name";
	shares=0;
	share_val=0.0;
	total_val=0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
	company =co;
	std::cout<<"constructor "<<company<<" called"<<std::endl;
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
	std::cout<<"destructor "<<company<<" called\n";
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

void Stock::show() const
{
	using std::ios_base;
	std::streamsize prec=std::cout.precision(3);	//save preceding precision
	ios_base::fmtflags orig=std::cout.setf(ios_base::fixed, ios_base::floatfield);
	std::cout<<"company: "<<company
	<<"  shares: "<<shares
	<<"  share price: "<<share_val;
	std::cout.precision(2);
	std::cout<<"  total worth: "<<total_val
	<<std::endl;
	std::cout.setf(orig, ios_base::floatfield);
	std::cout.precision(prec);
}

const Stock & Stock::thebigger(const Stock &obj) const
{
	if (obj.total_val < total_val)
		return *this;
	else
		return obj;
}