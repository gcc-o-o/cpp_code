//function get() getline() test

#include<iostream>

int main(void)
{
	using namespace std;
	const int arr_size=10;
	char name_1[arr_size];
	char name_2[arr_size];
	cout<<"enter name_1	in 'cin'"<<endl;
	cin>>name_1;
	cin.get();
	cout<<name_1<<endl;
	cout<<"enter name_1	in'cin.get()'"<<endl;
	cin.get(name_1,arr_size).get();
	cin.clear();
	cin.get();
	cout<<name_1<<endl
	<<"enter name_1		in 'cin.getline()'"<<endl;
	cin.getline(name_1,arr_size);
	cout<<name_1<<endl;

	return 0;
}