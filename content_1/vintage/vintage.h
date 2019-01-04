//vintage.h
#ifndef VINTAGE_H_
#define VINTAGE_H_
#include "port.h"
class VintagePort : public Port
{
private:
	char * nickname;
	int year;
public:
	VintagePort();
	VintagePort(const char * br, int b, const char * nn, int y);
	VintagePort(const VintagePort & v);
	virtual ~VintagePort() {delete [] nickname;}
	VintagePort & operator=(const VintagePort & v);
	virtual void Show() const;
	friend ostream & operator<<(ostream & os, const VintagePort & v);
};

#endif