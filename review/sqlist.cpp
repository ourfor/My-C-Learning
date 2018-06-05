
 #include <iostream>
 using namespace std;
 #include <malloc.h>
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define OVERFLOW -2
 typedef  int Status; /* int�Ǻ���������,��ֵ�Ǻ������״̬���룬��OK�� */
 #define LIST_INIT_SIZE 10 /* ���Ա�洢�ռ�ĳ�ʼ������ */
 #define LISTINCREMENT 2 /* ���Ա�洢�ռ�ķ������� */
 typedef int ElemType;
 typedef struct
 {
   ElemType *elem;
   int length;
   int listsize;
 }SqList;



Status InitList(SqList  &L) /* �㷨2.3 */
 {
   L.elem=(int*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
   if(!L.elem)
     exit(OVERFLOW);
   L.length=0;
   L.listsize=LIST_INIT_SIZE;
   return OK;
 }



  Status ListInsert(SqList &L, int i ,ElemType e) /* �㷨2.4 */
 { int *newbase,*q,*p;
   if(i<1||i>L.length+1) /* iֵ���Ϸ� */
     return ERROR; 
   if(L.length>=L.listsize) /* ��ǰ�洢�ռ�����,���ӷ��� */
   {
     newbase=(int *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
     if(!newbase)
       exit(OVERFLOW); /* �洢����ʧ�� */
     L.elem=newbase; /* �»�ַ */
     L.listsize+=LISTINCREMENT; /* ���Ӵ洢���� */
   }
   q=L.elem+i-1; /* qΪ����λ�� */
   for(p=L.elem+L.length-1;p>=q;--p) /* ����λ�ü�֮���Ԫ������ */
     *(p+1)=*p;
   *q=e; /* ����e */
   ++L.length; /* ����1 */
   return OK;
 }

 Status ListDelete(SqList &L,int i,ElemType &e) /* �㷨2.5 */
 {
   int *p,*q;
   if(i<1||i>L.length) /* iֵ���Ϸ� */
     return ERROR;
   p=L.elem+i-1; /* pΪ��ɾ��Ԫ�ص�λ�� */
   e=*p; /* ��ɾ��Ԫ�ص�ֵ����e */
   q=L.elem+L.length-1; /* ��βԪ�ص�λ�� */
   for(++p;p<=q;++p) /* ��ɾ��Ԫ��֮���Ԫ������ */
     *(p-1)=*p;
   L.length--; /* ����1 */
   return OK;
 }

  int LocateElem(SqList L, ElemType e)        /* �㷨2.6*/
 {
   int *p;
   int i=1;
   p=L.elem; /* p�ĳ�ֵΪ��1��Ԫ�صĴ洢λ�� */
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
   cout<<"��Ҫ�ڱ��в��뼸��Ԫ�أ�";
   cin>>n;
   for(i=1;i<=n;i++)
   {
     cin>>e;
     ListInsert(L,i,e);
   }
   cout<<"Ŀǰ����Ԫ��Ϊ��";
   print(L);

   cout<<"��������Ҫ��ѯ��ֵ��";
   cin>>e;
   i=LocateElem(L,e);
   if(i==0)
      cout<<"����ʧ��"<<endl;
   else 
      cout<<e<<"�ڱ��е�λ��Ϊ:"<<i<<endl;
   
   cout<<"��������Ҫɾ��Ԫ�ص�λ�ã�";
   cin>>i;
   t=ListDelete(L,i,e); /* ɾ����j������ */
   if(t==ERROR)
       cout<<"ɾ����"<<i<<"������ʧ��"<<endl;
     else
       cout<<"ɾ����"<<i<<"����Ԫ��ֵΪ"<<e<<endl;
   cout<<"Ŀǰ����Ԫ��Ϊ��";
   print(L);
   system("PAUSE");
   return 1;
 }
