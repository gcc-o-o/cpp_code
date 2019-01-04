//randomwalk.cpp using Vector class
//compile with the vector.cpp file
#include <cstdlib> 		//rand() srand() prototypes
#include <ctime>		//time() prototype
#include "vector.h"
#include <fstream>	//ostream class
#include <string>


int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	using std::rand;
	using std::srand;
	using std::time;
	using VECTOR::Vector;
	using std::ofstream;
	using std::string;
	string file_name = "walkstep.txt";
	Vector result{0, 0};
	Vector step;
	double stepdistance;
	unsigned long steps = 0;
	double direction;
	double target;
	srand(time(0));
	ofstream fout;
	fout.open(file_name);
	if (!(fout.is_open()))
	{
		cout << "can't not open" << file_name << endl;
		exit(1);
	}
	cout << "enter target distance (q to quit)" << endl;
	while (cin >> target)
	{
		cout << "enter step distance" << endl;
		if (!(cin >> stepdistance))
			break;
		fout << "Target Distance " << target << " Step Distance "
		<< stepdistance << endl;
		result.rect_mode();
		while (result.magval() < target)
		{
			direction = rand() % 360;
			step.reset(stepdistance, direction, Vector::POL);
			result = result + step;
			fout << steps << ": " << result;
			steps++;
		}
		fout << "after " << steps << " steps " 
		<< "the object has the following location " << endl;
		result.rect_mode();
		fout << result << "or" << endl;
		result.polar_mode();
		fout << result;
		fout << "Average outward distance per step = " << result.p
		cout << "enter new target distance (q to quit)" << endl;
	}
	cin.clear();
	return 0;
}