//stonewt1.h -- revised for the Stonewt class and coversion functions added
#ifndef STONEWT1_H_
#define STONEWT1_H_

class Stonewt
{
private:
	enum {PDS_PER_STONE = 14};	//pounds per stone
	int stone;				//whole stones
	double pds_left;			//fractional pounds
	double pounds;			//entire weight in pounds
public:
	Stonewt(double pds);		//constructor for double pounds
	explicit Stonewt(int stn, double pdsl = 0);	//constructor for stone
	explicit Stonewt(long stn);
	explicit Stonewt();			//default constructor
	~Stonewt();
	void show_pds() const;		//show weight in pounds format
	void show_stn() const;		//show weight in stone format
	Stonewt operator*(double d);
//conversion functions
	explicit operator int();
	explicit operator double();
};

#endif