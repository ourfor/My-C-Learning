#include<iostream>
using namespace std;



void Swap(int &Num_u,int &Num_d)
{
	if(Num_u>Num_d)                 //确保Num_d>=Num_u
	{
		int temp=Num_u;
		Num_u=Num_d;
		Num_d=temp;
	}

}

//分数类的定义
class fraction
{
public:
	
	int MaxNum(int a,int b);
	fraction(int u_,int d_){num_u=u_;num_d=d_;}
	fraction(){num_u=0;num_d=0;}
	void Display();
	void Sample();

	//运算符重载
	int operator == (fraction a1);
	friend fraction operator + (fraction a1,fraction a2);
	friend fraction operator - (fraction a1,fraction a2);
	friend fraction operator * (fraction a1,fraction a2);
	friend fraction operator / (fraction a1,fraction a2);

private:
	int num_u;                 //分子
	int num_d;				   //分母

};

int fraction::MaxNum(int a,int b)
{
	Swap(a,b);
	if(a==0) return b;
	return MaxNum(b-a,a);
}

void fraction::Display()
{
	Sample();
	if(num_u==0) cout << "0" << endl;
	else
	{
		if(num_d==1&&num_u!=0) cout << num_u << endl;
		else cout << num_u << "/" << num_d << endl;
	}
	
}

void fraction::Sample()
{
	int b=MaxNum(num_u,num_d);
	num_u=num_u / b;
	num_d=num_d /b;
}


int fraction::operator == (fraction a1)
{
	int d;
	d=MaxNum(num_d,num_u);
	num_u=num_u / d;
	num_d=num_d / d;
	d=MaxNum(a1.num_d,a1.num_u);
	a1.num_u=a1.num_u / d;
	a1.num_d=a1.num_d / d;
	if(a1.num_u==num_u&&a1.num_d==num_d) return 1;
	return 0;
}

fraction operator + (fraction a1,fraction a2)
{
	fraction c;
	c.num_d=a1.num_d * a2.num_d;
	c.num_u=a1.num_u * a2.num_d + a2.num_u *a1.num_d;
	return c;
}

fraction operator - (fraction a1,fraction a2)
{
	fraction c;
	c.num_d=a1.num_d * a2.num_d;
	c.num_u=a1.num_u * a2.num_d - a2.num_u *a1.num_d;
	return c;
}

fraction operator * (fraction a1,fraction a2)
{
	fraction c;
	c.num_d=a1.num_d * a2.num_d;
	c.num_u=a1.num_u * a2.num_u;
	return c;
}

fraction operator / (fraction a1,fraction a2)
{
	fraction c;
	c.num_d=a1.num_d * a2.num_u;
	c.num_u=a1.num_u * a2.num_d;
	return c;
}


int main()
{
	fraction c(12,72);
	c.Display();
	int d=c.MaxNum(12,72);
	cout << d << endl;

	fraction m(1,6);
	if(m==c) cout << "相等\n";

	fraction e;
	e=m + c;
	e.Display();
	e=m - c;
	e.Display();
	e=m * c;
	e.Display();
	e=m / c;
	e.Display();



	return 0;
}




















