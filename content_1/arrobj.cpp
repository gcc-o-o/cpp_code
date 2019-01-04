//arrobj.cpp  functions with array and string object

#include <iostream>
#include <string>
#include <array>

const int Sensons=4;
const std::array<std::string, Sensons>Snames={"spring", "summer", "fall", "winter"};

void fill(std::array<double, Sensons> *);
void show(std::array<double, Sensons>);

int main(void)
{
	std::array<double, Sensons> expenses;
	fill(&expenses);
	show(expenses);
	return 0;
}

void fill(std::array<double, Sensons> *expenses)
{
	using namespace std;
	cout<<"enter the expenses"<<endl;
	for (int i=0; i<Sensons; i++)
	{
		cout<<"the expense of "<<Snames[i]<<" : ";
		cin>>(*expenses)[i];
	}
}

void show(std::array<double, Sensons> expenses)
{
	using namespace std;
	for (int i=0; i<Sensons; i++)
	{
		cout<<"the expense of "<<Snames[i]<<" : "<<expenses[i]<<endl;
	}
}
