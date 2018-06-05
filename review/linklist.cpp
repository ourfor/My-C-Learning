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
     // �ڴ�ͷ���ĵ�����L�е�i������Ԫ��֮ǰ��������Ԫ��e 
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
     // �ڴ�ͷ���ĵ�����L�У�ɾ����i��Ԫ�أ�����e������ֵ 
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
    //��λ������n��Ԫ�ص�ֵ��������ͷ���ĵ�����L��
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
   cout<<"��Ҫ�ڱ��в��뼸��Ԫ�أ�";
   cin>>n;
   CreateList_L(L,n);
   cout<<"Ŀǰ����Ԫ��Ϊ��";
   print(L);

   cout<<"��������Ҫ��ѯԪ�ص�λ�ã�";
   cin>>i;
   GetElem_L(L,i,e); 
   cout<<"Ԫ��ֵΪ:"<<e<<endl;
   
   cout<<"��������Ҫɾ��Ԫ�ص�λ�ã�";
   cin>>i;
   ListDelete_L(L,i,e); 
   if(t==ERROR)
       cout<<"ɾ����"<<i<<"������ʧ��"<<endl;
     else
       cout<<"ɾ����"<<i<<"����Ԫ��ֵΪ"<<e<<endl;
   cout<<"Ŀǰ����Ԫ��Ϊ��";
   print(L);
   system("PAUSE");
   return 1;
 }
