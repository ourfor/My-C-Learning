//pointer.cpp -- using pointer
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	double x,y;
	cout << "请输入a,b的值，用空格隔开：";
	cin >> x >> y;
	if(x>y)
	{
		swap(x,y);
	}
	cout << "\n";
	cout << "x,y中的最大值为" << y << ",最小值为" << x << endl;
	cout << "该程序将会帮助你求一元二次方程的根，其中二次项系数为a，一次项系数为b,常数项系数为c." << " 用空格隔开" << endl;
	double a,b,c;
	cin >> a >>b >> c;
	if(a == 0) cout << "该不会是个傻逼吧？";
	if(a != 0) 
	{
		double status;
		double * p_customer;
		p_customer=&status;
		* p_customer=pow(b,2) - 4 * a * c;
		if(status < 0)  cout << "该方程没有实数根" << endl;
		if(status == 0)
		{
			double root_1,root_2;
			root_1 = root_2 = -b/(2 * a);
			cout << "该方程有两个相等的实数根，为root=" << root_1 << "\n";
		}
		else
		{
            double status_sqrt;
            status_sqrt = sqrt(status);
            double root_1,root_2;
            root_1 = -(b + status_sqrt)/(2 * a);
            root_2 = -(b - status_sqrt)/(2 * a);
            cout << "该方程有两个不相等的实数根，分别为root_1=" << root_1 << " root_2=" << root_2 << endl;
		}

	}
	return 0;
 
	
}
void swap(double x,double y)
{
	double z;
	z=x;
	x=y;
	y=z;
}