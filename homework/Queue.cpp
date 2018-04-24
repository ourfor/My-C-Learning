//数据结构作业
#include<iostream>
#include<cstdlib>

using namespace std;

//-------------------------定义队列-------------------------
typedef struct Queue{
	double data;
	struct Queue *next;
}Queue;

Queue *T;


//-------------------------初始化队列-------------------------
int InitQueue(Queue *T)
{
	T=(Queue *)malloc(sizeof(Queue));
	if(!T) exit(-2);
	T->next=T;
	return 0;
}


//-------------------------主函数-------------------------
int main()
{
	InitQueue(T);
	return 0;
}