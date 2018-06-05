#include <iostream>
 using namespace std;
 #include <malloc.h>
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define OVERFLOW -2
 typedef  int Status; 
 typedef int ElemType;
 typedef  struct  LNode {
     ElemType  data ;
     struct  LNode *next ;
} LNode, *LinkList ;
Status GetElem_L ( LinkList L, int i, ElemType &e ) 
{  
    LinkList p;
    int j; 
    p=L->next;
    j=1;
    while(p && j<i)
    {
      p=p->next;
      j++;
    } 
   if ( !p || j>i ) 
    return ERROR;
}  
Status ListInsert_L ( LinkList &L, int i , ElemType e ) {
     // 在带头结点的单链表L中第i个数据元素之前插入数据元素e 
    LinkList p,s;
    int j=0;
    p=L;   
    while(p && j<i-1)
    {
      p=p->next;
      j++;
    } 
    if ( !p || j>i ) 
        return ERROR;
    s=(LinkList)malloc(sizeof(LNode));
    s->data=e; s->next= p->next ;
     p->next =s ;
     return OK;
} 

Status ListDelete_L ( LinkList &L, int i , ElemType &e ) {
     // 在带头结点的单链表L中，删除第i个元素，并由e返回其值 
     LinkList p,q;
     int j=0;
    while(p && j<i-1)
    {
      p=p->next;
      j++;
    } 
    if ( !p || j>i-1 ) 
        return ERROR;
    q=p->next;
    p->next=q->next;
    e=q->data;
    free(q);
    return OK;
} 

void  CreateList_L (LinkList &L, int n) {
    //逆位序输入n个元素的值，建立带头结点的单链表L。
    LinkList p;
    L->next=(LinkList) malloc(sizeof(LNode)) ;
    L->next=NULL;
    for( int i=n; i>0; --i) 
    {
         p= (LinkList) malloc(sizeof(LNode)) ;
         cin>>p->data;
         p->next=L->next;
         L->next=p;
     }
} 


void print(LinkList L)
{
	LinkList p;
	p=L->next;
	while(p)
	{
		cout<<p->data;
		p=p->next;
	}
}
int main()
 {
   LinkList L;
   ElemType e;
   int i,n,t;
   cout<<"您要在表中插入几个元素：";
   cin>>n;
   CreateList_L(L,n);
   cout<<"目前表中元素为：";
   print(L);

   cout<<"请输入您要查询元素的位置：";
   cin>>i;
   GetElem_L(L,i,e); 
   cout<<"元素值为:"<<e<<endl;
   
   cout<<"请输入您要删除元素的位置：";
   cin>>i;
   ListDelete_L(L,i,e); 
   if(t==ERROR)
       cout<<"删除第"<<i<<"个数据失败"<<endl;
     else
       cout<<"删除第"<<i<<"个的元素值为"<<e<<endl;
   cout<<"目前表中元素为：";
   print(L);
   system("PAUSE");
   return 1;
 }
