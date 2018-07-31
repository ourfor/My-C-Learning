/*
 * 二叉树的C++实现，练习头文件、类以及熟悉编译链接的过程
 * author：ourfor date:20180726
 */

#include <iostream>

#ifndef TREE_H
#define TREE_H

//节点的定义
typedef struct BiNode{
	char data;
	struct BiNode *lchild,*rchild;

}BiNode,*BiTree;
class Tree
{
	public:
		Tree();
		void Input(BiTree &T);
		void Preorder(BiTree T);
		int Deepth(BiTree T);
		int Leaves(BiTree T);
//	private:
		BiTree T;

};



#endif
