//Practice Structure
#include<iostream>
using namespace std;
/*struct Student{
	int id;
	char name;
	char sex;
}student1,student2;*/
int main()
{
	/*struct Student student1,student2;
	cout << "输入学生的各项信息(id name sex):";
	cin >> student1.id >> student1.name >> student1.sex;
	cout << "输入下一个";
	cin >> student2.id >> student2.name >> student2.sex;
	*/
	int sum(int x,int y);
	double sum(double x,double y,double z);
	double sum1,sum2;
	int a1,a2;
	double b1,b2,b3;
	cout << "输入a1,a2的值：";
	cin >> a1 >> a2;
	cout << "输入b1,b2,b3的值：";
	cin >> b1 >> b2 >> b3;
	sum1=sum(a1,a2);
	sum2=sum(b1,b2,b3);
	cout << sum1;
	cout << endl;
	cout << sum2;
	cout << endl;	
	return 0;
}
int sum(int x,int y)
{
	int z;
	z = x + y;
	return z;
}
double sum(double x,double y,double z)
{
	   double s;
	   s = ( x + y )/z;
	   return s;
}
