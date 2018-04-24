//定义一个Student的类，包含score、total、count

#include<iostream>
using namespace std;

//---------------------------------定义Student的类---------------------------------
class Student
{
public:

	static double total;
	static void sum(double score);
	static double average();

	Student(double xx)
	{
		score=xx;
		sum(score);

	}

private:

	double score;
	static int count;
};

//---------------------------------成员函数的定义---------------------------------
void Student::sum(double score)
{
	total += score;
}//sum()

double Student::average()
{
	return total / count;
}//average()

//---------------------------------静态数据成员初始化---------------------------------
double Student::total=0;
int Student::count=3;

//---------------------------------主函数---------------------------------
int main()
{

	Student A(90),B(45),C(66);
	cout << "总分为:" << Student::total << endl;
	cout << "平均分为：" << Student::average() << endl;
	return 0;

}




----------------------------------------------------------------------------------------------------------
	/*
	
//------------------------------------------计算两个类里面weight的和-------------------------------------------------------
#include<iostream>
using namespace std;

//-----------------------------------------定义第一个类BOOK------------------------------------------------
class Ruler;
class Book
{
private:
	double weight;
	friend void totalweight(Book&a,Ruler&x);
public:
	Book(double input_weight){weight=input_weight;}

};

//-----------------------------------------定义第二个类RULER------------------------------------------------
class Ruler
{
private:
	double weight;

public:
	Ruler(double input_weight){weight=input_weight;}
	friend void totalweight(Book&a,Ruler&x);
};

//--------------------------------------------友元函数-------------------------------------------------------
void totalweight(Book&a,Ruler&x)
{
	double totalweight;
	totalweight=a.weight + x.weight;
	cout << "Book和Ruler的总质量之和为：" << totalweight << endl;
}

//----------------------------------------------主函数--------------------------------------------------------
int main()
{
	Book X(10);
	Ruler M(8);
	totalweight(X,M);
	return 0;
}

*/

