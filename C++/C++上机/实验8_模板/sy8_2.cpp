//sy8_2.cpp
//了解特定模板的作用
//date:20180601
//Author: ourfor

#include<iostream>
#include<cstring>

using namespace std;

template <class T>
T MAX(T a,T b)
{
	return a>b?a:b;
}

char *MAX(char *a,char *b)
{
	return strcmp(a,b)>0?a:b;
}

int main()
{
	cout << "MAX(6,5)is" << max(6,5) << endl;
	cout << "MAX(\"China\",\"Japan\")is" << MAX("China","Japan") << endl;

	return 0;
}