//sales.h -- exception and inheritance
#ifndef SALES_H_
#define SALES_H_
#include <stdexcept>
#include <string>

class Sales{
public:
	enum {MONTHS = 12};
	class bad_index : public std::logic_error {
	private:
		int bi;		//bad index
	public:
		bad_index(int b, const std::string & s =
			"Index error in Sales object.\n");
		int bi_val() const {return bi;}
		virtual ~bad_index() {}
	};
	Sales(int y);
	Sales(int y, double * gr, int n);
	virtual ~Sales() {}
	int Year() const {return year;}
	virtual double operator[](int id) const;
	virtual double & operator[](int id);
private:
	double gross[MONTHS];
	int year;
};

class LabeledSales : public Sales {
public:
	class nbad_index : public Sales::bad_index{
	public:
		nbad_index(const std::string & lb, int id, const std::string & s
			= "Index error in labeledSales object\n");
		const std::string & label_val() const {return label;}
		virtual ~nbad_index() {}
	private:
		std::string label;
	};
	LabeledSales(const std::string & lb = "none", int y = 0);
	LabeledSales(const std::string & lb, int y, double * gr, int n);
	virtual ~LabeledSales() {}
	const std::string & Label() const {return label;}
	virtual double operator[](int id) const;
	virtual double & operator[](int id);
private:
	std::string label;
};

#endif
