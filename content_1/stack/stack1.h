//stack1.h class definition for stack abstrat data type

#ifndef STACK1_H_
#define STACK1_H_
#include <iostream>
using std::ostream;
using std::cout;
typedef long Item;

class Stack
{
private:
	enum {MAX=10};		//constant specific to class
	Item * pitems;		//holds stack items
	int size;			//number of elements
	int top;			//index for top stack items
public:
	Stack(int n = MAX);		//create stack with n elements
	Stack(const Stack & st);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	//push() return false if stack alread is full, true otherwise
	bool push(Item &it);		//push item into stack
	//pop() return false if stack alread is empty true otherwise
	bool pop(Item &it);		//pop top into item
	Stack & operator=(const Stack & st);
	friend ostream & operator<<(ostream & os, const Stack & st);
};

#endif