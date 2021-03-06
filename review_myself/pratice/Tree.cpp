#include<iostream>
#include<cstdio>
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
	scanf("%c",&ch);
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

int Leaves(BiTree T)
{
	static int count=0;
	if(T){
	
		if(!T->lchild&&!T->rchild) count++;
		Leaves(T->lchild);
		Leaves(T->rchild);
	}

	return count;
}

int Level(BiTree T)
{
	int level;
	if(T==NULL) level=0;
	else{
		level=1+(Level(T->lchild)>Level(T->rchild)?Level(T->lchild):Level(T->rchild));
	}
	return level;
}

//主函数
int main()
{
	BiTree T;
	cout << "输入二叉树中的结点：\n";
	CreateTree(T);
	cout << "\n先序遍历二叉树：\n";
	Pre(T);
	cout << "\n二叉树叶子个数：";
	cout << Leaves(T);
	cout << "\n树的层次为：\n" << Level(T);


	return 0;
}
