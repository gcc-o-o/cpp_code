#include<stdio.h>
#define in 0
#define out 1

int main(int argc,char *argv[])
{

	int state=out;
	int c;
	long word_num=0;
	FILE*pt=fopen(argv[1],"r+");
	printf("argv_1 %s\n",argv[1]);
	if(!pt)
		fprintf(stderr,"can't open %s",argv[1]);
	while((c=getc(pt))!=EOF){
		if(c=='\n'||c==' ')
			state=out;
		else if(state==out){
			state=in;
			++word_num;
		}
	}
	printf("word num in this file is : %ld",word_num);
	return 0;
}