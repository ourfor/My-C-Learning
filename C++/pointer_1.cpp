//pointer_1.cpp --practice using pointer
#include<iostream>
using namespace std;
void showmenu();
int main()
{
	int * p_number,a,b;
	a=7;
	b=78;
	p_number=&a;
	* p_number=123;
	cout << "a=" << a << endl;
	cout << "p_number=\n" << p_number <<endl;
	showmenu();
	int chose;
	cin >> chose;
	switch(chose)
    {
	int x;
	case 1 : cout << "sudo apt-get install gcc && sudo apt-get install g++";
	break;
	case 2 : cout << "sudo apt-get install choco && sudo apt-get update";
	break;
	case 3 : cout << "sudo apt-get install nodejs && sudo apt-get install git";
	break;
	case 4 : cout << "return";
	break;
    }
	return 0;
}
void showmenu()
{
	cout << "Please enter the number you chose:\n"
	"1)install gcc/g++         2)install choco\n"
	"3)install nodejs and git  4)return\n";
}
