#include<iostream>
using namespace std;

//状态代码
#define OK 1
#define FALSE 0
#define INFEASIBLE -1
#define OVERFLOW -2

//类型定义
typedef int Status;
typedef double ElemType;

//顺序表常量
#define Init_list_size 100
#define Add_size 20

//顺序表定义
struct Sqlist{
	ElemType *base; //基地址
	int length;   //当前表长
	int list_size;  //表长
};

Sqlist T;

//初始化顺序表
Status InitSqlit(Sqlist &T)
{
	T.base=(ElemType *)malloc(Init_list_size * sizeof(ElemType));
	if(!T.base) exit(OVERFLOW);  //分配失败
	T.length=0;
	T.list_size=Init_list_size;
	cout << "初始化成功！";
	return OK;
}
//输入元素
Status InputSqlist(Sqlist &T)
{
	cout << "输入线性表中的元素(通过空格隔开):";
	char stop_input='\0';
	ElemType *p;
	for(p=T.base;stop_input!='\n';p=p + 1)
	{
		cin >> *p;
		stop_input=cin.get();
		//T.length+=1;
	}
	T.length=p - T.base;

	return OK;
}

//线性表元素的插入
Status InsertSqlist(Sqlist &T,ElemType e)
{
	cout << "输入你想插入的位置：";
	int i_l;  //插入位置
	cin >> i_l;
	if(i_l>=T.length)
	{
		
	}
	ElemType *p=T.base;

	for(int i=T.length - 1;i>=i_l -1;i--) *(p + i + 1)=*(p + i);  
	*(p + i_l - 1)=e;
	T.length+=1;
	return OK;

}


//打印表中元素
Status Display(Sqlist T)
{
	ElemType *p=T.base;
	for(int i=0;*(p + i)!='\0';i++)
		cout << *(p + i) << " ";
	return OK;
}

//主函数
int main()
{
	InitSqlit(T);
	InputSqlist(T);
	ElemType e;
	cout << "输入你想插入的元素的值：";
	cin >> e;
	InsertSqlist(T,e);
	Display(T);

	return 0;

}













