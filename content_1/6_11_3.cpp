
#include<iostream>

int main(void)
{
	using namespace std;
	cout<<"enter one of the following choices"<<endl
	<<"c) carnivore \t p) pianist"<<endl
	<<"t) tree \t g) game"<<endl;
	char ch;
	cin.get(ch);
	int loop=1;
	while(loop)
	{
	switch (ch)
	{
		case 'c':cout<<"carnivore"; loop=0; break;
		case 'p':cout<<"pianist"; loop=0; break;
		case 't':cout<<"tree"; loop=0; break;
		case 'g':cout<<"game"; loop=0; break;
		default:
			cout<<"default enter one of the following choices"<<endl
			<<"c) carnivore \t p) pianist"<<endl
			<<"t) tree \t g) game"<<endl;
			cin.get();
			cin.get(ch);
	}
	}
	return 0;
}