//usetock30.cpp
//compile with stock30.cpp
#include "stock30.h"
using namespace std;
int main()
{
	Stock user1;
	Stock user2{"user2", 10 , 20};
	cout << user1 << user2;
	user1.buying(20, 11.5);
	user2.sell(1, 1.1);
	cout << user1 << user2;
	user2.update(30.33);
	cout << user2;
	return 0;
}