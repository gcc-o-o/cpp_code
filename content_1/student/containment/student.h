//student.h -- define Student Class using containment
#ifndef STUDENT_H_
#define STUDENT_H_

#include "string.h"
#include <valarray>
#include <iostream>

class Student
{
private:
	typedef std::valarray<double> ArrayDb;
	String name;		//contained object
	ArrayDb scores;		//contained object
	//private method for scores output
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student() : name{"Null student"}, scores{} {}
	explicit Student(const String & n) : name{n}, scores{} {}
	explicit Student(int s) : name{"Nully"}, scores(s) {}
	Student(const String & n, int s) : name{n}, scores(s) {}
	Student(const String & n, const ArrayDb & s) : name{n}, scores(s) {}
	Student(const char * n, const double * s, int size) : name{n}, scores(s, size) {}
	~Student() {}
	double Average() const;
	const String & Name() const;
	double operator[](int i) const;
	double & operator[](int i);
//friends
	//input
	friend std::istream & operator>>(std::istream & is, Student & st); //one word
	friend std::istream & getline(std::istream & is, Student & st);	//one line
	//output
	friend std::ostream & operator<<(std::ostream & os, const Student & st);
};

#endif