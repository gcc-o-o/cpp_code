//String.cpp -- implementation of class String
#include <cstring>
#include <cctype>
#include "String.h"
using std::cout;
using std::endl;

//initializing static class member
int String::num_obj = 0;

//member methods

String::String()			//default constructor
{
	len = 0;
	str = nullptr;							//default string
	num_obj++;
	//cout << num_obj << " : \"" << str <<"\"created\n";
}

String::String(const char * s)		//constructor String from c string
{
	len = std::strlen(s);					//set size
	str = new char [len + 1];				//allot storage
	std::strcpy(str, s);					//initializing poiner
	num_obj++;					//set object count
	//cout << num_obj << " : \"" << str <<"\" created\n";	//for your information
}


String::String(const String & st)	//deep copy constructor
{
	len = st.len;				//set string size
	str = new char [len + 1];			//allot space
	std::strcpy(str, st.str);			//copy string
	num_obj++;				//update object count
	//cout << num_obj << " : \"" << str <<"\"copy constructor\n";
}

String::~String()
{
	//cout <<"\""<< str << "\" deleted ";
	delete [] str;
	num_obj--;
	//cout<< num_obj << " left\n";
}

char & String::operator[](int i)
{
	return str[i];
}

const char & String::operator[](int i) const
{
	//cout << "in const []\n";
	return str[i];
}

const String & String::operator=(const String & st)
{
	if (this == &st)
	{
		//cout << "in assignment operator 1\n";
		return *this;
	}
	len = st.len;				//set size
	delete [] str;				//free old string
	str = new char [len + 1];			//allot space
	std::strcpy(str, st.str);			//copy string
	//cout << num_obj << " : \"" << str << "\"assignment operator 2" << endl;
	return *this;
}

void String::StringLow()
{
	char * temp = str;
	while (*temp)
	{
		*temp = std::tolower(*temp);
		temp++;
	}
}

void String::StringUp()
{

	char * temp = str;
	while (*temp)
	{
		*temp = std::toupper(*temp);
		temp++;
	}
}

int String::AppearTimes(const char c) const
{
	int count = 0;
	char * temp = str;
	while (*temp)
	{
		if (*temp == c)
			count ++;
		temp ++;
	}
	return count;
}

//friend function
bool operator<(const String & st1, const String & st2) 
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator==(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

std::ostream & operator<<(std::ostream & os, const String & st)
{
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;
}


String operator+(const String & st1, const String & st2)
{
	String temp;
	temp.len = std::strlen(st1.str) + std::strlen(st2.str);
	temp.str = new char[temp.len + 1];
	std::strcpy(temp.str, st1.str);
	std::strcat(temp.str, st2.str);
	return temp;
}

//static methods
int String::HowMany()
{
	return num_obj;
}