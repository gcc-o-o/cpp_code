//implementation file for AbstractEmployee class and its children
#include "employee.h"

//AbstractEmployee class methods
AbstractEmployee::AbstractEmployee()
	: firstName("None"), lastName("None"), job("None") {}

AbstractEmployee::AbstractEmployee(const String & fn, const String ln,
	const String & j)
	: firstName(fn), lastName(ln), job(j) {}

AbstractEmployee::~AbstractEmployee() {}

void AbstractEmployee::ShowAll() const
{
	cout << "Name: " << firstName << "  " << lastName;
	cout << "\tJob: "  << job;
}

void AbstractEmployee::SetAll()
{
	cout << "FirstName: ";
	cin >> firstName;
	cout << "LastName: ";
	cin >> lastName;
	cout << "Job: ";
	cin >> job;
}

std::ostream & operator<<(std::ostream & os, const AbstractEmployee & ae)
{
	ae.ShowAll();
}


//Employee class methods
Employee::Employee() {}

Employee::Employee(const String & fn, const String & ln, const String & j)
	: AbstractEmployee(fn, ln, j) {}


void Employee::ShowAll() const
{
	AbstractEmployee::ShowAll();
	cout << endl;
}

void Employee::SetAll()
{
	AbstractEmployee::SetAll();
}


//Manager class methods
Manager::Manager()
	: inChargeOf(0) {}

Manager::Manager(const String & fn, const String & ln, const String & j, int ico)
	: AbstractEmployee(fn, ln, j), inChargeOf(ico) {}

Manager::Manager(const AbstractEmployee & ae, int ico)
	: AbstractEmployee(ae), inChargeOf(ico) {}

void Manager::ShowAll() const
{
	AbstractEmployee::ShowAll();
	cout << "\tIn charge of: " << inChargeOf << endl;
}

void Manager::SetAll()
{
	AbstractEmployee::SetAll();
	cout << "In charge of: ";
	cin >> inChargeOf;
}


//Fink class methods
Fink::Fink()
	: reportTo("None") {}

Fink::Fink(const String & fn, const String & ln, const String & j, const String & rt)
	: AbstractEmployee(fn, ln, j), reportTo(rt) {}

Fink::Fink(const AbstractEmployee & ae, const String & rt)
	: AbstractEmployee(ae), reportTo(rt) {}

void Fink::ShowAll() const
{
	AbstractEmployee::ShowAll();
	cout << "\tReport to: " << reportTo << endl;
}

void Fink::SetAll()
{
	AbstractEmployee::SetAll();
	cout << "Report to: ";
	cin >> reportTo;
}


//HighFink class methods
HighFink::HighFink() {}

HighFink::HighFink(const String & fn, const String & ln,
	const String & j, const String & rt, int ico)
	: AbstractEmployee(fn, ln, j), Manager(fn, ln, j, ico),
	Fink(fn, ln, j, rt) {}
	
HighFink::HighFink(const AbstractEmployee & ae, const String & rt, int ico)
	: AbstractEmployee(ae), Manager(ae, ico), Fink(ae, rt) {}
	
HighFink::HighFink(const Fink & f, int ico)
	: AbstractEmployee(f), Fink(f), Manager(f, ico) {}
	
HighFink::HighFink(const Manager & m, const String & rt)
	: AbstractEmployee(m), Fink(m, rt), Manager(m) {}
	
void HighFink::ShowAll() const
{
	AbstractEmployee::ShowAll();
	cout << endl << "InChargeOf: " << InChargeOf() << "\t\tReportTo: "
	<< ReportTo() << endl;
}

void HighFink::SetAll()
{
	AbstractEmployee::SetAll();
	cout << "InChargeOf: ";
	cin >> InChargeOf();
	cout << "ReportTo: ";
	while (cin.get() != '\n')
		continue;
	cin >> ReportTo();
}