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

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
	
}LNode,*LinkList;

LinkList p,q;

Status InitList_L(LinkList &L)
///////建表头 
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
	return OVERFLOW;
	L->next=NULL;
	return OK;
}

void DestroyList_L(LinkList &L)
//////销毁表
{
	while (L)
	{
		p=L->next;
		free(L);
		L=p;
	}
} 

void ClearList_L(LinkList &L)
//////清空表
{
	p=L->next;
	while(p)
	{
		L->next=p->next;
		free(p);
		p=L->next;
	}
} 

Status ListEmpty_L(LinkList L)
//////判断是否空表
{
	if(!L->next)
	return NULL;
	else
	return FALSE;
} 

int Listlength_L(LinkList L)
//////求表长 
{
	p=L->next;
	int n=0;
	while(p)
	{
		n++;
		p=p->next;
	}
	return n;
}

Status GetElem_L(LinkList L,int i,ElemType &e)
//////找到第i个元素给e
{
	p=L->next;
	int j=1;
	while (p&&j<i)
	{
		p=p->next;
		++j;
	}
	if(!p||j>i)
	return ERROR;
	e=p->data;
	return OK;
} //GetElem


