#include <iostream>
#include <cstring>
#include <new>

struct staff
{
	char dross[20];
	int slag;
};
char buffer[sizeof(staff)*2];

int main(void)
{
	staff* ps=new (buffer) staff [2];
	for (int i=0; i<2; i++)
	{
		std::strcpy(ps[i].dross, "test string");
		ps[i].slag=i;
	}
	for (int i=0; i<2; i++)
	{
		std::cout<<ps[i].dross<<" "<<ps[i].slag<<std::endl;
	}
	return 0;
}