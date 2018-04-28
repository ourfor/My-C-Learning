//c++ 116页第5题源代码。
#include<iostream>

using namespace std;

class A
{
public:

	A(int i,int j){a=i;b=j;}
	void move(int x,int y){a += x;b += y;}
	void disp()
	{
		cout << "(" << a << "," << b << ")" << endl;
	}

private:

	int a,b;

};

class B:public A
{
public:

	B(int i,int j,int k,int l):A(i,j),x(k),y(l){}
	void disp()
	{
		cout << x << "," << y << endl;
	}
	void fun1(){move(13,15);}
	void fun2(){A::disp();}

private:

	int x,y;

};


int main()
{
	A aa(11,22);
	aa.disp();
	B bb(13,14,15,16);
	bb.fun1();
	bb.A::disp();
	bb.B::disp();
	bb.fun2();

	return 0;
}

/*
输出结果：
(11,22)
(26,29)
15,16
(26,29)









*/













