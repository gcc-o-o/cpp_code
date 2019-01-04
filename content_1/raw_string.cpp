//test raw string wchar_t char16_t and char32_t

#include<iostream>

int main(void)
{
	using namespace std;
	char s[]="’‚ a normal string";
	wchar_t s1[]=L" this is a wchar_t type string";
	char16_t s2[]=u"this is a char16_t type string";
	char32_t s3[]=U"this is a cjhar32_t type string";

	cout<<R"+/(’‚this is a raw string)+/"<<endl;

	cout<<s<<endl
	<<s1<<endl
	<<s2<<endl
	<<s3<<endl
	<<L"wchar_t type constant"<<endl
	<<U"char32_t type constant"<<endl
	<<u8"’‚ utf-8 string"<<endl;

	return 0;
}