//use_sales.cpp -- nested exception
//compile with sales.cpp
#include "sales.h"
#include <iostream>

int main(void)
{
	using std::cout;
	using std::cin;
	using std::endl;
	double vals1[12]{
		1,2,3,4,5,6,
		7,8,9,10,11,12
	};
	double vals2[12]{
		11,22,33,44,55,66,
		77,88,99,100,111,212
	};
	Sales sales1(2011, vals1, 12);
	LabeledSales sales2("Blogstar", 2012, vals2, 12);
	cout << "First try block:" << endl;
	try{
		int i;
		cout << "Year = " << sales1.Year() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales1[i] << " ";
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Year = " << sales2.Year() << endl;
		cout << "Label = " << sales2.Label() << endl;
		for (i = 0; i < 12; i++)
		{
			cout << sales2[i] << " ";
			if (i % 6 == 5)
				cout << endl;
		}
		cout << "Endl of try block 1" << endl;
	}
	catch(LabeledSales::nbad_index & nbi){
		cout << nbi.what();
		cout << "Company: " << nbi.label_val() << endl;
		cout << "Bad index: " << nbi.bi_val() << endl;
	}
	catch(Sales::bad_index & bi){
		cout << bi.what();
		cout << "Bad index: " << bi.bi_val() << endl;
	}
	cout << "\nNext try block:\n";
	try{
		sales1[20] = 111222;
		sales2[2] = 1.22;
		cout << "End of try block 2" << endl;
	}
	catch(LabeledSales::nbad_index & nbi){
		cout << nbi.what();
		cout << "Company: " << nbi.label_val() << endl;
		cout << "Bad index: " << nbi.bi_val() << endl;
	}
	catch(Sales::bad_index & bi){
		cout << bi.what();
		cout << "Bad index: " << bi.bi_val() << endl;
	}
	cout << "done!\n";
	return 0;
}
