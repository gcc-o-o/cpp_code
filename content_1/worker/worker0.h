//worker.h -- working classes
#ifndef WORKER0_H_
#define WORKER0_H_
#include "string.h"

class Worker			//an abstract bass class
{
private:
	String fullname;
	long id;
public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const String & fn, long i) : fullname(fn), id(i) {}
	virtual ~Worker() =0;	//pure virtual destructor
	virtual void Set();
	virtual void Show() const;
};

class Waiter : public Worker
{
private:	
	int panache;
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const String & fn, long i, int p = 0) : Worker(fn, i), panache(p) {}
	Waiter(const Worker & w, int p = 0) : Worker(w), panache(p) {}
	~Waiter() {}
	void Set();
	void Show() const;
};

class Singer : public Worker
{
protected:
	enum {other, alto, contralto, soprano, bass, baritone ,tenor};
	enum {vtypes = 7};
private:
	const static char * pv[vtypes];		//string equivs of voice types
	int voice;
public:
	Singer() : Worker(), voice(0) {}
	Singer(const String & fn, long i, int v = other) : Worker(fn, i), voice(v) {}
	Singer(const Worker & w, int v = other) : Worker(w), voice(v) {}
	~Singer() {}
	void Set();
	void Show() const;
};
#endif