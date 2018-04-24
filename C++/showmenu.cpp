//试试showmenu语句
#include<iostream>
using namespace std;
void showmenu();
int main()
{
	int chose;
	showmenu();
	cin >> chose;
	switch(chose)
	{
		
		case 1 : cout << "sudo apt-get install git";
		break;
		case 2 : cout << "sudo apt-get install wget";
		break;
		case 3 : cout << "sudo apt-get install nodejs";
		break;
		case 4 : cout << "sudo apt-get update";
		break;
	}
	return 0;
}
void showmenu()
{
	cout << "请输入数字 1 , 2 , 3 , 4 or 5:\n"
	"1)install git           2)install wget\n"
	"3)install nodejs        3)update       \n";
}