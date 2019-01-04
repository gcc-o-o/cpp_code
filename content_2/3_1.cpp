// some integer limit

#include<iostream>
#include<climits>

int main(void)
{
	using namespace std;

	short n_short;
	int n_int;
	long n_long;
	long long n_llong;
	cout<<"short "<<sizeof (short)<<endl
		<<"int "<<sizeof (int)<<endl
		<<"long "<<sizeof (long)<<endl
		<<"long long "<<sizeof (long long)<<endl
		<<"max short "<<SHRT_MAX<<endl
		<<"max int "<<INT_MAX<<endl
		<<"max long "<<LONG_MAX<<endl
		<<"max long long "<<LLONG_MAX<<endl
		<<"min int "<<INT_MIN<<endl
		<<"bit per Byte "<<CHAR_BIT<<endl;
	return 0;
}