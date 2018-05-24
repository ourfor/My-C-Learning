//------------------------实验5------------------------
#include<iostream>
using namespace std;

//------------------------定义类A-----------------------
class A
{

public:
	void seta(int i){a=i;}
	int geta(){return a;}

protected:
	int a;

};

//--------------------------------------------------

class B:public A              //继承A的公有部分
{

public:
	void setb(int i){b=i;}
	int getb(){return b;}
	void show(){cout << "A::a=" << a << endl;}

public:
	int b;

};

//----------------------主函数-----------------------
int main()
{
	B bb;
	bb.seta(6);
	bb.setb(3);
	bb.show();
	cout << "A::a=" << bb.a << endl;
	cout << "B::b=" << bb.b << endl;
	cout << "A::a=" << bb.geta() << endl;
	cout << "B::b=" << bb.getb() << endl;
	return 0;
}
