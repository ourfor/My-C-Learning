#include<iostream>
#include<cstdlib>

using namespace std;

//------------------------预定义状态代码------------------------
#define ERROR 0
#define FALSE 0
#define OK 1
#define TRUE 1
#define INFEASIBLE -1
#define OVERFLOW -2

//------------------------类  型  定  义------------------------
typedef int Status;
typedef char ElemType;


//------------------------二    叉    树------------------------

//二叉树结点定义

struct BiTreeNode{

	ElemType data;                //数据

	struct BiTreeNode *lchild;     //左孩子

	struct BiTreeNode *rchild;     //右孩子
};

BiTreeNode *T;

//创建二叉树，先序创建。

Status CreatBiTree(BiTreeNode * &T)
{
	//思路:1规律 2出口
	ElemType e;
	cin >> e;

	if(e==' ') T=NULL;

	else 
	{

		if(!(T=(BiTreeNode *)malloc(sizeof(BiTreeNode)))) exit(OVERFLOW);
		T->data=e;                //生成根结点
		CreatBiTree(T->lchild);   //构造左子树
		CreatBiTree(T->rchild);   //构造右子树

	}

	return OK;
}

//遍历二叉树

Status InOrderTraverse_Thr(BiThrTree T,Status(* Visit)(TElemType e))
{
	//T指向头结点，头结点的左链lchild指向根结点
	//中序遍历二叉线索树T的非递归算法，对每个数据元素调用函数Visit
	p=T->lchild;            //p指向根结点
	while(p!=T)             //空树或遍历结束时，p==T
	{
		while(p->LTag==Link) p=p->data;
		if(!Visit(p->data)) return ERROR;            //访问其左子树为空的结点
		while(p->Rtag==Thread&&p->rchild!=T)     
		{
			p=p->rchild;Visit(p->data);              //访问后继结点

		}

		p=p->rchild
	}

	return OK;
}





//------------------------主函数--------------------------

int main()
{
	CreatBiTree(T);

	return 0;
}














