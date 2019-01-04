//movetest.cpp
#include "move.h"

int main(void)
{
	Move a;
	Move b{3, 3};
	Move c;
	a.reset(1,1);
	a.showmove();
	b.showmove();
	c=a.moveadd(b);
	c.showmove();
	return 0;
}