#include<iostream>
using namespace std;

class Xx
{
private:
	int num;
public:
	Xx(int x){num=x;}
	~Xx(){cout << "dst" << num << endl;}
};
int main()
{
	Xx w(5);
	cout << "Exit main" << endl;
	return 0;
}