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
 typedef int QElemType;
 typedef  struct  QNode {
     QElemType  data ;
     struct  QNode *next ;
} QNode, *Queueptr ;
typedef struct  {
     Queueptr   front;
     Queueptr   rear ;
  } Lqueue ;

Status InitQueue(Lqueue &Q )
 {
   Q.front=Q.rear=(Queueptr)malloc(sizeof(QNode));
   if (!Q.front) exit (OVERFLOW) ;
   Q.front->next=NULL ;
   return OK;
  }

 Status Enqueue(Lqueue &Q,QElemType e )
 {
   Queueptr p;
   p=(Queueptr)malloc(sizeof(QNode));
   if (!p) exit (OVERFLOW) ;
   p->data=e ; p->next=NULL ;
   Q.rear->next=p; Q.rear=p;
   return OK;
  }

Status Dequeue(Lqueue &Q,QElemType &e )
 {
   Queueptr p;
   if (Q.front==Q.rear) return ERROR;
   p=Q .front->next ;   e=p->data;
   Q.front->next=p->next;
   if (Q.rear==p)  Q.rear=Q.front;
   free(p);
   return OK;
  }

int Locate (Lqueue Q, QElemType e )
{
    Queueptr p;
    int i;
    p=Q.front->next;
    i=1;
    while(p && p->data!=e)
    {
      p=p->next;
      i++;
    }
   if ( p )
    return i;
   else
    return 0;
}


void print(Lqueue Q)
{
	Queueptr p;
	p=Q.front->next;
	while(p)
	{
		cout<<p->data<<"  ";
		p=p->next;
	}
	cout<<endl;
}
int main()
 {
   Lqueue Q;
   QElemType e;
   int i,n,t;
   InitQueue(Q);
   cout<<"��Ҫ�ڶ����в��뼸��Ԫ�أ�";
   cin>>n;
   for(i=1;i<=n;i++)
   {
       cin>>e;
       Enqueue(Q,e);
   }
   cout<<"Ŀǰ������Ԫ��Ϊ��";
   print(Q);

   cout<<"��������Ҫ��ѯ��Ԫ��";
   cin>>e;
   t=Locate(Q,e);
   if(t==0)
       cout<<e<<"���ڶ�����"<<endl;
   else
      cout<<e<<"�Ƕ����еĵ�"<<t<<"��Ԫ��"<<endl;

   Dequeue(Q,e);
   cout<<e<<"����"<<endl;
   cout<<"Ŀǰ������Ԫ��Ϊ��";
   print(Q);
   system("PAUSE");
   return 1;
 }
