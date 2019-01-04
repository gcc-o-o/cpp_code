//student.h -- define a student class using private inheritance
#ifndef STUDENT_H_
#define STUDENT_H_

#include "string.h"
#include <iostream>
#include <valarray>

class Student : private String, private std::valarray<double>
{
private:
	typedef valarray<double> ArrayDb;
	//private method for scores output
	std::ostream & arr_out(std::ostream & os) const;
public:
	Student() : String("Null student"), ArrayDb() {}
	explicit Student(const String & s) : String(s), ArrayDb() {}
	explicit Student(int n) : String("Nully"), ArrayDb(n) {}
	Student(const String & s, int n) : String(s), ArrayDb(n) {}
	Student(const String & s, const ArrayDb & a) : String(s), ArrayDb(a) {}
	Student(const String & s, double * pad, int n) : String(s), ArrayDb(pad, n) {}
	~Student() {}
	double Average() const;
	double operator[](int i) const;
	double & operator[](int i);
	const String & Name() const;
//frined functions
	//input
	friend std::istream & operator>>(std::istream & is, Student & st);	//1 word
	friend std::istream & getline(std::istream & is, Student & st);		//1 line
	//output
	friend std::ostream & operator<<(std::ostream & os, const Student & st);
};

#endif