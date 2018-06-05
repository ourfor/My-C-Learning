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
 { // ������������� 
      if (T) {
          cout<<T->data; // ���ʽ��
          Preorder(T->lchild); // ����������
          Preorder(T->rchild); // ����������
       }
  }
void Inorder(BiTree T)
 { // ������������� 
      if (T) {
          Inorder(T->lchild); // ����������
          cout<<T->data; // ���ʽ��
          Inorder(T->rchild); // ����������
       }
  }
void CountLeaf (BiTree T, int   &count)
    {  
        if ( T ) 
         {
             if ((!T->lchild)&& (!T->rchild))     count++;
             CountLeaf( T->lchild, count); 
                        // ͳ����������Ҷ�ӽ�����
             CountLeaf( T->rchild, count); 
                        // ͳ����������Ҷ�ӽ�����
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
   // �������������������н���ֵ��һ���ַ�����
   //�ո��ַ���ʾ������������������ʾ�Ķ�����T��
   char ch;
  scanf("%c",&ch);
  if (ch==' ')    T = NULL;
  else {
      if (!(T = (BiTNode *)malloc(sizeof(BiTNode))))
      exit(OVERFLOW);
     T->data = ch; // ���ɸ����
     CreateBiTree(T->lchild); // ����������
     CreateBiTree(T->rchild); // ����������
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
  
