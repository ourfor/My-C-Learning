//input number and range 
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	void func(int num);
	cout << "输入需要排序的数字的个数：";
	printf("\n");
	int num;
	cin >> num;
	func(num);
}
void func(int num)    //数据类型为双精度浮点型
{
	double a[num];
	int i,j;
	cout << "这是最后一步了，输入这些数，数字之间以一个空格隔开，输完后回车:" << "\n";
	for(i=0;i<=num-1;i++)
		cin >> a[i];
	for(j=num;j>=0;j--)
	{
		for(i=0;i<=j;i++)
			if(a[i]<a[i+1]) swap(a[i],a[i+1]);
	}
	for(i=0;i<=num-1;i++)
		cout << a[i] << "  ";
	printf("\n");
}
void func(int num)     //数据类型为整型
{
	int a[num];
	int i,j;
	cout << "这是最后一步了，输入这些数，数字之间以一个空格隔开，输完后回车:" << "\n";
	for(i=0;i<=num-1;i++)
		cin >> a[i];
	for(j=num;j>=0;j--)
	{
		for(i=0;i<=j;i++)
			if(a[i]<a[i+1]) swap(a[i],a[i+1]);
	}
	for(i=0;i<=num-1;i++)
		cout << a[i] << "  ";
	printf("\n");
}
void func(int num)       //数据类型为单精度浮点型
{
	float a[num];
	int i,j;
	cout << "这是最后一步了，输入这些数，数字之间以一个空格隔开，输完后回车:" << "\n";
	for(i=0;i<=num-1;i++)
		cin >> a[i];
	for(j=num;j>=0;j--)
	{
		for(i=0;i<=j;i++)
			if(a[i]<a[i+1]) swap(a[i],a[i+1]);
	}
	for(i=0;i<=num-1;i++)
		cout << a[i] << "  ";
	printf("\n");
}