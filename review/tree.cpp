#include <iostream>
 using namespace std;
 #include <malloc.h>
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 #define OVERFLOW -2
 typedef  int Status; 
 typedef char TElemType;

typedef struct BiTNode {
    TElemType  data;
    struct BiTNode   *lchild, *rchild; 
} BiTNode,  *BiTree;

void Preorder(BiTree T)
 { // 先序遍历二叉树 
      if (T) {
          cout<<T->data; // 访问结点
          Preorder(T->lchild); // 遍历左子树
          Preorder(T->rchild); // 遍历右子树
       }
  }
void Inorder(BiTree T)
 { // 中序遍历二叉树 
      if (T) {
          Inorder(T->lchild); // 遍历左子树
          cout<<T->data; // 访问结点
          Inorder(T->rchild); // 遍历右子树
       }
  }
void CountLeaf (BiTree T, int   &count)
    {  
        if ( T ) 
         {
             if ((!T->lchild)&& (!T->rchild))     count++;
             CountLeaf( T->lchild, count); 
                        // 统计左子树中叶子结点个数
             CountLeaf( T->rchild, count); 
                        // 统计右子树中叶子结点个数
         }
      }
      
int Depth (BiTree T )
  {  
     int depthval,depthLeft,depthRight;
     if ( !T )       depthval = 0;
     else
      { 
        depthLeft = Depth( T->lchild );
        depthRight= Depth( T->rchild );
        depthval = 1 +
                   (depthLeft>depthRight?depthLeft:depthRight);
       }
     return depthval;
  }

void CreateBiTree(BiTree &T) {
   // 按先序次序输入二叉树中结点的值（一个字符），
   //空格字符表示空树，构造二叉链表表示的二叉树T。
   char ch;
  scanf("%c",&ch);
  if (ch==' ')    T = NULL;
  else {
      if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
      exit(OVERFLOW);
     T->data = ch; // 生成根结点
     CreateBiTree(T->lchild); // 构造左子树
     CreateBiTree(T->rchild); // 构造右子树
   }
 } // CreateBiTree 


int main()
{
  BiTree T;
  int leafnum=0,depth;
  cout<<"Please input the preorder of the tree:";
  CreateBiTree(T);
  cout<<"The preorder of the tree is:";
  Preorder(T);
  cout<<endl;
  cout<<"The inorder of the tree is:";
  Inorder(T);
  cout<<endl;
  depth= Depth(T);
  cout<<"The depth of the tree is:"<<depth<<endl;
  CountLeaf(T,leafnum);
  cout<<"The leaf num of the tree is:"<<leafnum<<endl; 
  system("PAUSE");
  return 1;
}
  