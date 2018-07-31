#include <iostream>
#include "tree.h"

int main()
{
	using namespace std;
	Tree A;
	cout << "先序输入二叉树中的元素\n";
	A.Input(A.T);
	cout << "先序便利二叉树\n";
	A.Preorder(A.T);
	cout << "二叉树的层次为" << A.Deepth(A.T) << endl;
	cout << "二叉树的叶子节点数为" << A.Leaves(A.T) << endl;

	return 0;
	
}
