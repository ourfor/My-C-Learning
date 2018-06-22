#include<iostream>
#include<cstdio>
using namespace std;

//结点结构体定义
typedef struct Node{
	double data;
	struct Node *next;
}Node,*Linklist;

//初始化链表
int InitLinklist(Linklist &T)
{
	T=(Linklist)malloc(sizeof(Node));
	if(T) cout << "链表初始化成功\n";

	return 0;
}

//建立链表
int Create(Linklist &T,int num)
{
	if(!(T=(Linklist)malloc(sizeof(Node)))) exit(-2);
	Linklist p=T,q;
	for(int i=0;i<num;i++)
	{
		q=p;
		p=(Linklist)malloc(sizeof(Node));
		cin >> p->data;
		q->next=p;
	}
	cout << (T->next)->data;
	p=NULL;
	return 0;
}

//打印链表
int Display(Linklist T)
{

	Linklist p=T->next;
	for(;p!=NULL;p=p->next)
	{
		cout << p->data << " ";
	}

	return 0;

	
}

int main()
{
	Linklist T;
	InitLinklist(T);
	cout << "输入链表中的元素个数：\n";
	int num;
	cin >> num;
	cout << "输入链表中的元素：\n";
	Create(T,num);
	cout << "链表中的元素有：\n";
	Display(T);



	return 0;
}
