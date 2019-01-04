//ruler.cpp  using recursion to subdivide a ruler

#include <iostream>

int len=66;
int divi=6;

void subdivide(char [], int min, int max, int level);

int main(void)
{
	using namespace std;
	int max=len-2;
	int min=0;
	char ruler[len];
	ruler[len-1]='\0';
	ruler[min]=ruler[max]='|';
	for (int i=1; i<len-2; i++)
	{
		ruler[i]=' ';
	}
	cout<<ruler<<endl;
	for (int i=1; i<divi; i++)
	{
		subdivide(ruler, min, max, i);
		cout<<ruler<<endl;
		for (int j=1; j<len-2; j++)
		{
			ruler[j]=' ';
		}
	}
	//cout<</* */"×¢ÊÍ"<<endl;
	return 0;
}


void subdivide(char ruler[], int min, int max, int level)
{
	if (level<=0)
		return;
	int mid;
	mid=(min+max)/2;
	ruler[mid]='|';
	subdivide(ruler, min, mid, level-1);
	subdivide(ruler, mid, max, level-1);
}