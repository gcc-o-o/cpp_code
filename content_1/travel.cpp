//travel.cpp  using structures with functions

#include<iostream>

const int Mins_per_hour=60;
struct travel_time
{
	int hours;
	int mins;
};
travel_time sum(travel_time,travel_time);
void show_time(travel_time);

int main(void)
{
	travel_time day1,day2;
	day1={1,20};
	day2={1,50};
	show_time(sum(day1,day2));
	return 0;
}

travel_time sum(travel_time time_1,travel_time time_2)
{
	travel_time total;
	total.hours=time_1.hours+time_2.hours+(time_1.mins+time_2.mins)/Mins_per_hour;
	total.mins=(time_1.mins+time_2.mins)%Mins_per_hour;
	return total;
}

void show_time(travel_time time)
{
	using namespace std;
	cout<<time.hours<<"\t hours"<<endl
	<<time.mins<<"\t mins"<<endl;
}