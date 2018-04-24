// myfirst.cpp -- display some messages author sagit software engineering
/*
#include<iostdream>
using namespace std;
int main()
{
    cout << "This is my first C++ language application";
    cout << endl;
    cout << "My email address is 2320813747@qq.com";
    return 0
}
*/
#include <iostream>

using namespace std;

class Box
{
   public:
      double length;         // 长度
      double breadth;        // 宽度
      double height;         // 高度

      // 成员函数声明
      double getVolume(void);
      void setLength( double len );
      void setBreadth( double bre );
      void setHeight( double hei );
};

// 成员函数定义
double Box::getVolume(void)
{
    return length * breadth * height;
}

void Box::setLength( double len )
{
    length = len;
}

void Box::setBreadth( double bre )
{
    breadth = bre;
}

void Box::setHeight( double hei )
{
    height = hei;
}

// 程序的主函数
int main( )
{
   Box Box1;                // 声明 Box1，类型为 Box
   Box Box2;                // 声明 Box2，类型为 Box
   double volume = 0.0;     // 用于存储体积
 
   // box 1 详述
   Box1.setLength(6.0); 
   Box1.setBreadth(7.0); 
   Box1.setHeight(5.0);

   // box 2 详述
   Box2.setLength(12.0); 
   Box2.setBreadth(13.0); 
   Box2.setHeight(10.0);

   // box 1 的体积
   volume = Box1.getVolume();
   cout << "Box1 的体积：" << volume <<endl;

   // box 2 的体积
   volume = Box2.getVolume();
   cout << "Box2 的体积：" << volume <<endl;
   return 0;
}

----- BEGIN LICENSE -----
Country Rebel
Single User License
EA7E-993095
19176BCE 3FF86EA0 3CE86508 6BE4DCA7
9F74D761 4D0CAD8B E4033008 43FC73F3
1C01F6DD C4829BE9 E7830578 A4823ADC
61B224F1 DC93C458 ABAAAE0F 925C32D4
04A83C36 813FF6C8 9877942C 4418F99C
2F15E5B8 544EDB80 D9A86985 4CBBA6A8
998DE3E4 7FB33E15 6CD30357 6DC96CEA
ECB1BC4E D8010D5A 77BA86C8 BA7F76CC
------ END LICENSE ------