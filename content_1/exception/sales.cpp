//sales.cpp -- Sales implementation
#include "sales.h"

//methods of class Sales
Sales::bad_index::bad_index(int b, const std::string & s)
	: bi(b), std::logic_error(s) {}

Sales::Sales(int y)
	: year(y) {}

Sales::Sales(int y, double * gr, int n)
	: year(y)
{
	int lim = (n < MONTHS) ? n : MONTHS;
	int i;
	for (i = 0; i < lim; i++)
		gross[i] = gr[i];
	for ( ; i < MONTHS; i++)
		gross[i] = 0;
}

double Sales::operator[](int id) const
{
	if (id < 0 || id >= MONTHS)
		throw bad_index(id);
	return gross[id];
}

double & Sales::operator[](int id)
{
	if (id < 0 || id >= MONTHS)
		throw bad_index(id);
	return gross[id];
}


//methods of class LabeledSales
LabeledSales::nbad_index::nbad_index(const std::string & lb, int id, const std::string & s)
	: label(lb), Sales::bad_index(id, s) {}

LabeledSales::LabeledSales(const std::string & lb, int y)
	: Sales(y), label(lb) {}

LabeledSales::LabeledSales(const std::string & lb, int y, double * gr, int n)
	: Sales(y, gr, n), label(lb) {}


double LabeledSales::operator[](int id) const
{
	if (id < 0 || id >= Sales::MONTHS)
		throw nbad_index(Label(), id);
	return Sales::operator[](id);
}

double & LabeledSales::operator[](int id)
{
	if (id < 0 || id >= Sales::MONTHS)
		throw nbad_index(Label(), id);
	return Sales::operator[](id);
}
