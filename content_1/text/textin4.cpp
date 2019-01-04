//textin4.cpp  read char with cin.get()

#include<iostream>

int main(void)
{
	using namespace std;
	char ch;
	int count=0;
	while((ch=cin.get())!=EOF)
	{
		cout.put(ch);
		count++;
	}
	cout<<endl<<count<<" characters read"<<endl;
	return 0;
}