//twod.cpp -- make a 2-D array
#include <iostream>
#include "arraytp.h"

int main()
{
	using std::cout;
	using std::endl;

	Array<int, 10> sum;
	Array<double, 10> average;
	Array<Array<int, 5>, 10> twod;

	for (int i = 0; i < 10; i++)
	{
		sum[i] = 0;
		for (int j = 0; j < 5; j++)
		{
			twod[i][j] = (i + 1) * (j + 1);
			sum[i] += twod[i][j];
		}
		average[i] = double(sum[i]) / 5;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cout.width(2);
			cout << (double)twod[i][j] << " ";
		}
		cout << " sum = ";
		cout.width(3);
		cout << sum[i];
		cout << " average = ";
		cout.width(3);
		cout << average[i] << endl;
	}
	return 0;
}
