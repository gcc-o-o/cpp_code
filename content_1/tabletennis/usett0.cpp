//usett0.cpp - usig the base class
//compile with tabletennis.cpp
#include <iostream>
#include "tabletennis.h"

int main(void)
{
	using std::cout;
	TableTennisPlayer player1 {"chunk", "blizzard", true};
	TableTennisPlayer player2 {"tara", "boomdea", false};
	player1.Name();
	if (player1.HasTable())
		cout << " : has a table .\n";
	else
		cout << ": hasn't a table. \n";
	player2.Name();
	if (player2.HasTable())
		cout << " : has a table";
	else
		cout << " : hasn't a table";
	return 0;
}