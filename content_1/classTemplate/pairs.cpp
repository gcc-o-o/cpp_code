//pairs.cpp defining and using a Pair template
//compile with string.cpp
#include <iostream>
#include "string.h"
#include "pairs.h"

int main()
{
	using std::cout;
	using std::endl;
	Pair<String, int> ratings[4] = {
		Pair<String, int>("a", 1),
		Pair<String, int>("b", 2),
		Pair<String, int>("c", 3),
		Pair<String, int>("d", 4)
	};

	int joins = sizeof(ratings) / sizeof(Pair<String, int>);
	cout << "Ratings\tEatery\n";
	for (int i = 0; i < joins; i++)
		cout << ratings[i].second() << "\t" << ratings[i].first()
			<< endl;
	cout << "Oops! Revised ratings\n";
	ratings[3].first() = "revised";
	ratings[3].second() = 11;
	cout << ratings[3].second() << "\t" << ratings[3].first() << endl;
	return 0;
}
