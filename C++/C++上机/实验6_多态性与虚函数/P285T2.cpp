//sy6_2.cpp
#include<iostream>
using namespace std;

class Base
{
public:
	void f(int x){cout << "Base::f(int)" << x << endl;}
	void f(float x){cout << "Base::f(float)" << x << endl;}
	virtual void g(void){cout << "Base::g(void)" << endl;}

};

class Derived:public Base
{
public:
	virtual void g(void){cout << "Derived::g(void)" << endl;}
};

int main()
{
	Derived d;
	Base *pb=&d;
	pb->f(42);
	pb->f(3.14f);
	pb->g();

	return 0;
}



/*
输出结果：
Base::f(int)42
Base::f(float)3.14
Derived::g(void)

*/