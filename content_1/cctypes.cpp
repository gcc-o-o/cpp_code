//cctypes.cpp  using ctype.h library

#include<iostream>
#include<cctype>

int main(void)
{
	using namespace std;
	int alphabetic=0;
	int punctuation=0;
	int digit=0;
	int whitespace=0;
	int others=0;
	char ch;
	cout<<"enter some characters to analysis  and type 'EOF' to terminate input \n";
	ch=cin.get();
	while (ch!=EOF)				//test for sentinel
	{
		if (isalpha(ch))
			alphabetic++;
		else if (ispunct(ch))
			punctuation++;
		else if (isdigit(ch))
			digit++;
		else if (isspace(ch))
			whitespace++;
		else
			others++;
		ch=cin.get();
	}
	cout<<alphabetic<<"\t letters \n"
	<<punctuation<<"\t punctuations \n"
	<<digit<<"\t digits \n"
	<<whitespace<<"\t whitespace \n"
	<<others<<"\t others \n";
	return 0;
}