//stringbad.cpp -- implementation of class StringBad
#include <cstring>
#include "stringbad.h"
using std::cout;
using std::endl;

//initializing static class member
int StringBad::num_obj = 0;

//member methods
//constructor StringBad from c string
StringBad::StringBad(const char * s)
{
	len = std::strlen(s);									//set size
	str = new char [len + 1];								//allot storage
	std::strcpy(str, s);									//initializing poiner
	num_obj++;												//set object count
	cout << num_obj << " : \"" << str <<"\" created\n";		//for your information
}

StringBad::StringBad()
{
	len = 4;
	str = new char [len+1];
	std::strcpy(str, "c++");							//default string
	num_obj++;
	cout << num_obj << " : \"" << str <<"\"created\n";
}

StringBad::StringBad(const StringBad & st)	//deep copy constructor
{
	len = st.len;						//set string size
	str = new char [len + 1];			//allot space
	std::strcpy(str, st.str);			//copy string
	num_obj++;							//update object count
	cout << num_obj << " : \"" << str <<"\"copy constructor\n";
}

StringBad::~StringBad()
{
	cout << "\"" << str << "\" deleted ";
	delete [] str;
	num_obj--;
	cout<< num_obj << " left\n";
}

StringBad & StringBad::operator=(StringBad & st)
{
	if (this == &st)
	{
		cout << "in assignment operator 1\n";
		return *this;
	}
	len = st.len;						//set size
	delete [] str;						//free old string
	str = new char [len + 1];			//allot space
	std::strcpy(str, st.str);			//copy string
	cout << num_obj << " : \"" << str << "\"assignment operator 2" << endl;
	return *this;
}	

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
	os << "\"" << st.str << "\"";
	return os;
}


