//输入n个数进行排序，数据类型可以是整型、单精度浮点型、双精度浮点型
#include<iostream>
using namespace std;
template<typename T>
void Swap(T x,T y);
void func(int num);
int main()
{
	int num;
	cout << "输入需要排序的数字的个数:";
	cin >> num;   
    func(num);
    return 0;
}
void func(int num)
{
	double a[num];
	
	int i,j;
	cout << "输入这些数字并以空格隔开" << endl;
	for(i=0;i<=num-1;i++)
		cin >> a[i];
	for(j=num;j>0;j--)
	{
		for(i=0;i<=j-2;i++)
			if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		cout << a[j-1] << " ";
	}
}
template<typename T>
void Swap(T x,T y)
{
	T temp;
	temp=x;
	x=y;
	y=temp;
}
