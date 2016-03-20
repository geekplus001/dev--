#include<stdio.h> 
#include<stdlib.h>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0 
#define INFEASIBLE -1
#define OVERFLOW   -2
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status; 
typedef int ElemType; 

#include<queue>
using namespace std; 

typedef char InfoType;
typedef char VertexType; 

#define MAX_VERTEX_NUM 20
typedef struct ArcNode
{
	int    adjvex;                 //�û���ָ��Ķ���λ��
	struct ArcNode *nextarc;      //ָ����һ������ָ��
	InfoType *info;              //�û������Ϣָ��
	 
}ArcNode;

typedef struct VNode
{
	VertexType data;             //������Ϣ
	ArcNode    *firstarc;       //ָ���һ�������ö���Ļ���ָ��
	 
} VNode,AdjList[MAX_VERTEX_NUM];

typedef struct
{
	AdjList vertices;
	int     vexnum,arcnum;      //ͼ�ĵ�ǰ�������ͻ���
	int     kind;              //ͼ�������־ 
 } ALgraph;
 

Boolean visited[MAX];
Status (*VisitFunc)(int v);

void DFSTraverse(Graph G,Status(*Visit)(int v))
//��ͼG��������ȱ��� 
{
	VisitFunc = Visit;         //ʹ��ȫ�ֱ���VisitFunc��ʹDFS�����躯��ָ����� 
	for(v=0;v<G.vexnum;++v)   //���ʱ�־�����ʼ�� 
		visited[v] = FALSE;
	for(v=0;v<vexnum;++v)    //����δ���ʵĶ������DFS 
		if(!visited[v])
			DFS(G,v);       
 } 
 
 void DFS(Graph G,int v) 
 //�ӵ�v����������ݹ��������ȱ���ͼG 
 {
 	int w; 
 	visited[v] = TRUE; 
 	VisitFunc(v);           //���ʵ�v������
	for(w = FirstAdjVex(G,v);w >= 0;w = NextAdjVex(G,v,w))
		if(!visited[w])
			DFS(G,w);     //����δ���ʵ��ڽӶ���w�ݹ����DFS 
 }
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 void BFSTraverse(Graph G,Stasus (*Visit)(int v))
 //��������ȷǵݹ����ͼG��ʹ�ø�������Q�ͷ��ʱ�־����visited
 {
     char u;
     for(v = 0;v<G.vexnum;++v)
	 	visited[v] = FALSE; 
	 queue<VNode> Q;                   //�������� 
	 for(v = 0;v<G.vexnum;++v)
	 if(!visited(v))                  //v��δ���� 
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
