//线性表的建立、初始化、插入、删除、查询以及销毁 --线性表.cpp
#include<iostream>
#include<cstdlib>

using namespace std;

//函数结果状态代码
#define OK 1
#define TRUE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//用status代替int使用，Status是函数的类型，其值是函数结果的状态代码。
typedef int Status;
typedef double ElemType;


//- - - - - -线性表的动态分配顺序存储结构- - - - - -
#define LIST_INIT_SIZE 100    //线性表存储空间的初始分配量
#define LISTINCREMENT 10      //线性表存储空间的分配增量



//定义结构体
struct SqList{
	ElemType * elem;    //存储空间基地址
	int length;        //当前长度
	int listsize;      //当前分配的储存容量（以sizeof(ElemType)为单位）
};

Status InitList_Sq(SqList);



int main()
{
	cout << "Nice to meet you!";
	SqList L;
	InitList_Sq(*L);

	return TRUE;
}
//线性表的建立 


Status InitList_Sq(SqList *L){
     //构造一个空的线性表
	L.elem=(ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);        //存储分配失败
	L.length=0;                        //空表长度
	L.listsize=LIST_INIT_SIZE;         //初始储存容量
	return OK;
}//InitList_Sq


//线性表的元素插入实现

/*
Status ListInsert_Sq(SqList &L,int i,ElemType e){
	//在顺序线性表L中第i个位置之前插入新的元素e，
	//i的合法性为1<=i<=ListLength_Sq(L)+1
	if(i<1 || i>L.length+1) return ERROR;     //i值不合法
	if(L.length>=L.listsize){                 //当前储存空间已满,增加分配
		newbase=(ElemType *)remallc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
   
		if(!newbase) exit(OVERFLOW);        //存储分配失败
		L.elem=newbase;                     //新基址
		L.listsize+=LISTINCREMENT;          //增加后的容量
	
	}

	q=&(L.elem[i-1]);                      //q为插入位置
	for(p=&(L.elem[L.length-1]);p>=q;--p)  * (p+1)=* p;
											//插入位置及之后的元素右移

	* p=e;                  //插入e
	++L.length;             //使用前表长加1

	return OK;
}//ListInsert_Sq
*/


//线性表的元素删除实现
//1.值（参数）的合法性
//2.具体操作

/*
Status ListDelete_Sq(SqList &L,int i,ElemType &e){
	//在顺序线性表L中删除第i个元素，并用e返回其值
	//i值的合法性1<=i<=Listlength_Sq(L)
	if((i<1)||(i>ListLength_Sq)) return ERROR;    //i值不合法
	p=&(L.elem[i-1]);                             //p为被删除的元素位置
	e=* p                                         //用e返回被删除的元素
	q=L.elem+L.length-1;                          //表尾元素的位置
	for(++p;p<=q;++p) * (p-1)=* p;                //被删除的元素之后的元素右移
		--L.length                                //表长减1
	return OK;


}//ListDelete_Sq
*/





















