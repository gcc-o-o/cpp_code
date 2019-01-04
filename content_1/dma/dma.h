//dma.h -- inheritance and dynamic memory allocation
#ifndef DMA_H_
#define DMA_H_
#include <iostream>

//bass class using dma
class BaseDMA
{
private:
	char * lable;
	int rating;
public:
	BaseDMA(const char * l = "null", int r = 0);
	BaseDMA(const BaseDMA & b);
	virtual ~BaseDMA();
	BaseDMA & operator=(const BaseDMA & b);
	friend std::ostream & operator<<(std::ostream & os, const BaseDMA & b);
};

//derived class without DMA, no dessturctor needed
//uses implicit copy constructor
//uses implicit assignment operator
class LackDMA : public BaseDMA
{
private:
	enum {COL_LEN = 40};
	char color[COL_LEN];
public:
	LackDMA(const char * c = "black", const char * l = "null", int r = 0);
	LackDMA(const char * c, const BaseDMA & b);
	friend std::ostream & operator<<(std::ostream & os, const LackDMA & l);
};

//derived class with DMA
class HasDMA : BaseDMA
{
private:
	char * style;
public:
	HasDMA(const char * s = "none", const char * l = "null", int r = 0);
	HasDMA(const char * s, const BaseDMA & b);
	HasDMA(const HasDMA & h);
	HasDMA & operator=(const HasDMA & h);
	friend std::ostream & operator<<(std::ostream & os, const HasDMA & h);
};
#endif