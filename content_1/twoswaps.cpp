//twoswap.cpp specialization template Swap()
#include <iostream>

struct job
{
	char name[30];
	double salary;
	int floor;
};

template<typename T>
void Swap(T &a, T &b);

template<>
void Swap<job>(job &a, job &b);

void show(job &a);

int main(void)
{
	int i=1, j=2;
	job a={"a", 1000, 1}, b={"b", 2000, 2};
	std::cout<<"i , j : "<<i<<" , "<<j<<"\n";
	Swap(i, j);
	std::cout<<"swaped\n"<<"i , j : "<<i<<" , "<<j<<"\n";
	show(a);
	show(b);
	Swap(a, b);
	std::cout<<"swaped\n";
	show(a);
	show(b);
	return 0;
}

template<typename T>
void Swap(T &a, T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

template<>			//explicit specialization
void Swap<job>(job &a, job &b)
{
	double s;
	int f;
	s=a.salary;	
	a.salary=b.salary;
	b.salary=s;
	f=a.floor;
	a.floor=b.floor;
	b.floor=f;
}

void show(job &a)
{
	using namespace std;
	cout<<"name: \t"<<a.name<<endl
	<<"salary: "<<a.salary<<endl
	<<"floor: \t"<<a.floor<<endl;
}