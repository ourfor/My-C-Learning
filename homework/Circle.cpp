#include<iostream>
using namespace std;

class Circle
{
public:
	double radius;
	void area();
};

void Circle::area()
{
	double pi=3.14159;
	cout << "输入圆的半径:";
	cin >> radius;
	cout << "圆的面积是" << pi * radius * radius;
}

int main()
{
	Circle S;
	S.area();
	return 0;
}