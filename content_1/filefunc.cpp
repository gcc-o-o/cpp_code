#include<iostream>
#include<fstream>
#include<string>

using namespace std;
void file_it(ostream &, double, double [], int);

int main(void)
{
	double objective;
	const int SIZE=4;
	double eyepieces[SIZE];
	string filename="telescope.txt";
	ofstream fout;
	fout.open(filename);
	if (!fout.is_open())
	{
		cerr<<"can not open "<<filename<<endl;
		exit(EXIT_FAILURE);
	}
	cout<<"enter the focal length of the objective: ";
	cin>>objective;
	cout<<endl<<"enter the focal length of the "<<SIZE<<" eyepieces "<<endl;;
	for (int i=0; i<SIZE; i++)
	{
		cout<<"# "<<i+1<<" : ";
		cin>>eyepieces[i];
		//cout<<endl;
	}
	file_it(cout, objective, eyepieces, SIZE);
	file_it(fout, objective, eyepieces, SIZE);
	return 0;
}

void file_it(ostream & os, double objective, double eyepieces[], int size)
{
	ios_base::fmtflags initial;
	initial=os.setf(ios_base::fixed);
	os.precision(0);
	os<<"the focal length of objective: "<<objective<<endl;
	os.setf(ios_base::showpoint);
	os.precision(6);
	os.width(10);
	os<<"eyepieces";
	os.width(20);
	os<<"magnification"<<endl;
	for (int i=0; i<size; i++)
	{
		os.width(10);
		os<<eyepieces[i];
		os.width(20);
		os<<objective / eyepieces[i]<<endl;
	}
	os.setf(initial);
}