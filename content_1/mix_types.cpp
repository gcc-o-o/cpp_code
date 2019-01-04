#include<iostream>

int main(void)
{
	using namespace std;
	struct years
	{
		int year;
	};
	years y0={1},y1{2},y2{3};
	years arr[3]={y0,y1,y2};
	years *parr[3]={&y0,&y1,&y2};
	years** ppyears=parr;
	cout<<"arr[0].year : "<<arr[0].year<<endl
	<<"parr[0]->year : "<<parr[0]->year<<endl
	<<"(*(ppyears+1))->year : "<<(*(ppyears+1))->year<<endl;
	int i{2};
	cout<<"i : "<<i<<endl;

	return 0;
}