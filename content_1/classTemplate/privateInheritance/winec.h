//winec.h -- a class about wine
//compile with string.cpp
#ifndef WINEC_H_
#define WINEC_h_
#include "pairs.h"
#include "string.h"
#include <valarray>

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine : private String, private PairArray
{
public:
	Wine() : String("NoneWine"), PairArray(ArrayInt(0, 1), ArrayInt(0, 1)) {}
	//initiate lable to l, number of years to y, vintage years to yr[]
	//bottles to bot[]
	Wine(const String  & l, int y, const int yr[], const int bot[])
		: String(l), PairArray(ArrayInt(yr, y), ArrayInt(bot, y)) {}
	//initiate lable to l, number of years to y, creat array objects of length y
	Wine(const String & l, int y) : String(l), PairArray(ArrayInt(y), ArrayInt(y)) {}
	void GetBottles();
	const String & Lable() {return (const String &) * this;}
	int Sum() {return ((PairArray &)* this).second().sum();}
	void Show();
};

#endif
