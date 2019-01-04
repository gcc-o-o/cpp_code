//tabletennis.cpp
#include <iostream>
#include "tabletennis.h"

//TableTennisPlayer ,methods
TableTennisPlayer::TableTennisPlayer(const string & fn, const string & ln, bool ht): firstname{fn}, lastname{ln}, hastable{ht}
{
	
}

void TableTennisPlayer::Name() const
{
	std::cout << firstname << " , " << lastname;
}


//RatedPlayer methods
RatedPlayer::RatedPlayer(unsigned int r, const string & fn, const string & ln, bool ht)
: TableTennisPlayer(fn, ln, ht), rating{r}
{

}

RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & ppt)
: rating{r}, TableTennisPlayer(ppt)
{

}



