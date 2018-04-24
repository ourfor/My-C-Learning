//funtemp.cpp --using a function template
#include<iostream>
using namespace std;
template<typename T>
void Swap(T &a,T &b);

int main()
{
	int i=10;
	int j=20;
	cout << "i,j=" << i << "," << j << ".\n";
	Swap(i,j);
	cout << "i,j=" << i << "," << j << ".\n";
	double x=56.78,y=98.346;
	cout << "x,y=" << x << "," << y << ".\n";
	Swap(x,y);
	cout << "x,y=" << x << "," << y << ".\n";
	cin.get();
	return 0;
}
template<typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}

