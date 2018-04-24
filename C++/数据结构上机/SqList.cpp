<<<<<<< HEAD
//线性表的建立、插入、删除、查询以及销毁。
=======
//线性表-顺序表的建立、插入、删除、查询以及销毁。


>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
#include<iostream>
using namespace std;

//--------------------定义状态代码--------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define INFEASIBLE -1

typedef int Status;
typedef int ElemType;

//-------------------线性表初始量-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
#define LIST_INIT_SIZE 100
#define LIST_ADD_SIZE 10

//-------------------定义结构体-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
typedef struct{
	ElemType * elem;      //基地址
	int length;           //线性表长度
	int listsize;         //线性表所占的空间大小
}Sqlist;

//-------------------初始化线性表-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
Status InitList(Sqlist &T)
{
//构造一个空的线性表L
	T.elem=(ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));            
	if(!T.elem) exit(OVERFLOW);
	T.length=0;
	T.listsize=LIST_INIT_SIZE;
	cout << "线性表初始化成功！" << endl;
	return OK;
}//InitList
//-------------------线性表数据的输出-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
Status DisplayList(Sqlist T)
{   
	ElemType * q=T.elem;
	for(int i=0;i<=T.length-1;i++)
	{
		q=T.elem+i;
		cout << * q << " " ;
		 
	}
	cout << "\n";
	return OK;
}
//-------------------线性表数据输入-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
Status InputList(Sqlist &T)
{
	cout << "线性表中有多少个元素：";
	cin >> T.length;
	cout << "请输入线性表中的各个元素：";
	ElemType * p;
	p=T.elem;
	for(int i=0;i<=T.length-1;i++,p++)
	{
		
		cin >> * p;
	}
	DisplayList(T);
	return OK;
}

//-------------------线性表元素的插入-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
Status InsertList(Sqlist &T,int i,ElemType e)
{
	//在第i个元素之前插入，使其成为第i个元素，判断插入位置i的合法性
	//如果空间不够，重新分配空间
	if(i<1||i>T.length+1) exit(ERROR);
	if(T.length>=T.listsize) 
	{
		ElemType * newbase=(ElemType *)malloc((LIST_INIT_SIZE+LIST_ADD_SIZE)*sizeof(ElemType));
		T.elem=newbase;
	}
	if(!T.elem) return ERROR;             //分配失败
	//i后面的元素后移
	int j;
	ElemType * p=T.elem;
	for(j=T.length - 1;j>=i - 1;j--) *(p + j + 1)=*(p + j);
	*(T.elem + i - 1)=e;
	cout << "已将第" << i << "个位置插入元素" << e << endl;
	T.length=T.length + 1;
	DisplayList(T);
	return OK;
}
//-------------------线性表元素的删除-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
Status DeleteList(Sqlist &T,int i,ElemType &f)
{
	//删除位置的取值范围1<=i<=T.length
	//删除第i个元素，其他元素往前移
	if(i<1||i>T.length) exit(ERROR);
	ElemType *p=T.elem + i;
	f=*(p - 1);
	int j;
	for(j=i;j<=T.length;*(p - 2)=*(p - 1),j++)
		p++;
	T.length=T.length-1;
	cout << "删除的元素为" << f << endl;
	DisplayList(T);
	return OK;
}
//-------------------线性表元素的排序-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
Status RankList(Sqlist &T)
{
	cout << "自小至大排序：" << endl;
	ElemType *r=T.elem,*temp;
	//冒泡排序
	for(int j=T.length;j>=1;j--)
	{
		r=T.elem;
		for(int i=0;i<=j - 2;i++)
		{
			if(*(r + i)>*(r + 1 + i)) {*temp=*(r + i);*(r + i)=*(r + 1 + i);*(r + 1 + i)=*temp;}
	    }
	}
	DisplayList(T);        //线性表元素打印
	return OK;
	
}
Status LocalList(Sqlist &T,ElemType find_elem)
{
	ElemType *p;
	int elem_num=0;
	int num=0;
	for(p=T.elem;p<T.elem + T.length - 1;p++)
	{
		num+=1;
		if(*p==find_elem){
			elem_num=num;
			cout << "元素" << find_elem << "在线性表中位于第" << elem_num << "个位置";
			cout << "\n";
			return OK;
		}
	}
	if(elem_num==0) cout << "表中不存在元素" << find_elem;
	return ERROR;
}
//-------------------主函数-------------------
<<<<<<< HEAD
=======

>>>>>>> bce2b59f930798faf9de1b833e4911b441d50959
int main()
{
	Sqlist T;
	InitList(T);           //初始化线性表
    InputList(T);          //线性表的输入

	int i;
	ElemType e;
	cout << "输入插入位置以及元素：";
	cin >> i >> e;
	InsertList(T,i,e);
	
	cout << "请输入删除位置：";
	cin >> i;
	ElemType f;
	DeleteList(T,i,f);
	RankList(T);
	cout << "你要查找哪个元素：";
	ElemType find_elem;
	cin >> find_elem;
	LocalList(T,find_elem);
	
	
	return 0;
}
