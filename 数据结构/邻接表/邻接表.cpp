#include<stdio.h> 
#include<stdlib.h>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0 
#define INFEASIBLE -1
#define OVERFLOW   -2
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status; 
typedef int ElemType; 

#include<queue>
using namespace std; 

typedef char InfoType;
typedef char VertexType; 

#define MAX_VERTEX_NUM 20
typedef struct ArcNode
{
	int    adjvex;                 //该弧所指向的顶点位置
	struct ArcNode *nextarc;      //指向下一条弧的指针
	InfoType *info;              //该弧相关信息指针
	 
}ArcNode;

typedef struct VNode
{
	VertexType data;             //顶点信息
	ArcNode    *firstarc;       //指向第一条依附该顶点的弧的指针
	 
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int     vexnum,arcnum;      //图的当前顶点数和弧数
	int     kind;              //图的种类标志 
 } ALgraph;
 

Boolean visited[MAX];
Status (*VisitFunc)(int v);

void DFSTraverse(Graph G,Status(*Visit)(int v))
//对图G作深度优先遍历 
{
	VisitFunc = Visit;         //使用全局变量VisitFunc，使DFS不必设函数指针参数 
	for(v=0;v<G.vexnum;++v)   //访问标志数组初始化 
		visited[v] = FALSE;
	for(v=0;v<vexnum;++v)    //对尚未访问的顶点调用DFS 
		if(!visited[v])
			DFS(G,v);       
 } 
 
 void DFS(Graph G,int v) 
 //从第v个顶点出发递归地深度优先遍历图G 
 {
 	int w; 
 	visited[v] = TRUE; 
 	VisitFunc(v);           //访问第v个顶点
	for(w = FirstAdjVex(G,v);w >= 0;w = NextAdjVex(G,v,w))
		if(!visited[w])
			DFS(G,w);     //对尚未访问的邻接顶点w递归调用DFS 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void BFSTraverse(Graph G,Stasus (*Visit)(int v))
 //按广度优先非递归遍历图G。使用辅助队列Q和访问标志数组visited
 {
     char u;
     for(v = 0;v<G.vexnum;++v)
	 	visited[v] = FALSE; 
	 queue<VNode> Q;                   //辅助队列 
	 for(v = 0;v<G.vexnum;++v)
	 if(!visited(v))                  //v尚未访问 
	 {
		 visited[v] = TRUE;
		 Visit(v);
		 Q.push(v);
		 while(!Q.empty()) 
		 {
		 	v = Q.front();
		 	Q.pop();
		 	for(w = FirstAdjVex(G,u);w >= 0;w = NextAdjVex(G,u,w))
		 	{
		 		if(!Visited[w])
		 		{
		 			Visited[w] = TRUE;
		 			Visit(w);
		 			Q.push(W);
				 }
			 }
		 }
	 
	 }
	 
  } 
