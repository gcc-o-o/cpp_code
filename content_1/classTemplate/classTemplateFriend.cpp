//classTemplateFriend.cpp -- class template with non-template friend
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
class HasFriend
{
private:
	T item;
	static int count;
public:
	HasFriend(T t) : item(t) {count ++;}
	~HasFriend() {count--;}
	friend void counts();
	friend void report(HasFriend<T> &);	//template parameter
};

template<typename T>
int HasFriend<T>::count = 0;

//non-template friend to all HasFriend<T> classes
void counts()
{
	cout << "count int: " << HasFriend<int>::count << endl
		<< "count double: " << HasFriend<double>::count << endl;
}

//non-template friend to HasFriend<int> class
void report(HasFriend<int> & hf)
{
	cout << "HasFriend<int>: " << hf.item << endl;
}

//non-template friend to HasFriend<double> class
void report(HasFriend<double> & hf)
{
	cout << "HasFriend<double>: " << hf.item << endl;
}

int main()
{
	cout << "No object declared\n";
	counts();
	HasFriend<int> hfi1(10);
	cout << "After hfi1 declared\n";
	counts();
	HasFriend<int> hfi2(20);
	cout << "After hfi2 declared\n";
	counts();
	HasFriend<double> hfdb(1.1);
	cout << "After Hfdb declared\n";
	counts();
	report(hfi1);
	report(hfi2);
	report(hfdb);
	return 0;
}