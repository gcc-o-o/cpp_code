//employee.cpp -- head file for AbstractEmployee class and its children
//compile with string.cpp
#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_
#include <iostream>
#include "string.h"

using std::cout;
using std::cin;
using std::endl;

class AbstractEmployee
{
private:
	String firstName;
	String lastName;
	String job;
public:
	AbstractEmployee();
	AbstractEmployee(const String & fn, const String ln, const String & j);
	virtual void ShowAll() const;	//lables and shows all data
	virtual void SetAll();			//prompts user for values
	friend std::ostream & operator<<(std::ostream & os, const AbstractEmployee & ae);
	//just display first and last name
	virtual ~AbstractEmployee() =0;	//this means the class is virtual base class
};

class Employee : public AbstractEmployee
{
public:
	Employee();
	Employee(const String & fn, const String & ln, const String & j);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class Manager : virtual public AbstractEmployee
{
private:
	int inChargeOf;		//number of AbstractEmployee managed
protected:
	int InChargeOf() const {return inChargeOf;}	//output
	int & InChargeOf() {return inChargeOf;}		//input
public:
	Manager();
	Manager(const String & fn, const String & ln, const String & j, int ico = 0);
	Manager(const AbstractEmployee & ae, int ico);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class Fink : virtual public AbstractEmployee
{
private:
	String reportTo;		//to whom fink reports
protected:
	String ReportTo() const {return reportTo;}
	String & ReportTo() {return reportTo;}
public:
	Fink();
	Fink(const String & fn, const String & ln, const String & j, const String & rt);
	Fink(const AbstractEmployee & ae, const String & rt);
	virtual void ShowAll() const;
	virtual void SetAll();
};

class HighFink : public Manager, public Fink	//management fink
{
public:
	HighFink();
	HighFink(const String & fn, const String & ln,
		const String & j, const String & rt, int ico);
	HighFink(const AbstractEmployee & ae, const String & rt, int ico);
	HighFink(const Fink & f, int ico);
	HighFink(const Manager & m, const String & rt);
	virtual void ShowAll() const;
	virtual void SetAll();
};


#endif