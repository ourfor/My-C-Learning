#include<iostream>
#include<malloc.h>
#include<stdio.h>
using namespace std;
#define MAX_NUMBER 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define TRUE 1
#define FALSE 0
#define Status int
bool visited[MAX_NUMBER];
typedef struct ArcNode{
    int adjvex;
    struct ArcNode *nextarc;
}ArcNode;
typedef struct
{
    char data;
    ArcNode *firstarc;
}VNode,AdjList[MAX_NUMBER];
typedef struct{
    AdjList vertices;
    int vexnum,arcnum;
}MGraph;
int Get(MGraph &G,char c)
{
    for(int i=0;i<G.vexnum;i++)
    if(G.vertices[i].data==c)
    {
        return i;
    }
}
Status GreatGraph(MGraph &G)
{
    ArcNode *p;
    cin>>G.vexnum>>G.arcnum;
    for(int i=0;i<G.vexnum;i++)
      {cin>>G.vertices[i].data;G.vertices[i].firstarc=NULL;}
    for(int j=0;j<G.arcnum;j++)
    {
        char a,b;
        cin>>a>>b;
        int i=Get(G,a);
        int k=Get(G,b);
        p=(ArcNode *)malloc(sizeof (ArcNode));
        p->adjvex=k;
        p->nextarc=G.vertices[i].firstarc;
        G.vertices[i].firstarc=p;
    }

}
int FirstAdjVex(MGraph G,int v)
{
    if(G.vertices[v].firstarc)
        return G.vertices[v].firstarc->adjvex;
    else return -1;
}
int NextAdjVex(MGraph G,int v,int w)
{

    ArcNode *p=G.vertices[v].firstarc;
    while (p)
    {
        if(p->adjvex==w)
        {
            p=p->nextarc;
            if(p)
               return p->adjvex;
            else return -1;}

        else p=p->nextarc;
    }

    return -1;

}
void DFS(MGraph G,int v)
{
    visited[v]=TRUE;
   // cout<<"บวบว";
    cout<<G.vertices[v].data;
     for(int w=FirstAdjVex(G,v);w>=0;w=NextAdjVex(G,v,w))
    {

        if(!visited[w])DFS(G,w);
    }
    //cout<<"JJ";
}
void DFSTraverse(MGraph G)
{
    int i;
    for(i=0;i<G.vexnum;i++) visited[i]=FALSE;
    for(i=0;i<G.vexnum;i++)
    {
        if(!visited[i])
           {
               DFS(G,i);
           }

    }
}

int main()
{
    MGraph G;
    GreatGraph(G);
    DFSTraverse(G);
    return 0;
}