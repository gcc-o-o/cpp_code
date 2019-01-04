//sales.cpp
#include <iostream>
#include "sales.h"

namespace SALES
{
	void setSales(Sales &s, const double ar[], int n)
	{
		double max, min, sum;
		int i;
		for (i=0; i<QUARTERS && i<n; i++)
		{
			s.sales[i]=ar[i];
			if (i==0)
				sum=max=min=ar[i];
			else
			{
				sum+=ar[i];
				if (max<ar[i])
					max=ar[i];
				if (min>ar[i])
					min=ar[i];
			}
		}
		s.average=sum/i;
		s.max=max;
		s.min=min;
	}
	
	void setSales(Sales &s)
	{
		using namespace std;
		double sales, max, min, sum;
		sales=sum=0;
		cout<<"\nenter the sales data for 4 quarters: "<<endl;
		int i;
		for (i=0; i<QUARTERS && cin>>sales; i++)
		{
			s.sales[i]=sales;
			if (i==0)
				sum=max=min=sales;
			else
			{
				sum+=sales;
				if (max<sales)
					max=sales;
				if (min>sales)
					min=sales;
			}
		}
		s.average=sum/i;
		s.max=max;
		s.min=min;
	}

	void showSales(const Sales &s)
	{
		using namespace std;
		cout<<"\nsales: "<<endl;
		for (int i=0; i<QUARTERS; i++)
			cout<<s.sales[i]<<" ";
		cout<<"\naverage: "<<s.average<<endl
		<<"max: "<<s.max<<endl
		<<"min: "<<s.min<<endl;
	}
}