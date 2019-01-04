#include<iostream>

int left(long, int);
char* left(char*, int);


int main(void)
{
	using namespace std;
	long n=123456789;
	char test[]="teststring!!!";
	char* temp;
	for (int i=0; i<10; i++)
	{
		cout<<left(n, i)<<endl;
		cout<<(temp=left(test, i))<<endl;
		delete [] temp;
	}
	return 0;
}

int left(long source, int size)
{
	//std::cout<<"in"<<std::endl;
	int src_size=1;
	long src_cpy=source;
	while (src_cpy /= 10)
	{
		src_size++;
	}
	if (!size || !src_size)
		return 0;
	else if (size>=src_size)
		return source;
	else
	{
		size=src_size-size;
		//std::cout<<"size: "<<size<<"\n"<<"src_size: "<<src_size<<"\n";
		while (size--)
		{
			//std::cout<<size<<" ";
			source /= 10;
		}
	}
	return source;
}

char* left(char* test, int size)
{
	//std::cout<<"in"<<std::endl;
	int count=0;
	if (!size)
		return "NULL";
	char* result=new char [size];
	while (test[count] && size--)
		result[count]=test[count] , count++;
	result[count]='\0';
	return result;
}