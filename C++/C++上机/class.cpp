//Pratice using class
#include<iostream>
using namespace std;

class Area
{
	public:
		void input();
		void display();
        void calcul();

		double side;
		double width;
		double height;
		double area_s;
		double area_v;

};
void Area::input()
{
	cout << "输入长、宽、高：";
	cin >> side >> width >> height;
}
void Area::display()
{
	cout << "面积为" << area_s << "，体积为" << area_v;
}
void Area::calcul()
{
        area_s=side * width;
        area_v= side * width * height;
}
int main()
{
	Area T;
	T.input();
        T.calcul();
	T.display();
	return 0;
}
