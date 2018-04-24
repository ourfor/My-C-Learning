// 数列求和.cpp
#include<iostream>
#include<cmath>
double pi=3.1415;
using namespace std;
int main()
{
	double a[50];
	int i;
	for(i=0;i<50;i++)
		a[i]=50 * pi /(i + 1);
	for(i=49;i>=0;i--)
	{
		cout << a[i] << "  ";
		if(i%5==0) cout << endl;
	}
	double sum=0;
	for(i=0;i<=49;i++)
		sum=sin(a[i]) * cos(a[i]) + sum;
	cout << endl << sum;
	return 0;	
}