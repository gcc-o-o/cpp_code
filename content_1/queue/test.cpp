//test.cpp -- test class Queue
//compile with queue.cpp
#include <iostream>
#include "queue.h"
using namespace std;
using namespace std;
int main()
{
	Item i1 {};
	cout << "times: ";
	Queue q{10};
	int times;
	cin >> times;
	for (int i = 0; i < times; i++)
	{
	q.EnQueue(i1);
	}
	return 0;
}