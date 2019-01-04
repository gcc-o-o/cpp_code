//usestack1.cpp
//compile with stack1.cpp
#include <iostream>
#include "stack1.h"

int main()
{
	Item i1 = 1;
	Item i2 = 2;
	Stack stack = 5;
	cout <<stack;
	stack.push(i1);
	cout << stack;
	stack.push(i2);
	cout << stack;
	cout << "i1: " << i1 << "\n";
	stack.pop(i1);
	cout << "i1: " << i1 << "\n";
	cout << stack;
	stack.pop(i2);
	cout << "i2: " << i2 << "\n";
	cout << stack;
	return 0;
}