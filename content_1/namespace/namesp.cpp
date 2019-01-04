#include <iostream>
#include "namesp.h"

namespace debt
{
	void getDebt(Debt &rd)
	{
		getPerson(rd.name);
		cout<<"enter debt: ";
		cin>>rd.amount;
	}
	void showDebt(const Debt &rd)
	{
		showPerson(rd.name);
		cout<<"$ "<<rd.amount<<endl;
	}
	double sumDebts(const Debt arr[], int n)
	{
		double result=0;
		for (int i=0; i<n; i++)
			result+=arr[i].amount;
		return result;
	}
	
}

namespace person
{
	void getPerson(Person &rp)
	{
		cout<<"enter first name"<<endl;
		cin>>rp.fname;
		cout<<"enter last name"<<endl;
		cin>>rp.lname;
	}
	void showPerson(const Person &rp)
	{
		cout<<rp.fname<<" , "<<rp.lname<<endl;
	}
}
