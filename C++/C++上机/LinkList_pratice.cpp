//单链表的初始化、赋值、插入、删除、查询以及销毁 ------------------------LinkList.cpp
#include<iostream>
using namespace std;

//状态代码
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//Status就是int,ElemType就是double
typedef int Status;
typedef double ElemType;

//定义结构体
typedef struct{
      ElemType data;
      LinkList * next;
}LinkList;

//初始化链表
Status InitList(LinkList &T)
{
  L=(LinkList)malloc(sizeof(LinkList));
  L->next=NULL;
}
