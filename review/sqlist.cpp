
 #include <iostream>
 using namespace std;
 #include <malloc.h>
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define OVERFLOW -2
 typedef  int Status; /* int是函数的类型,其值是函数结果状态代码，如OK等 */
 #define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
 #define LISTINCREMENT 2 /* 线性表存储空间的分配增量 */
 typedef int ElemType;
 typedef struct
 {
   ElemType *elem;
   int length;
   int listsize;
 }SqList;



Status InitList(SqList  &L) /* 算法2.3 */
 {
   L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L.elem)
     exit(OVERFLOW);
   L.length=0;
   L.listsize=LIST_INIT_SIZE;
   return OK;
 }



  Status ListInsert(SqList &L, int i ,ElemType e) /* 算法2.4 */
 { int *newbase,*q,*p;
   if(i<1||i>L.length+1) /* i值不合法 */
     return ERROR; 
   if(L.length>=L.listsize) /* 当前存储空间已满,增加分配 */
   {
     newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
     if(!newbase)
       exit(OVERFLOW); /* 存储分配失败 */
     L.elem=newbase; /* 新基址 */
     L.listsize+=LISTINCREMENT; /* 增加存储容量 */
   }
   q=L.elem+i-1; /* q为插入位置 */
   for(p=L.elem+L.length-1;p>=q;--p) /* 插入位置及之后的元素右移 */
     *(p+1)=*p;
   *q=e; /* 插入e */
   ++L.length; /* 表长增1 */
   return OK;
 }

 Status ListDelete(SqList &L,int i,ElemType &e) /* 算法2.5 */
 {
   int *p,*q;
   if(i<1||i>L.length) /* i值不合法 */
     return ERROR;
   p=L.elem+i-1; /* p为被删除元素的位置 */
   e=*p; /* 被删除元素的值赋给e */
   q=L.elem+L.length-1; /* 表尾元素的位置 */
   for(++p;p<=q;++p) /* 被删除元素之后的元素左移 */
     *(p-1)=*p;
   L.length--; /* 表长减1 */
   return OK;
 }

  int LocateElem(SqList L, ElemType e)        /* 算法2.6*/
 {
   int *p;
   int i=1;
   p=L.elem; /* p的初值为第1个元素的存储位置 */
   while(i<=L.length&&(*p++!=e))
     ++i;
   if(i<=L.length)
     return i;
   else
     return 0;
 }
 void print(SqList L)
 {
    int i;
    for(i=0;i<L.length;i++)
      printf("%d ", L.elem[i]);
    printf("\n");
 } 



int main()
 {
   SqList L;
   ElemType e;
   int i,n,t;
   InitList(L);
   cout<<"您要在表中插入几个元素：";
   cin>>n;
   for(i=1;i<=n;i++)
   {
     cin>>e;
     ListInsert(L,i,e);
   }
   cout<<"目前表中元素为：";
   print(L);

   cout<<"请输入您要查询的值：";
   cin>>e;
   i=LocateElem(L,e);
   if(i==0)
      cout<<"查找失败"<<endl;
   else 
      cout<<e<<"在表中的位置为:"<<i<<endl;
   
   cout<<"请输入您要删除元素的位置：";
   cin>>i;
   t=ListDelete(L,i,e); /* 删除第j个数据 */
   if(t==ERROR)
       cout<<"删除第"<<i<<"个数据失败"<<endl;
     else
       cout<<"删除第"<<i<<"个的元素值为"<<e<<endl;
   cout<<"目前表中元素为：";
   print(L);
   system("PAUSE");
   return 1;
 }