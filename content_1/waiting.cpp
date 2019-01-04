//waiting.cpp ***** using clock() in a time-delay loop

#include<iostream>
#include<ctime>

int main(void)
{
	using namespace std;
	long double delay_secs;
	cout<<"enter the delay secs"<<endl;
	cin>>delay_secs;
	clock_t delay_time=delay_secs*CLOCKS_PER_SEC;			//convert to clock ticks
	cout<<"starting"<<endl;
	clock_t current_time;
	clock_t elapsed_time;
	long double elapsed_secs;
	int last_sec;
	clock_t start_time=clock();
									//wait until time elapses
	while ((elapsed_time=clock()-start_time)<delay_time)
	{								//note the semicolon
		elapsed_secs=elapsed_time/CLOCKS_PER_SEC;
		if (elapsed_secs==int(elapsed_secs)&&elapsed_secs!=last_sec)
			cout<<(last_sec=elapsed_secs)<<' ';
	}
	cout<<"done"<<endl;
	return 0;
}