//newplace.cpp  test regular new and placement new
#include <iostream>
#include <new>

const int BUF=512;
const int N = 10;
char buffer[BUF];

int main(void)
{
	using namespace std;
	cout<<"call regular new and placement new the first time"<<endl;
	double *p1, *p2;
	p1=new double [N];
	p2=new (buffer) double [N];
	cout<<"heap: "<<p1<<"\tstatic: "<<(void*)buffer<<endl;
	for (int i=0; i<N; i++)
		cout<<"#"<<i<<" p1 "<<" : "<<&p1[i]<<"\tp2 "<<" : "<<&p2[i]<<endl;
	cout<<"call regular new and placement new the second time"<<endl;
	double *p3, *p4;
	p3=new double [N];
	p4=new (buffer) double [N];
	for (int i=0; i<N; i++)
		cout<<"#"<<i<<" p3 "<<" : "<<&p3[i]<<"\tp4 "<<" : "<<&p4[i]<<endl;
	delete [] p1;
	cout<<"call regular new and placement new the third time"<<endl;
	p1=new double [N];
	p2=new (buffer + N * sizeof(double)) double [N];
	for (int i=0; i<N; i++)
		cout<<"#"<<i<<" p1 "<<" : "<<&p1[i]<<"\tp2 "<<" : "<<&p2[i]<<endl;
	delete [] p3;
	delete [] p1;
	return 0;
}