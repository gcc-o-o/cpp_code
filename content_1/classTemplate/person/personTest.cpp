//personTest.cpp -- test virtual base classes inheritance
//compile with string.cpp and person.cpp
#include "person.h"
#include "String.h"

int main(void)
{
	BadDude b("Ray", "swift");
	b.Show();
	b.Person::Show();
	cout << b.PDraw() << endl;
	cout << b.GDraw() << endl;
	Gunslinger g("guns", "linger");
	g.Show();
	return 0;
}