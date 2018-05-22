//sy6_1.cpp
#include<iostream>
using namespace std;
class Base
{
public:
	virtual void f(float x){cout << "Base::f(float)" << x << endl;}
	void g(float x){cout << "Base::g(float)" << x << endl;}
	void h(float x){cout << "Base::h(float)" << x << endl;}
};

class Derived:public Base
{
public:
	virtual void f(float x){cout << "Derived::f(float)" << x << endl;}
	void g(int x){cout << "Derived::g(int)" << x << endl;}
	void h(float x){cout << "Derived::h(float)" << x << endl;}
};

int main()
{
	Derived d;
	Base *pb=&d;
	Derived *pd=&d;
	pb->f(3.14f);
	pd->f(3.14f);
	pb->g(3.14f);
	pb->h(3.14f);
	pd->h(3.14f);

	return 0;
}


/*
输出结果：
Derived::f(float)3.14
Derived::f(float)3.14
Base::g(float)3.14
Base::h(float)3.14
Derived::h(float)3.14
*/

#include<iostream>
using namespace std;
class complex
{
public:
	complex(){real=imag=0.0;}
	complex(double r){real=r;imag=0.0;}
	complex(double r,double i){real=r;imag=i;}
	complex operator + (const complex &c);
	complex operator - (const complex &c);
	complex operator * (const complex &c);
	complex operator / (const complex &c);
	friend void print(const complex &c);
private:
	double real,imag;
};

inline complex complex::operator + (const complex &c)
{
	return complex(real + c.real,imag + c.imag);
}

inline complex complex::operator - (const complex &c)
{
	return complex(real - c.real,imag - c.imag);
}

inline complex complex::operator * (const complex &c)
{
	return complex(real * c.real - imag * c.imag,real * c.imag - imag * c.real);
}

inline complex complex::operator / (const complex &c)
{
	return complex((real * c.real + imag * c.imag)/(c.real * c.real + c.imag * c.imag),(imag * c.real - real * c.imag)/(c.real * c.real + c.imag * c.imag));
}

void print(const complex &c)
{
	if(c.imag<0)
		cout << c.real << c.imag << "i";
	else 
		cout << c.real << "+" << c.imag << "i";
}

int main()
{
	complex c1(2.0),c2(3.0,-1.0),c3;
	c3=c1 + c2;
	cout << "\nc1 + c2";
	print(c3);
	c3=c1 - c2;
	cout << "\nc1 - c2";
	print(c3);
	c3=c1 * c2;
	cout << "\nc1 * c2";
	print(c3);
	c3=c1 / c2;
	cout << "\nc1 / c2";
	print(c3);
	c3=(c1 + c2) * (c1 - c2) * c2 / c1;
	cout << "\n(c1 + c2) * (c1 - c2) * c2/c1 =";
	print(c3);
	cout << endl;
	return 0;

}
