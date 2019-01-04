// stock20.h Stock class interface
// version 20
#ifndef _STOCK20_H_
#define _STOCK20_H_	
#include <string>
class Stock
{
private:
	std::string company;
	long shares;
	double share_val;
	double total_val;
	void set_tot();
	//inline void set_tot(){total_val = share_val * shares;};
public:
	Stock();		//default constructor
	Stock(const std::string &co, long n, double pr);
	~Stock();		//noisy destructor
	void buying(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show() const;
	const Stock & thebigger(const Stock &obj) const;
};

inline void Stock::set_tot()
{
	total_val=shares*share_val;
}

#endif