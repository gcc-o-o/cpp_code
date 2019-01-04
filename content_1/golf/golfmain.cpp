//golfmain.cpp
#include "golf.h"
golf list[4];

int main(void)
{
	for (int i=0; i<4; i++)
	{
		if ( ! setgolf(list[i]))
			break;
	}
	for (int i=0; i<4; i++)
	{
		showgolf(list[i]);
	}
	return 0;
}