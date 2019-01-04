//maxn_template.cpp
#include <iostream>
using namespace std;
#include <cstring>

template<typename T>
T maxn(T a[], int size);
template<>
char* maxn(char* a[], int size);

int main(void){
	int i[]{1,5,3,660,1};
	double d[]{1,5,6,3,699,3,6,1};
	char* c[]{
		"template",
		"using",
		"duality",
		"specalization",
		"twice",
		"explicit specalization",
		"end"
	};
	cout<<maxn(i, 5)<<endl
	<<maxn(d,8)<<endl
	<<maxn(c,7)<<endl;
	return 0;
}


template<typename T>
T maxn(T a[], int size){
	T temp=a[0];
	for (int i=1; i<size; i++){
		if (temp<a[i])
			temp=a[i];
	}
	return temp;
}

template<>
char* maxn(char* a[], int size){
	char* temp=a[0];
	int s=strlen(temp);
	for (int i=1; i<size; i++){
		if (s<strlen(a[i])){
			temp=a[i];
			s=strlen(a[i]);
		}
	}
	return temp;
}