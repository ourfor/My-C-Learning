/*用于计算圆的周长和面积，从一个简单的小程序开始，同时联系头文件、类的声明、类的实现以及类的调用
 * author:曾谞旺
 * date:2018年7月24日
 * 编程语言：c/c++
 */

#ifndef CIRCLE_H
#define CIRCLE_H

//圆类
class Circle
{
	public:
		Circle();
		Circle(double);
		void Display();
		void Calculate();
	private:
		double radius;
		double area;
};

#endif
