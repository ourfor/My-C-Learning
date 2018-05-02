#include<iostream>

using namespace std;

int calculator(int n)
{
	//出口
	if(n==0) return 1;
	return n * calculator(n-1);
}

int main()
{
	cout << "输入整数n：";
	int n;
	cin >> n;
	cout << calculator(n);
	return 0;
}