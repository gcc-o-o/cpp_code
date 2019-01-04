//static.cpp using a static local variable
#include <iostream>
using namespace std;
const int ArrSize=10;
void strcount(const char* str);

int main(void)
{
	char input[ArrSize];
	char next;
	cout<<"enter a line"<<endl;
	cin.get(input, ArrSize);
	while (cin)
	{
		cin.get(next);
		while (next != '\n')
		{
			cin.get(next);
		}
		strcount(input);
		cout<<"enter a line"<<endl;
		cin.get(input, ArrSize);
	}
	return 0;
}

void strcount(const char* str)
{
	static int local = 0;
	int count = 0;
	const char* pt=str;
	while(*pt++)
		count++;
	local+=count;
	cout<<"\""<<str<<"\""<<" contains "
	<<count<<" characters\n"
	<<"total "<<local<<" characters"<<endl;
}