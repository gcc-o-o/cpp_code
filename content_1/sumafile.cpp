#include<iostream>
#include<cstdlib>
#include<fstream>

const int ArrSize=50;

int main(void)
{
	using namespace std;
	cout<<"enter file name :";
	char filename[ArrSize];
	cin.getline(filename,ArrSize);
	ifstream inFile;
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout<<endl<<"failed to open "<<filename<<endl
		<<"program terminating"<<endl;
		exit(EXIT_FAILURE);
	}
	double value=0.0;
	double sum=0.0;
	int count=0;
	inFile>>value;
	while (inFile.good())
	{
		++count;
		sum+=value;
		inFile>>value;
	}
	if (inFile.eof())
		cout<<"end of file reached"<<endl;
	else if (inFile.fail())
		cout<<"input terminated by data mismatch"<<endl;
	else
		cout<<"input terminated for unkonwm reason"<<endl;
	cout<<endl<<"sum : "<<sum<<endl
	<<"count : "<<count<<endl
	<<"average : "<<sum/count<<endl;
	inFile.close();
	return 0;
}