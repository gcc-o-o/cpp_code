//stacker.cpp testing class Stack
//compile with string.cpp
#include <iostream>
#include <cctype>
#include "stacktp.h"
#include "string.h"

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	char ch;
	Stack<String> stack;
	String po;
	cout<<"enter 'A' to add a purchase order \n"
	<<"P to process a po , or Q to quit: ";
	while (cin>>ch && toupper(ch)!='Q')
	{
		while(cin.get() != '\n')
			continue;
		if (! isalpha(ch))
		{
			cout<<'\a';
			continue;
		}
		switch (ch)
		{
			case 'a':
			case 'A':
				if (stack.isFull())
					cout<<"stack is aready full\n";
				else
				{
					cout<<"enter the po num to add: ";
					cin>>po;
					stack.push(po);
				}
				break;
			case 'p':
			case 'P':
				if (stack.isEmpty())
					cout<<"stack is already empty\n";
				else
				{
					stack.pop(po);
					cout<<"po: "<<po<<endl;
				}
				break;
		}
		cout<<"enter 'A' to add a purchase order \n"
		<<"P to process a po , or Q to quit: ";
	}
	cout<<"done"<<endl;
	return 0;
}