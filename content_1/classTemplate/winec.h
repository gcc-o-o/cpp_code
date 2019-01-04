//winec.h -- a class about wine
//compile with string.cpp
#ifndef WINEC_H_
#define WINEC_h_
#include "pairs.h"
#include "string.h"
#include <valarray>

class Wine
{
private:
	typedef std::valarray<int> ArrayInt;
	typedef Pair<ArrayInt, ArrayInt> PairArray;
	String lable;
	PairArray yearsBottles;
public:
	Wine() : lable("NoneWine"), yearsBottles(ArrayInt(0, 1), ArrayInt(0, 1)) {}
	//initiate lable to l, number of years to y, vintage years to yr[]
	//bottles to bot[]
	Wine(const String  & l, int y, const int yr[], const int bot[])
		: lable(l), yearsBottles(ArrayInt(yr, y), ArrayInt(bot, y)) {}
	//initiate lable to l, number of years to y, creat array objects of length y
	Wine(const String & l, int y) : lable(l), yearsBottles(ArrayInt(y), ArrayInt(y)) {}
	void GetBottles();
	String & Lable() {return lable;}
	int Sum() {return yearsBottles.second().sum();}
	void Show();
};

#endif
