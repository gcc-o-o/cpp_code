//workermi.h -- working classes
#ifndef WORKERMI_H_
#define WORKERMI_H_
#include "string.h"

class Worker			//an abstract bass class
{
private:
	String fullname;
	long id;
protected:
	virtual void Get();
	virtual void Data() const;
public:
	Worker() : fullname("no one"), id(0L) {}
	Worker(const String & fn, long i) : fullname(fn), id(i) {}
	virtual ~Worker() =0;	//pure virtual destructor
	virtual void Set();
	virtual void Show() const;
};

class Waiter : virtual public Worker
{
private:	
	int panache;
protected:
	void Get();
	void Data() const;
public:
	Waiter() : Worker(), panache(0) {}
	Waiter(const String & fn, long i, int p = 0) : Worker(fn, i), panache(p) {}
	Waiter(const Worker & w, int p = 0) : Worker(w), panache(p) {}
	~Waiter() {}
	void Set();
	void Show() const;
};

class Singer : virtual public Worker
{
protected:
	enum {other, alto, contralto, soprano, bass, baritone ,tenor};
	enum {vtypes = 7};
	void Get();
	void Data() const;
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

class SingerWaiter : public Singer, public Waiter
{
protected:
	void Get() {}
	void Data() const {}
public:
	SingerWaiter() {}
	SingerWaiter(const String & fn, long i, int v = other, int p = 0)
		: Worker(fn, i), Singer(fn, i, v), Waiter(fn, i, p) {}
	SingerWaiter(const Worker & wk, int v = other, int p = 0) 
		: Worker(wk), Singer(wk, v), Waiter(wk, p) {}
	SingerWaiter(const Singer & s, int p = 0)
		: Worker(s), Waiter(s,p) {}
	SingerWaiter(const Waiter & wt, int v = other)
		: Worker(wt), Singer(wt, v) {}
	void Set();
	void Show() const;
};

#endif