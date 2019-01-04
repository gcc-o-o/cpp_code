//stack.h class definition for stack abstrat data type

#ifndef STACK_H_
#define STACK_H_

typedef long Item;

class Stack
{
private:
	enum {MAX=10};
	Item items[MAX];
	int top;
public:
	Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(Item &it);
	bool pop(Item &it);
};

#endif