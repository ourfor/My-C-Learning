#include<iostream>
#include<string>
using namespace std;

template<typename T>
T max(T a,T b)
{
	return a>b?a:b;
}


int main()
{
  	cout << "max(6,5)" << max(6,5) << endl;
	cout << "max('6','5')" << max('6','5') << endl;
	return 0;
}
