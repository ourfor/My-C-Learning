//队列的初始化、入队和出队
#include<iostream>
#include<cstdlib>

using namespace std;

//====================================定义状态代码====================================
#define FALSE 0
#define ERROR 0
#define OK 1
#define TRUE 1
#define INFEASIBLE -1
#define OVERFLOW -2


//====================================类型定义====================================
typedef int Status;
typedef double QElemType;

//------------------------------定义结点结构体------------------------------
typedef struct Node{
	QElemType data;
	struct Node *next;
}QNode;

//====================================定义队列====================================
typedef struct Queue{
	struct Node *front;
	struct Node *rear;
}Queue;

Queue Q;

//------------------------------初始化队列------------------------------

Status InitQueue(Queue &Q)
{
	Q.front=Q.rear=(Node *)malloc(sizeof(Node));
	if(!Q.front) exit(OVERFLOW);
	Q.front->next=NULL;
	cout << "队列初始化成功！" << endl;
	return OK;
}


//------------------------------入队------------------------------

Status EnQueue(Queue &Q)
{
	Node *p,*r;
	char stop_input='\0';
	cout << "输入队列中的元素(元素彼此用空格隔开):" << endl;
	p=(Node *)malloc(sizeof(Node));	
	for(Q.front->next=p;stop_input!='\n';)
	{	
		cin >> p->data;
		stop_input=cin.get();
		r=p;
		p=(Node *)malloc(sizeof(Node));
		r->next=p;		
	}
	Q.rear=r->next;

	return OK;
}


//------------------------------出队------------------------------

Status OutQueue(Queue Q)
{
	Node *p=Q.front->next;
	cout << "队列中有元素:\n"; 
	for(;p!=Q.rear;p=p->next)
	{
		cout << p->data << " ";
	}

	return OK;
}

//------------------------------元素插入------------------------------

Status InsertQueue(Queue &Q,QElemType e)
{
	Node *p;
	p=(Node *)malloc(sizeof(Node));
	Q.rear->next=p;
	Q.rear->data=e;
	Q.rear=p;

	return OK;
}

//------------------------------输入待插入的元素------------------------------

Status GetQueue(Queue &Q)
{
	char stop_input='\0';
	cout << "\n" << "输入待插入的元素:\n";
	for(QElemType e=0;stop_input!='\n';)
	{		
		cin >> e;
		stop_input=cin.get();
		InsertQueue(Q,e);
	}


	return OK;
}

//------------------------------主函数------------------------------

int main()
{

	InitQueue(Q);
	EnQueue(Q);
	OutQueue(Q);
	GetQueue(Q);
	OutQueue(Q);

	return 0;
}






















