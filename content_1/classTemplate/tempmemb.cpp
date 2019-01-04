//tempmemb.cpp -- mested class template
#include <iostream>
using std::cout;
using std::endl;

template<typename T>
class Beta
{
private:
	template<typename V>
	class hold;		//declaration
	hold<T> q;
	hold<int> n;
public:
	Beta(T t, int i) : q(t), n(i) {}
	template<typename U>
	U blab(U u, T t);		//declaration
	void Show() const {q.Show(); n.Show();}
};

template<typename T>
	template<typename V>
	class Beta<T>::hold
	{
	private:
		V val;
	public:
	 	hold(V v) : val(v) {}
		void Show() const {cout << val;}
		V Value() const {return val;}
	};

template<typename T>
	template<typename U>
	U Beta<T>::blab(U u, T t)
	{
		return (q.Value() / n.Value()) * u / t;
	}

int main()
{
	Beta<double> guy(10.5, 3);
	cout << "V was set to T which was set to double then V was set to int\n";
	cout << guy.blab(10, 12) << endl;
	cout << "U was set to int" << endl;
	cout << guy.blab(10.0, 12) << endl;
	cout << "U was set to double" << endl;
	return 0;
}