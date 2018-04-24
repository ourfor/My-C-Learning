//sy4_2.cpp
#include<iostream>
#include<cmath>
using namespace std;

class My
{
public:
	My(double i=0){x=y=i;}
	My(double i,double j){x=i;y=j;}
	My(My&m){x=m.x;y=m.y;}
	friend double dist(My&a,My&b);

private:
	double x,y;
};

double dist(My&a,My&b)
{
	double dx=a.x - b.x;
	double dy=a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main()
{
	My m1,m2(15),m3(13,14);
	My m4(m3);
	cout << "The diatance1:" << dist(m1,m3) << endl;
	cout << "The diatance2:" << dist(m2,m3) << endl;
	cout << "The diatance3:" << dist(m3,m4) << endl;
	cout << "The diatance4:" << dist(m1,m2) << endl;
	return 0;
}
