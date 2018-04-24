//链表的初始化、插入、删除、查找以及销毁
#include<iostream>
#include<stdlib.h>
using namespace std;

//-------------------------状态代码-------------------------
#define    OK      1
#define    TRUE    1
#define    ERROR   0
#define    FALSE   0
#define    INFEASIBLE    -1
#define    OVERFLOW      -2


//-------------------------定义状态名和元素类型-------------------------
typedef int Status;
typedef double ElemType;

//-------------------------定义结构体-------------------------
typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode;

LNode *head;


//-------------------------初始化链表-------------------------
Status InitList(LNode * &head)
{
	head=(LNode *)malloc(sizeof(struct LNode));
	head->next=NULL;
	return OK;
}

//-------------------------输入链表-------------------------
Status InputList(LNode * &head)
{
	LNode *p,*r;
	p=r=(LNode *)malloc(sizeof(struct LNode));	
	cout << "输入链表中的元素：";
	cin >> p->data;
	char stop;
	stop=cin.get();
	int n=0;
	while(stop!='\n')
	{
		n=n+1;
		if(n==1)head->next=p;
		else 
		{
			r=p;
			p=(struct LNode *)malloc(sizeof(struct LNode));
			cin >> p->data;
			stop=cin.get();
			r->next=p;
			
		}
		
	}

	p->next=NULL;
	return OK;
}

//-------------------------输出链表-------------------------
Status DisplayList(LNode *head)
{
	LNode *p;
<<<<<<< HEAD
	/*for(p=head->next;p->next!=NULL;p=p->next)
	{
		cout << p->data << " ";

	}
	*/
=======
>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
	p=head->next;
	do{
		cout << p->data << " ";
		p=p->next;
	}while(p->next!=NULL);
	cout << p->data << "\n";
	return OK;
}

//-------------------------查找链表元素-------------------------
Status LocateList(LNode *head)
{
	cout << "你想查找链表中的哪个元素：";
	ElemType e;
	cin >> e;
	LNode *p;
	int n=0;
	for(p=head->next;p->data!=e&&p->next!=NULL;p=p->next)
	{
		n=n+1;
	}
	if(p->data!=e&&p->next==NULL) {cout << "链表中不存在元素" << e << endl;return FALSE;}
	if(p->data==e) {n=n+1;cout << e << "是链表中的第" << n << "个元素" << endl;}
	else cout << e << "是链表中的第" << n << "个元素" << endl;
	return OK;

}

//-------------------------链表元素的插入-------------------------
Status InsertLNode(LNode * &head)
{
	cout << "你想将元素插入到链表的哪个位置：";
	int i;
	cin >> i;
	ElemType e;
	while(i<=0)
	{
		cout << "插入位置不对，请输入有效的插入位置：";
		cin >> i;
	}
	cout << "插入什么元素：";
	cin >> e;
	LNode *p=head->next;
	for(int n=2;n<=i-1;n++)
	{
		p=p->next;
		if(p==NULL) break;
	}
	LNode *r;
	r=(LNode *)malloc(sizeof(LNode));
	r->data=e;
	r->next=p->next;
	p->next=r;
	DisplayList(head);
	return OK;
}

//-------------------------链表元素的删除-------------------------
Status DeleteLNode(LNode * &head)
{
	if(head->next==NULL) {cout << "链表为空" << endl;return ERROR;}
	cout << "你想删除哪个元素：";
	ElemType e;
	cin >> e;
	LNode *p,*r;
	for(p=head;p->data!=e&&p->next!=NULL;)
	{
                r=p;
		p=p->next;
	}
	if(p->data==e)
	{
		r->next=(p->next);
                DisplayList(head);
                return OK;
	}
	if(p->next==NULL){cout << "不存在要删除的元素" << e << endl;return ERROR;}
	r->next=p->next;
	cout << "已将元素删除" << endl;
	DisplayList(head);
	return OK;
}

//-------------------------链表就地转置-------------------------
Status UnsLinklist(LNode * &head)
{
	LNode *p,*r,*first=head->next;
        cout << "将链表就地转置为：\n";
	for(p=head->next;p->next!=NULL;)
	{
		r=p->next;
		p->next=head->next;
		head->next=p;
		p=r;
	}
	p->next=head->next;
	head->next=p;
	first->next=NULL;
	
	DisplayList(head);
        return OK;
}

//-------------------------主函数-------------------------
int main()
{
	InitList(head);
	InputList(head);
	DisplayList(head);
	LocateList(head);
	InsertLNode(head);
	DeleteLNode(head);
	UnsLinklist(head);
	return 0;
}


















