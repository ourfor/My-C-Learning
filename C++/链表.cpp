//练习链表
#include<iostream>
using namespace std;

//定义链式结构体
struct Student{
	double data;
	int id;
	char name;
	struct Student *next;
};

int main()
{
	Student a,b,c,*head,*p;
	head=&a;
	a.next=&b;
	b.next=&c;
	c.next=NULL;
	int i=1;
	for(p=head;p!=NULL;p=p->next,i++)
	{
		cout << "输入第" << i << "名同学的生日、学号以及名字：";
		cin >> p->data >> p->id >> p->name;
		cin.get();
	}

	for(p=head;p!=NULL;p=p->next)
	cout << p->name << "生日是" << p->data << "学号是" << p->id << endl;
	return 0;  

}