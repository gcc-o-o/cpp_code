//usett1.cpp -- using base class and derived class
//compile with tabletenis.cpp
#include <iostream>
#include "tabletennis.h"

int main(void)
{
	using std::cout;
	using std::endl;
	TableTennisPlayer player1 {"Tara", "Boomdea", false};
	RatedPlayer rplayer1 {1140, "Mallory", "Duck", true};
	rplayer1.Name();		//derived object use base method
	if (rplayer1.HasTable())
		cout << " : has a table\n";
	else
		cout << " : hasn't a table \n";
	player1.Name();		//base object use base method
	if (player1.HasTable())
		cout << " : has a table\n";
	else
		cout << " : hasn't a table \n";
	cout << "Name: ";
	rplayer1.Name();
	cout << " , Rating: " << rplayer1.Rating() << endl;
//initial RatedPlayer object using TableTennisPlayer object
	RatedPlayer rplayer2{1212, player1};
	cout << "Name: ";
	rplayer2.Name();;
	cout << " , Rating: " << rplayer2.Rating() << endl;
	
	return 0;;
}