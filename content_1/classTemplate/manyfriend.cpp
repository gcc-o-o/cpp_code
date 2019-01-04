//manyfriend.cpp -- unbound template friend to template class
#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class ManyFriend
{
private:
	T item;
public:
	ManyFriend(const T & t) : item(t) {}
	template <typename C, typename D> friend void show2(const C &, const D &);
};

template <typename C, typename D>
void show2(const C & c, const D & d)
{
	cout << c.item << " , " << d.item << endl;
}

int main(void)
{
	template void show2<ManyFriend<int>, ManyFriend<double> >(const ManyFriend<int> &, const ManyFriend<double> &);
	ManyFriend<int> mfi1(10);
	ManyFriend<int> mfi2(20);
	ManyFriend<double> mfdb(3.3);
	cout << "mfi1 mfi2" << endl;
	show2(mfi1, mfi2);
	cout << "mfi2, mfdb" << endl;
	show2(mfi2, mfdb);
	return 0;
}