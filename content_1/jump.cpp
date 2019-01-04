#include<iostream>

int main(void)
{
	using namespace std;
	const int ArrSize=20;
	int space=0;
	char ch[ArrSize];
	cout<<"enter some charactors "<<endl;
	cin.get(ch,ArrSize);
	for (int i=0; ch[i]!='\0'; i++)
	{
		cout<<ch[i];
		if (ch[i] == '.')
			break;
		if (ch[i] != ' ')
			continue;
		space++;
	}
	cout<<endl<<"space : "<<space<<endl;
	return 0;
}