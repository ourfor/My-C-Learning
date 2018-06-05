#include<iostream>
using namespace std;

#define MAXSIZE 9 // �洢�ռ��ʼ������
#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;
typedef char VertexType;



typedef struct
{
	VertexType vexs[MAXSIZE];
    int  arcs[MAXSIZE][MAXSIZE];
	int vexnum,arcnum;
}Graph;

int LocateVex(Graph G,char v)
{

   for(int i=0;i<G.vexnum;i++)
     if(G.vexs[i]==v)
       return i;
   return -1;
}
// ����ͼ���ڽӾ���
void  CreateUDG(Graph &G)
{
	int i,j,k;
	printf("���붥�����ͱ���:\n");
	cin>>G.vexnum>>G.arcnum;
	for(i = 0;i < G.vexnum;i++)
		cin>>G.vexs[i];
	for(i = 0; i < G.vexnum;i++)
   	 for(j = 0; i < G.vexnum;i++)
	    G.arcs[i][j]=0;
	for(k = 0;k < G.arcnum;k++)
	{
        char v1,v2;
		cout<<"������ϵ���������:\n";
		cin>>v1>>v2;
	    i=LocateVex(G,v1);
        j=LocateVex(G,v2);
		G.arcs[i][j]=G.arcs[j][i]=1;
	}
}

int FirstAdjVex(Graph G, int v)
{
  int j;
  for(j=0;j<G.vexnum;j++)
   if(G.arcs[v][j]==1)
     return j;
  return -1;
}

int NextAdjVex(Graph G, int v, int w)
{
    int j;
    for(j=w+1;j<G.vexnum;j++)
     if(G.arcs[v][j]==1)
       return j;
    return -1;
}




int  visited[MAXSIZE];

// �ڽӾ����������ȵݹ��㷨
void DFS(Graph G, int v)
{
   visited[v] = TRUE;
   cout<<G.vexs[v];
   for(int w = FirstAdjVex(G, v); w>=0; w = NextAdjVex(G, v, w))
       if ( !visited[w] )	DFS(G, w);
}


//�ڽӾ������ȱ�������
void DFSTraverse(Graph G)
{
	int i;
 	for(i = 0; i < G.vexnum; i++)
 		visited[i] = 0;
	for(i = 0; i < G.vexnum; i++)
 		if(!visited[i])
			DFS(G, i);
}


int main()
{
	Graph G;
	CreateUDG(G);
	cout<<"��ȱ���:";
	DFSTraverse(G);
    system("PAUSE");
	return 0;
}
