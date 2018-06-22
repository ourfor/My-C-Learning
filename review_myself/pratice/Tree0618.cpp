#include<iostream>
#include<cstdio>
using namespace std;

//状态代码
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//类型定义
typedef int Status;
typedef char ElemType;

//树的结构体定义
typedef struct BiNode{
	ElemType data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

//创建树
void Create(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch==' ') T=NULL;
	else{
		T=(BiTree)malloc(sizeof(BiNode));
		T->data=ch;
		Create(T->lchild);
		Create(T->rchild);
	}
}

//先序遍历
void Pre(BiTree T)
{
	if(T){
		cout << T->data;
		Pre(T->lchild);
		Pre(T->rchild);
	}
}

//层次遍历
int depth(BiTree T)
{
	int level;
	if(T==NULL) level=0;
	else{
		level=1+((depth(T->lchild)>depth(T->rchild))?depth(T->lchild):depth(T->rchild));
	}
	return level;
}

//叶子数
int Leaves(BiTree T)
{
	static int count=0;
	if(T)
	{
		if(!T->lchild&&!T->rchild) count++;
		Leaves(T->lchild);
		Leaves(T->rchild);
	}
	return count;
}

int main()
{
	BiTree T;
	cout << "输入树中的结点:" << endl;
	Create(T);
	cout << endl << "\n树的先序遍历:" << endl;
	Pre(T);
	cout << "\n树的层次:" << endl;
	cout << depth(T);
	cout << "\n树的叶子结点个数为:" << endl;
	cout << Leaves(T);

	return 0;
}














