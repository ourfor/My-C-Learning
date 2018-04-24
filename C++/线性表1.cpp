#include"stdio.h"  
#include<cstdlib> 
#define OVERFLOW 0  
#define OK  1  
#define LIST_INIT_SIZE  100  
#define LISTINCREMENY  10  
typedef struct  
{  
    int *elem;  
    int length;  
    int listsize;  
}SqList;  
 int InitList_Sq(SqList &L)  
 {  
 L.elem =(int &)malloc(LIST_INIT_SIZE*sizeof(int));  
 if(!L.elem ) exit(OVERFLOW);  
 L.length =0;  
 L.listsize=LIST_INIT_SIZE;  
 return OK;  
  
 }  
   int main()  
   {  
   SqList L;  
   InitList_Sq(&L);  
   printf("线性表Sqlist初始化成功：\n");   
    return 0;  
  
   }  