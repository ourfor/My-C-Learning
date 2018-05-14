//sy6_3.cpp
#include<iostream>
using namespace std;

class Point
{
public:
	Point(double i,double j){x=i;y=j;}
	double Area(){return 0.0;}
private:
	double x,y;
};

class Rectangle:public Point
{
public:
	Rectangle(double i,double j,double k,double l):Point(i,j){w=k;h=l;}
	double Area(){return w*h;}
private:
	double w,h;
};

int main()
{
	Point p(3.5,7);
	double A=p.Area();
	cout << "Area = " << A << endl;
	Rectangle r(1.2,3,5,7.8);
	A=r.Area();
	cout << "Area = " << A << endl;

	return 0;
}

/*
输出结果：
Area = 0
Area = 39
*/

