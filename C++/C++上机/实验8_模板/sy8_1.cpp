//sy8_1.cpp
//了解模板的功能
//Date:20180601
//Author:ourfor

#include<iostream>
using namespace std;

template <typename T>
T MAX(T a,T b)
{
	return a>b?a:b;
}

int main()
{
	cout << "MAX(5,6)is" << MAX(5,6) << endl;
	cout << "MAX('5','6')is" << MAX('5','6') << endl;

	return 0;
}