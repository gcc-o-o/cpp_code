//stack.cpp class Stacl member functions
#include "stack.h"

Stack::Stack()
{
	top=0;
}

bool Stack::isempty() const
{
	return top==0;
}

bool Stack::isfull() const
{
	return top==MAX;
}

bool Stack::push(Item &it)
{
	if (isfull())
		return false;
	else
		items[top++]=it;
}

bool Stack::pop(Item &it)
{
	if (isempty())
		return false;
	else
		it=items[--top];
}