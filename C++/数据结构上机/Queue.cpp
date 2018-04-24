//队列的初始化、输入、删除、插入、输出的实现
#include<iostream>
using namespace std;

//－－－－－－－－－－－－－－－－－－预定义状态代码－－－－－－－－－－－－－－－－－－－
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//－－－－－－－－－－－－－－－－－－类型定义－－－－－－－－－－－－－－－－－－－
typedef int Status;
typedef double ElemType;

//－－－－－－－－－－－－－－－－－－定义顺序队列－－－－－－－－－－－－－－－－－－
typedef struct Queue{
  ElemType * front;
  ElemType * rear;
}Queue;
Queue Q;

//－－－－－－－－－－－－－－－－－－队列初始化常量－－－－－－－－－－－－－－－－－－
#define Queue_Init_Size 100
#define Queue_Increasing_Size 10

//－－－－－－－－－－－－－－－－－－队列的初始化－－－－－－－－－－－－－－－－－－－
Status InitQueue(Queue &Q)
{
  Q.front=(ElemType *)malloc(Queue_Init_Size * sizeof(ElemType));
  if(!Q.front) exit(OVERFLOW);
  Q.rear=Q.front;
  return OK;
}
//－－－－－－－－－－－－－－－－－－输入－－－－－－－－－－－－－－－－－－－－－－－
Status InputQueue(Queue &Q)
{
    cout << "输入你想放进队列的元素：";
    ElemType *p=Q.front;
    char stop;
    for(stop='\0';stop!='\n';p=p+1)
    {
      cin >> *p;
      stop=cin.get();
    }
    return OK;
}

//－－－－－－－－－－－－－－－－－－主函数－－－－－－－－－－－－－－－－－－－－－－
int main()
{
  InitQueue(Q);
  InputQueue(Q);
  return 0;
}

