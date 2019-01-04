//use_student.cpp -- using a composite class
//compile with string.cpp and student.cpp
#include "student.h"
using std::cin;
using std::cout;
using std::endl;

void set(Student & st, int n);
const int pupils = 3;
const int quizzes = 5;

int main(void)
{
	Student ada[pupils] = {Student(quizzes), Student(quizzes), Student(quizzes)};
	int i;
	for (i = 0; i < pupils; ++i)
	{
		set(ada[i], quizzes);
	}
	cout << "\nResult list: \n";
	for (i = 0; i < pupils; i++)
	{
		cout << endl << ada[i];
		cout << "Avegrage: " << ada[i].Average() << endl;
	}
	cout << "Done\n";
	return 0;
}

void set(Student & st, int n)
{
	cout << "Please enter tha student's name: ";
	getline(cin, st);
	cout << "Please enter " << n << " quiz scores: \n";
	for (int i = 0; i < n; i++)
	{
		cin >> st[i];
	}
	while (cin.get() != '\n')
		continue;
}