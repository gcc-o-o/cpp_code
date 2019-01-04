//queueTest.cpp -- using a queue that has nested class
//compile with string.cpp
#include <iostream>

#include "queuetp.h"
#include "string.h"

int main(void)
{
	using std::cin;
	using std::cout;
	
	Queue<String> cs(5);
	String temp;
	
	while (! cs.isFull())
	{
		cout << "Please enter your name,"
				"you will be served in order of arrival.\n"
				"Name: ";
		getline(cin, temp);
		cs.enQueue(temp);
	}
	cout << "The queue is full, processing begains:\n"; 
	
	while (! cs.isEmpty())
	{
		cs.deQueue(temp);
		cout << "Now processing " << temp << " ...\n";
	}
	return 0;
}

