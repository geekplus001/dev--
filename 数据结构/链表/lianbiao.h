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

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
	
}LNode,*LinkList;

LinkList p,q;

Status InitList_L(LinkList &L)
///////����ͷ 
{
	L=(LinkList)malloc(sizeof(LNode));
	if(!L)
	return OVERFLOW;
	L->next=NULL;
	return OK;
}

void DestroyList_L(LinkList &L)
//////���ٱ�
{
	while (L)
	{
		p=L->next;
		free(L);
		L=p;
	}
} 

void ClearList_L(LinkList &L)
//////��ձ�
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
//////�ж��Ƿ�ձ�
{
	if(!L->next)
	return NULL;
	else
	return FALSE;
} 

int Listlength_L(LinkList L)
//////��� 
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
//////�ҵ���i��Ԫ�ظ�e
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


