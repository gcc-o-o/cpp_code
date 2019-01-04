//person.h -- virtual base class test
//compile with string.cpp
#ifndef PERSON_H_
#define PERSON_H_
#include "string.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

class Person
{
private:
	String firstName;
	String lastName;
public:
	Person(const String & fn = "None", const String & ln = "None") : firstName(fn), lastName(ln) {}
	virtual void Show() {cout << firstName << " , " << lastName << endl;}	//show firstName and lastName
};

class Gunslinger : virtual public Person
{
private:
	int num;
public:
	Gunslinger(int n = 0) : num(n) {}
	Gunslinger(const String & fn, const String & ln, int n = 0)
		: Person(fn, ln), num(n) {}
	double Draw() {return 1.1;}
	void Show() {Person::Show(); cout << num << endl;}
};

class PokerPlayer : virtual public Person
{
public:
	PokerPlayer() {}
	PokerPlayer(const String & fn, const String & ln) : Person(fn, ln) {}
	int Draw() {std::srand(std::time(0)); return std::rand() % 52 + 1;}
};

class BadDude : private Gunslinger, public PokerPlayer
{
public:
	BadDude() {}
	BadDude(const String & fn, const String & ln, int n = 0)
		: Person(fn, ln), Gunslinger(fn, ln, n) {}
	double GDraw() {return Gunslinger::Draw();}
	int PDraw() {return PokerPlayer::Draw();}
	void Show() {Gunslinger::Show();}
};

#endif