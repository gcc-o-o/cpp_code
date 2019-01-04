//stonewt.cpp implementation of class Stonewt
#include <iostream>
using std::cout;
#include "stonewt.h"

Stonewt::Stonewt(double pds)
{
	stone = int (pds) / PDS_PER_STONE;
	pds_left = int (pds) % PDS_PER_STONE + pds - int (pds);
	pounds = pds;
}

Stonewt::Stonewt(int stn, double pdsl)
{
	stone = stn;
	pds_left = pdsl;
	pounds = stone * PDS_PER_STONE + pds_left;
}

Stonewt::Stonewt(long stn){ pounds = stone = pds_left = -1;}

Stonewt::Stonewt()
{
	stone = pds_left = pounds = 0;
}

Stonewt::~Stonewt() {}

void Stonewt::show_pds() const
{
	cout << "pounds " << pounds << "\n";
}

void Stonewt::show_stn() const
{
	cout << "stone " << stone << " pds_left " << pds_left << "\n";
}