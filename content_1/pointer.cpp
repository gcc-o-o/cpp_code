//test poiner and array name 


#include<iostream>

int main(void)
{
	using namespace std;
	int arr[3]{1,2,3};
	int* pt=arr;
	int(*pa)[3]=&arr;
	cout<<"pt :"<<pt<<endl
	<<"arr :"<<arr<<endl
	<<"&arr :"<<&arr<<endl
	<<"pa :"<<pt<<endl
	<<"sizeof(arr) :"<<sizeof(arr)<<endl
	<<"sizeof(pt) :"<<sizeof(pt)<<endl
	<<"sizeof(pa) :"<<sizeof(pa)<<endl
	<<"sizeof(&arr[0]) :"<<sizeof(&arr[0])<<endl;
	const char*str="test string";
	cout<<str<<endl;
	return 0;
}