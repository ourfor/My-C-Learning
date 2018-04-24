//input number and range 
#include<iostream>
#include<cmath>
void func();
using namespace std;
int main()
{
	int num;
	cout << "Please enter the number:";
	cin >> num;
        func(num);
	int i;
	num=5;
	for(i=0;i<num;i++)
		cin >> a[i];
	int j;
	for(j=num-1;j>=0;j--)
	{
		for(i=0;i<=j;i++)
			if(a[i]<a[i+1]) swap(a[i],a[i+1]);
	}
	for(i=0;i<=num;i++)
                printf("%4.2lf",a[i]);
	cout << endl;
	return 0;
}
void func(int n)
{
        double &a[n];
}
