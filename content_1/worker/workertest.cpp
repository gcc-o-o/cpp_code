//workertest.cpp -- testing worker classes hierarchy
//compile with string.cpp and worker0.cpp
#include "worker0.h"

const int LIM = 4;

int main()
{
	Waiter bob("Bob apple", 314L, 5);
	Singer bev("Beverly Hills", 665L, 3);
	Waiter w_temp;
	Singer s_temp;
	Worker * p[LIM] = {&bob, &bev, &w_temp, &s_temp};
	for (int i = 0; i < LIM; i++)
		p[i] -> Set();
	for (int i = 0; i < LIM; i++)
	{
		p[i]  -> Show();
		std::cout << std::endl;
	}
	return 0;
}

