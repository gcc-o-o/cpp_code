//strfile.cpp
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(){
	using namespace std;
	ifstream fin;
	fin.open("strfile.txt");
	if (fin.is_open() == false)
	{
		cerr << "can't open file \n";
		exit(EXIT_FAILURE);
	}
	string item;
	int count = 0;
	getline(fin, item, ':');
	while (fin){
		cout << ++count << ": " << item << endl;
		getline(fin, item, ':');
	}
	cout << "Done!" << endl;
	fin.close();
	return 0;
}