//stack1.cpp class Stacl member functions
#include "stack1.h"
//using std::cout;

Stack::Stack(int n)
{
	pitems = new Item [n];
	size = n;
	top = 0;
}

Stack::Stack(const Stack & st)
{
	size = st.size;
	top = st.top;
	pitems = new Item[size];
	for (int i = 0; i < size; i++)
	{
		pitems[i] = st.pitems[i];
	}
}

Stack::~Stack()
{
	delete [] pitems;
}

bool Stack::isempty() const
{
	return top == 0;
}

bool Stack::isfull() const
{
	return top == size;
}

bool Stack::push(Item &it)
{
	if (isfull())
		return false;
	else
		pitems[top++] = it;
	return true;
}

bool Stack::pop(Item &it)
{
	if (isempty())
		return false;
	else
		it = pitems[--top];
	return true;
}

Stack & Stack::operator=(const Stack & st)
{
	int i;
	for (i = 0; i < size && i < st.top; i++)
	{
		pitems[i] = st.pitems [i];
	}
	if (size <= st.top)
	{
		top = size;
	}
	else
		top = st.top;
	return *this;
}

ostream & operator<<(ostream & os, const Stack & st)
{
	for (int i = 0; i < st.top; i++)
		os << st.pitems[i];
	cout << "\n";
}