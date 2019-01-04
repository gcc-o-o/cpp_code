//using the sqrt() function

#include<iostream>
#include<cmath>

double sqrt(double);
int main()
{
	using namespace std;
	double area;
	cout<<"Enter the floor area ,in square feet, of your home"
		<<endl;
	cin>>area;
	double side;
	side=sqrt(area);
	cout<<"the side of your home is "<<side<<" feeet";
	return 0;
}