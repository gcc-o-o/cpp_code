#include "worker0.h"

int main()
{
	Waiter a;
	Singer s;
	a.Set();
	s.Show();
	Worker * p[2] = {&a, &s};
	p[0] -> Show();
	p[0] -> Set();

	return 0;
}