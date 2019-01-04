//randomwalk.cpp using Vector class
//compile with the vector.cpp file
#include <cstdlib> 		//rand() srand() prototypes
#include <ctime>		//time() prototype
#include "vector.h"

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::rand;
	using std::srand;
	using std::time;
	using VECTOR::Vector;
	Vector result{0, 0};
	Vector step;
	double stepdistance;
	unsigned long steps = 0;
	double direction;
	double target;
	srand(time(0));
	cout << "enter target distance (q to quit)" << endl;
	while (cin >> target)
	{
		cout << "enter step distance" << endl;
		if (!(cin >> stepdistance))
			break;
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(stepdistance, direction, Vector::POL);
			result = result + step;
			steps++;
		}
		cout << "after " << steps << " steps " 
		<< "has the following location " << endl;
		result.rect_mode();
		cout << result << "or" << endl;
		result.polar_mode();
		cout << result;
		cout << "enter new target distance (q to quit)" << endl;
	}
	cin.clear();
	return 0;
}