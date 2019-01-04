#include <iostream>
using std::cout;
using std::endl;

template<typename T>
void show(T);

template<typename T>
void show(T t)
{
	cout << t << endl;
}

template <typename T>
class A
{
private:
	static int count;
public:
	friend void show<T>(T t);
	template<typename TT>
		void sum(TT, TT);
	
};

template void show<int>(int);

template <typename T>
int A<T>::count = 0;

template<typename T>
void sum(T t1, T t2)
{
	t1 + t2;
}

int main()
{
	return 0;
}