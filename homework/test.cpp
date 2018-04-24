#include<iostream>
using namespace std;

class Test
{
	private:
		int num;
	public:
		Test();
		Test(int n);

};
Test::Test()
{
	cout << "Init defa" << endl;
	num=0;
}
Test::Test(int n)
{
	cout << "Init" << " " << n << endl;
	num=n;
}
int main()
{
	Test x[2];
	Test y(15);
}