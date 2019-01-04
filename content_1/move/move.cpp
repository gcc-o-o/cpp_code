//move.cpp
#include <iostream>
#include "move.h"

Move::Move(double a, double b)
{
	x=a;
	y=b;
}

void Move::showmove(void) const
{
	std::cout<<"x:"<<x<<"\ty: "<<y<<std::endl;
}

Move Move::moveadd(Move &m) const
{
	Move a;
	a.x=m.x+x;
	a.y=m.y+y;
	return a;
}

void Move::reset(double a, double b)
{
	x=a;
	y=b;
}
