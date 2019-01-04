//stctplTest.cpp -- testing stack template
#include <iostream>
#include <cstdlib>		//for srand() rand()
#include <ctime>		//for time()
#include "stctpl.h"

const int Num = 10;

int main()
{
	std::srand(std::time(0));	//randomize rand()
	std::cout << "Please enter stack size: ";
	int stacksize;
	std::cin >> stacksize;
//create an empty stack with stacksize slots
	Stack<const char *> st(stacksize);
//in basket
	const char * in[Num] = {"1: Hank", "2: Kiki", "3: Bertty", "4: Ian", "5: Mokfgang",
				"6: Portia", "7: Joy", "8: Xaverie", "9: Juan", 
				"10: Misha"};
//out basket
	const char * out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isEmpty())
			st.push(in[nextin++]);
		else if (st.isFull())
			st.pop(out[processed++]);
		else if (std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for (int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;
	std::cout << "Done\n";
	return 0;
}