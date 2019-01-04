//stctpl.h -- modified stack template
#ifndef STCTPL_H_
#define STCTPL_H_

template<class Type>
class Stack
{
private:
	enum {SIZE = 10};		//default stack size
	Type * items;		//hold stack items
	int stackSize;
	int top;			//index for top stack item
public:
	explicit Stack(int s = SIZE) : stackSize(s), top(0) {items = new Type[stackSize];}
	Stack(const Stack & st);
	~Stack() {delete [] items;}
	bool isEmpty() {return top == 0;}
	bool isFull() {return top == stackSize;}
	bool push(const Type & t);	//add item to stack
	bool pop(Type & t);		//pop top to item
	Stack & operator=(const Stack & st);
};

template<class Type>
Stack<Type>::Stack(const Stack & st)
{
	stackSize = st.stackSize;
	top = st.top;
	items = new Type[stackSize];
	for (int i = 0; i < top; i++)
		items[i] = st.items[i];
}

template<class Type>
bool Stack<Type>::push(const Type & t)
{
	if (isFull())
		return false;
	items[top++] = t;
	return true;
}

template<class Type>
bool Stack<Type>::pop(Type & t)
{
	if (isEmpty())
		return false;
	t = items[--top];
	return true;
}

template<class Type>
Stack<Type> & Stack<Type>::operator=(const Stack & st)
{
	if (this == &st)
		return *this;
	stackSize = st.stackSize;
	delete [] items;
	items = new Type[stackSize];
	top = st.top;
	for (int i = 0; i < top; i++)
	{
		items[i] = st.items[i];
	}
	return *this;
}

#endif