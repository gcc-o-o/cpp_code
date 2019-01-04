//namesp.h
//create pers and debts namespace
#include <string>

namespace person
{
	using std::cin;
	using std::cout;
	using std::endl;
	struct Person
	{
		std::string fname;
		std::string lname;
	};
	void getPerson(Person &rp);
	void showPerson(const Person &rp);
}

namespace debt
{
	using namespace person;
	struct Debt
	{
		Person name;
		double amount;
	};
	void getDebt(Debt &rd);
	void showDebt(const Debt &rd);
	double sumDebts(const Debt arr[], int n);
}