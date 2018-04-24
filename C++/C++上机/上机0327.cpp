#include<iostream>
void func(int);
using namespace std;
int main()
{
	int num;
	cout << "输入需要排序的数字的个数：";
	cin >> num;
	func(num);
	return 0;
}

void func(int num)
{
	double a[num];
	cout << "输入这些需要排序的数字：";
	for(int i=0;i<=num-1;i++)
		cin >> a[i];
	for(int i=0,j=num;j>0;j--){
		for(i=0;i<=j-2;i++)
			if(a[i]>a[i+1]) swap(a[i],a[i+1]);
		cout << a[j-1] << " ";
	}
}





//Pratice using class
#include<iostream>
using namespace std;
//-------------------------类的定义-------------------------
class Area
{
	public:
		void input();
		void display();
        void calcul();

		double side;     //³¤
		double width;    //¿í
		double height;   //¸ß
		double area_s;   //Ãæ»ý
		double area_v;   //Ìå»ý

};
//-------------------------输入部分-------------------------
void Area::input()
{
	cout << "ÊäÈë³¤¡¢¿í¡¢¸ß£º";
	cin >> side >> width >> height;
}
//-------------------------输出部分-------------------------
void Area::display()
{
	cout << "Ãæ»ýÎª" << area_s << "£¬Ìå»ýÎª" << area_v;
}
//-------------------------计算部分-------------------------
void Area::calcul()
{
        area_s=side * width;
        area_v= side * width * height;
}

//-------------------------主函数-------------------------
int main()
{
	Area T;
	T.input();
        T.calcul();
	T.display();
	return 0;
}




#include<iostream>
int max();
using namespace std;
class Student{
    public:
    double id;
    double score;

};

int main()
{
    Student a[5];
    int i;
    for(i=0;i<=4;i++)
    {
        cout << "请输入第" << i+1 << "同学的学号以及成绩：";
        cin >> a[i].id >> a[i].score;
        cin.get();
    }

    int s;
    s=max();


    cout << "分数最高者的学号是" << a[s].id;


    return 0;

}

int max()
{
    int max;
    Student a[5];
    int max_sign;
    max=a[0].score;
    int i;
    for(i=0;i<5;i++)
    {
        if(a[i].score>max)
        {
            max=a[i].score;
            max_sign=i;
        }

    }
    return max_sign;
}
