//constCast.cpp -- using const_cast<> operator and reinterpret_cast<> operator
#include <iostream>
using std::cout;
using std::endl;

void change(const int* pi, int n);

int main(){
	int i1 = 100;
	int i2 = 200;
	const int* pc = &i2;
	cout << "i1, i2: " << i1 << ", " << i2 << endl;
	change(&i1, 33);
	change(pc, 33);
	cout << "i1, i2: " << i1 << ", " << i2 << endl;
	int pcc = (int) &i1;
	cout << pcc << endl;
	struct dat{char s1; char s2;};
	short l = 0x3031;
	dat* pd = reinterpret_cast<dat*>(l);
	cout << pd->s1 << ", " << pd->s2 << endl;
	return 0;
}

void change(const int* pi, int n){
	int* pc;
	pc = const_cast<int*>(pi);
	*pc += n;
}