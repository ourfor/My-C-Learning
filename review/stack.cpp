
 #include <iostream>
 using namespace std;
 #include <stdio.h>
 #include <malloc.h>
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define OVERFLOW -2
 typedef  int Status;
 #define  STACK_INIT_SIZE   100
 #define  STACKINCREMENT  10
 typedef int SElemType;
 typedef   struct {
    SElemType   *base ;
    SElemType   *top ;
     int       stacksize ;
 } SqStack;



 Status InitStack(SqStack &s )
 {
  s.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof( SElemType));
  if  (!s.base) exit (OVERFLOW) ;
  s.top=s.base ;
  s.stacksize=STACK_INIT_SIZE ;
  return  OK;
 }

 Status Push (SqStack &s, SElemType e)
 {
    if (s.top-s.base >= s.stacksize)
    {
        s.base=(SElemType*)realloc(s.base,(s.stacksize+STACKINCREMENT)*sizeof(SElemType));
        if (!s.base) exit (OVERFLOW);
        s.top=s.base+ s.stacksize;
        s.stacksize+= STACKINCREMENT ;
    }
   *s.top++=e ;
   return OK;
}

 Status Pop (SqStack &s, SElemType &e)
 {
    if (s.top==s.base) return ERROR ;
    e=*--s.top ;
    return OK ;
 }

 Status StackEmpty(SqStack s )
 {
   if (s.top==s.base)  return  1;
   else  return  0;
 }

 void conversion(int N,int d)
 {
   SqStack  s;
   int  x;
   InitStack(s);
   while( N )  {
       Push (s,N % d );
       N=N / d ;
   }
   cout<<"转换后的数值为：";
   while(!StackEmpty (s))
    {
       Pop (s,x ) ;
       if(d==16)
       {
           if(x>=10)
             printf("%c",x-10+'A');
           else
             cout<<x;
       }
       else cout<<x ;
    }
}


int main()
 {

   int n,d;

   cout<<"您要把哪个整数转化为几进制：";
   cin>>n>>d;
   conversion(n,d);
   system("PAUSE");
   return 1;
 }