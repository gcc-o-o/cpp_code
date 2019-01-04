//test.cpp -- using AbstractEmployee classes
//compile with employee.cpp and string.cpp
#include "employee.h"

int main()
{
	Employee em("Trip", "Harris", "Thumper");
	cout << em;
	em.ShowAll();
	Manager ma("Amophia", "Spindragon", "Nuancer", 5);
	cout << ma;
	ma.ShowAll();
	
	Fink fi("Matt", "Oggs", "oiler", "Juno Barr");
	cout << fi;
	fi.ShowAll();
	HighFink hf(ma, "Curly Kew");
	hf.ShowAll();

	cout << "Press a key for next phase: ";
	cin.get();
	HighFink hf2;
	hf2.SetAll();
	cout << "Using AbstractEmployee's pointer: " << endl;
	AbstractEmployee * pat[4] = {&ma, &fi, &hf, &hf2};
	for (int i = 0; i < 4; i++)
		pat[i] -> ShowAll();
	return 0;
}