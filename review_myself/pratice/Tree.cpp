#include<iostream>
using namespace std;

//定义状态代码
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

//类型定义
typedef int Status;
typedef char TElemType;

//树的结构体定义
typedef struct BiNode{
	TElemType data;
	struct BiNode *lchild,*rchild;
}BiNode,*BiTree;

//创建一棵树🌲
void CreateTree(BiTree &T)
{
	char ch;
	ch=cin.get();
	if(ch==' ') T=NULL;
	else{
		if(!(T=(BiTree)malloc(sizeof(BiNode)))) exit(OVERFLOW);
		T->data=ch;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
}

//先序遍历二叉树
void Pre(BiTree T)
{
	if(T)
	{
		cout << T->data;
		Pre(T->lchild);
		Pre(T->rchild);
	}
}

//树的深度
int count=0;

int Leaves(BiTree T)
{
	if(!T) count++;
	else{
		Leaves(T->lchild);
		Leaves(T->rchild);
	}
}

//主函数
int main()
{
	BiTree T;
	CreateTree(T);
	Pre(T);

	return 0;
}
