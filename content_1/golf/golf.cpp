//golf.cpp
#include <iostream>
#include <cstring>
#include "golf.h"

void setgolf(golf &g, char* name, int hc)
{
	std::strcpy(g.fullname, name);
	g.handicap=hc;
}

int setgolf(golf &g)
{
	using std::cin;
	using std::cout;
	using std::endl;
	using std::strlen;
	cout<<"enter fullname: ";
	cin>>g.fullname;
	cout<<"enter handicap: ";
	cin>>g.handicap;
	if (strlen(g.fullname))
		return 1;
	else return 0;
}

void handicap(golf &g, int hc)
{
	g.handicap=hc;
}

void showgolf(const golf &g)
{
	using std::cout;
	using std::endl;
	cout<<g.fullname<<"  "<<g.handicap<<endl;
}