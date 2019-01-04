//rect_to_potular.cpp 
//turn rectangular coordinate to polar coordinate

#include<iostream>
#include<cmath>

struct rect
{
	double x;				//horizontal diatance from origin
	double y;				//vertical distance from origin
};
struct polar
{
	double distance;			//distance from origin
	double angle;			//ditrection from origin
 };
void show_polar(polar);
polar rect_to_polar(rect);

int main(void)
{
	using namespace std;
	rect rplace;
	polar pplace;
	cout<<"enter the x and y value ' q ' to quit"<<endl;
	while ((cout<<"x : ",cin>>rplace.x)&&(cout<<"y : ",cin>>rplace.y))
	{
		show_polar(rect_to_polar(rplace));
		cout<<endl<<"enter anther two nums"<<endl;
	}
	return 0;
}

void show_polar(polar pplace)
{
	using namespace std;
	const int Degree_per_radian=180/3.1415926;
	cout<<"diatance\t"<<pplace.distance<<endl
	<<"ditrection\t"<<pplace.angle*Degree_per_radian<<" degree"<<endl;
}

polar rect_to_polar(rect rplace)
{
	polar result;
	result.distance=sqrt(pow(rplace.x,2)+pow(rplace.y,2));
	result.angle=atan2(rplace.y,rplace.x);
	return result;
}