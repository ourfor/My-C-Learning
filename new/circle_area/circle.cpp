/*
 * 类的实现文件
 */

#include <iostream>
using namespace std;
#include "circle.h"
#define PI 3.1415

Circle::Circle(){}

Circle::Circle(double radius_i){radius=radius_i;}

void Circle::Display()
{
	cout << "圆的半径为" << radius << endl;
	cout << "圆的面积为" << area << endl; 
}

void Circle::Calculate()
{
	area= PI * radius * radius;
}
