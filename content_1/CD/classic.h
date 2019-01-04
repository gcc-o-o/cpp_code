//classic.h
#ifndef CLASSIC_H_
#define CLASSIC_H_
#include "cd.h"

class Classic : public Cd
{
private:
	char * songs;
public:
	Classic(const char * sg, const char * pf, const char * lb, int sl, double pt);
	Classic(const Classic & c);
	Classic();
	virtual ~Classic();
	virtual void Report() const;
	virtual Classic & operator=(const Classic & c);
};

#endif