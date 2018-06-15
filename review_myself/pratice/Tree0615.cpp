#include<iostream>
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

/*void Create(BiTree &T)
{
	char ch;
	ch=cin.get();
	if(ch==' ') T=NULL;
	else{
	        if(!((T=(BiNode *)malloc(sizeof(BiNode))))) exit(OVERFLOW);
		T->data=ch;
		Create(T->lchild);
		Create(T->rchild);
	}
}
*/
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

void Pre(BiTree T)
{
	if(T){
		cout << T->data;
		Pre(T->lchild);
		Pre(T->rchild);

	}
}

int Leaves(BiTree T)
{
	static int count=0;
	if(!T->lchild&&!T->rchild) count++; 
	Leaves(T->lchild);
	Leaves(T->rchild);
	return count;
}

int main()
{
	BiTree T;
	cout << "输入一棵二叉树：";
	CreateTree(T);
//	cout << "遍历二叉树";
	Pre(T);
	Leaves(T);

	return 0;
}
