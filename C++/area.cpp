//area.cpp -- length width side area
#include<iostream>
using namespace std;
int main()
{
  cout << "Please tell me the length and width.";
  double length,width;
  double area;
  cin >> length >> width;
  area = length * width;
  cout << " The area is " << area << endl;
  return 0;
}
