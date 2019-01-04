//tmp2tmp.cpp -- template friend to template class
#include <iostream>
using std::cout;
using std::endl;
//Template prototype
template <typename T>
void counts();
template <typename T>
void report(T &);

template <typename T>
class HasFriend
{
private:
	T item;
	static int count;
public:
	HasFriend(const T & t) : item(t) {count++;}
	~HasFriend() {count--;}
	friend void counts<T>();
	friend void report<>(HasFriend<T> & t);
};

template <typename T>
int HasFriend<T>::count = 0;

//template friend function definition
template <typename T>
void counts()
{
	cout << "template size: " << sizeof(HasFriend<T>) << endl
	<< "template count: " << HasFriend<T>::count << endl;
}

template <typename T>
void report	(T & t)
{
	cout << "t.item: " << t.item << endl;

}

int main()
{
	counts<int>();
	HasFriend<int> hfi1(10);
	HasFriend<int> hfi2(20);
	HasFriend<double> hfdb(3.3);
	report(hfi1);
	report(hfi2);
	report(hfdb);
	cout << "counts<int> output:\n";
	counts<int>();
	cout << "counts<double> output:\n";
	counts<double>();
	return 0;
}