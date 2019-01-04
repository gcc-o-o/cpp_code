//stacktp.h -- a stack template
#ifndef STACKTP_H_
#define STACKTP_H_
template<class Type>
class Stack
{
private:
	enum {MAX = 10};		//constant specific to class
	Type items[MAX];		//hold stack items
	int top;			//index for top stack item
public:
	Stack();
	bool isEmpty();
	bool isFull();
	bool push(const Type & item);	//add item to Stack
	bool pop(Type & item);	//pop top to item
};

template<class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::isEmpty()
{
	return top == 0;
}

template<class Type>
bool Stack<Type>::isFull()
{
	return top == MAX;
}

template<class Type>
bool Stack<Type>::push(const Type & item)
{
	if (isFull())
		return false;
	items[top++] = item;
	return true;
}

template<class Type>
bool Stack<Type>::pop(Type & item)
{
	if (isEmpty())
		return false;
	item = items[--top];
	return true;
}

#endif