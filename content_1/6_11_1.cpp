//uplow.cpp  get and echo input turn up letter to lower and low letter to upper

#include<iostream>
#include<cctype>


int main(void)
{
	using namespace std;
	char userin;
	cout<<"echo the charactor '@' to terminate"<<endl;
	while ((userin=cin.get())!='@')
	{
		if (isupper(userin))
			userin=tolower(userin);
		else if (islower(userin))
			userin=toupper(userin);
		cout<<userin;
	}
	
 	return 0;
}