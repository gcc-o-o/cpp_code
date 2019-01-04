//String.h -- flawed string class definition
#ifndef String_H_
#define String_H_
#include <iostream>

class String
{
private:
	char * str;			//pointer to string
	int len;			//length of string
	static int num_obj;		//number of objects
	static const int CINLIM = 40;	//'operator>>' input limit
public:
	String();					//default constructor
	String(const char * s);			//constructor
	String(const String & st);			//deep copy constructor
	~String();					//destructor
	int length() const {return len;}
	char & operator[](int i);
	const char & operator[](int i) const;		//for const String objects
	const String & operator=(const String & st);	//assignment operator
	//String & operator=(const char * chr);
	void StringLow();				//make every charactor in string to lower
	void StringUp();				//make every charactor in string to upper
	int AppearTimes(const char c) const; 		//return times 'c' appeared in String object
//friend functions
	friend bool operator<(const String & st1, const String & st2);
	friend bool operator==(const String & st1, const String & st2);
	friend bool operator>(const String & st1, const String & st2);
	friend std::ostream & operator<<(std::ostream & os, const String & st);
	friend std::istream & operator>>(std::istream & is, String & st);
	friend String operator+(const String & st1, const String & st2);
//static function
	static int HowMany();
};

#endif