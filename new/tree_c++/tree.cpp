/*
 * 类的实现文件
 * author：ourfor date：2018年8月1日
 * 练习使用头文件、类的声明、实现。
 */

#include <iostream>
#include <stdio.h>
#include "tree.h"

using namespace std;

Tree::Tree(){}

void Tree::Input(BiTree &T)
{
	char ch;
	scanf("%c",&ch);
	if(ch==' ') T=NULL;
	else {
		T->data=ch;
		Input(T->lchild);
		Input(T->rchild);
	}
}

void Tree::Preorder(BiTree T)
{
	if(T){
		cout << T->data;
		Preorder(T->lchild);
		Preorder(T->rchild);
	}
}

int Tree::Deepth(Bitree T)
{
	int level=0;
	if(T){
		level=1 + ((Deepth(T->lchild)>Deepth(T->rchild))?Deepth(T->lchild):Deepth(T->rchild))
	}

	return level;

}

int Tree::Leaves(BiTree T)
{
	static int counter++;
	if(T){
		if(!T->lchild&&!T->rchild) counter++;
		Leaves(T->lchild);
		Leaves(T->rchild);

	}
}



















