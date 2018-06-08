#include<iostream>
using namespace std;
bool visited[20];
typedef int vertextype;

typedef struct arcnode{
	int adjvex;
	struct arcnode *nextarc;
}arcnode;

typedef struct vnode{
	vertextype data;
	arcnode *firstarc;
}vnode,adjlist[20];


typedef struct{
	adjlist vertices;
	int vexnum,arcnum;
}algraph;


int locate(algraph g,vertextype v)
{
	int i;
	for(i=0;i<g.vexnum;i++)
	{
		if(g.vertices[i].data==v)
			return i;
	}
	return -1;
}

int create(algraph &g){
	int i,j,k;
	arcnode *p;
	vertextype v1,v2;
	cout<<"input number";
	cin>>g.vexnum>>g.arcnum;
	cout<<"input vexs";
	for(i=0;i<g.vexnum;i++)
	{
	cin>>g.vertices[i].data;
	g.vertices[i].firstarc =NULL;
	}
	cout<<"input arcs"<<endl;
	for(k=0;k<g.arcnum;k++){
		cout<<"arc"<<k+1<<endl;
		cin>>v1>>v2;
		i=locate(g,v1);j=locate(g,v2);
		p=new (arcnode);
		p->adjvex=j;
		p->nextarc =g.vertices [i].firstarc ;
		g.vertices [i].firstarc =p;
		p=new (arcnode);
		p->adjvex=i;
		p->nextarc =g.vertices [j].firstarc ;
		g.vertices [j].firstarc =p;

	}
	return 1;
}








	
void dfs(algraph g,int v){
	int w;
	visited[v]=true;
	cout<<g.vertices[v].data;

	arcnode  *p=g.vertices[v].firstarc;
	while(p)
	{
 		if(!visited[p->adjvex])
 			dfs(g, p->adjvex);
		p = p->nextarc;
 	}

}



void dfsorder(algraph g){
	int v;
	for(v=0;v<g.vexnum;v++)
		visited[v]=false;
	for(v=0;v<g.vexnum;v++)
		if(!visited[v])
			dfs(g,v);
}


int main()
{
	algraph g;
	create(g);
	dfsorder(g);
	return 0;
}
