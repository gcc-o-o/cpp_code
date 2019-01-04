#include <new>

char buffer1[50];
char buffer2[100];

struct chaff
{
	char dross[20];
	int slag;
};

int main(void)
{
	chaff *p1, *p2;
	int *p3, *p4;
	//regular forms of new
	p1=new chaff;
	p3=new int [10];
	//two forms of placement new
	p2=new (buffer1) chaff;		//place structure to buffer1
	p4=new (buffer2) int [10];		//place int array to buffer2
	return 0;
}