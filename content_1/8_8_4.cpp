//8_8_4.cpp 
#include<iostream>
using namespace std;
#include<cstring>			//for strlen() strcpy()
struct stringy{
	char * str;			//points to a string
	int len;			//length of string ( not counting '\0' )
};

void show(const stringy, int times=1);
void show(const char *, int times=1);
void set(stringy &, char*);

int main(void){
	stringy beany;
	char testing[]="Reality isn't what it used to be";		//first argument is a reference
							//allocate space to hold copy of testing
							//set str member of beany to point to new block
							//cpies testing to new block and set len member of beany
	set(beany, testing);
	show(beany);		//print member string once
	show(beany, 2);		//print member string twice
	testing[0]='D';
	testing[1]='u';
	show(testing);		//print testing string once
	show(testing, 3);		//print testing string thrice
	return 0;
}

void show(const stringy src, int times){
	for (int i=0; i<times; i++){
		cout<<src.str<<endl
		<<src.len<<endl;
	}
	cout<<endl;
}
void show(const char * str, int times){
	for (int i=0; i<times; i++){
		cout<<str<<endl;
	}
	cout<<endl;
}
void set(stringy &src, char* str){
	src.len=strlen(str);
	src.str=new char [src.len+1];
	strcpy(src.str, str);
}
