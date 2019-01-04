//stringbad.h -- flawed string class definition
#ifndef STRINGBAD_H_
#define STRINGBAD_H_
#include <iostream>

class StringBad
{
private:
	char * str;			//pointer to string
	int len;			//length of string
	static int num_obj;	//number of objects
public:
	StringBad();									//default constructor
	StringBad(const char * s);						//constructor
	StringBad(const StringBad & st);				//deep copy constructor
	~StringBad();									//destructor
	StringBad & operator=(StringBad & st);	//assignment operator
	//friend function
	friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
};

#endif