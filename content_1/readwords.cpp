//readwords.cpp compute words that begin with vowels and begin with consonant and other charactors

#include<iostream>
#include<cstring>

int main(void)
{
	using namespace std;
	cout<<"enter some words 'q' to quit"<<endl;
	int inword=0;
	int wordlength=0;
	int vowel=0;
	int consonant=0;
	int others=0;
	int quit=0;
	char ch;
	while (ch=cin.get())
	{
		if (isalpha(ch))
		{
			inword=1;
			wordlength++;
			switch (ch)
			{
				case 'A':
				case 'a':
				case 'E':
				case 'e':
				case 'I':
				case 'i':
				case 'O':
				case 'o':
				case 'U':
				case 'u':
					if (wordlength==1)
						vowel++;
					break;
				case 'q':
					quit=1;
				default :
					if (wordlength==1)
						consonant++;
			}
		}
		else if (quit&&wordlength==1)
		{
			break;
		}
		else
		{
			others++;
			inword=0;
			wordlength=0;
		}
	}
	cout<<vowel<<"\t word(s) beginning with vowels"<<endl
	<<consonant<<"\t word(s) beginning with consonants"<<endl
	<<others<<"\t others"<<endl;
	return 0;
}