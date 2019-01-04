// stock20.h Stock class interface
// version 20
#ifndef _STOCK20_H_
#define _STOCK20_H_
#include <iostream>
class Stock
{
private:
	char * company;
	long shares;
	double share_val;
	double total_val;
	void set_tot();
	//inline void set_tot(){total_val = share_val * shares;};
public:
	Stock();		//default constructor
	Stock(const char * co, long n, double pr);
	~Stock();		//noisy destructor
	void buying(long num, double price);
	void sell(long num, double price);
	void update(double price);
	friend std::ostream & operator<<(std::ostream  & os, const Stock & obj);
	const Stock & thebigger(const Stock &obj) const;
};

inline void Stock::set_tot()
{
	total_val = shares * share_val;
}

#endif