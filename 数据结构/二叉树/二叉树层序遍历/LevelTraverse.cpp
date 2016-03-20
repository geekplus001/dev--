#include<stdio.h> 
#include<stdlib.h>


#include<queue>
using namespace std;

#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0 
#define INFEASIBLE -1
#define OVERFLOW   -2
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
typedef int Status; 
typedef int ElemType; 
typedef char TElemType;

typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild;
} BiTNode,*BiTree;



Status PrintElement(TElemType e)
{
	printf("%c",e);
	return OK;
}



Status CreateBiTree(BiTree &T)
//����ݹ鴴�� 
{
	char ch; 
	scanf("%c",&ch);
	if(ch==' ')
		T=NULL;
	else
	{
		if(!(T=(BiTNode *)malloc(sizeof(BiTNode))))
			exit(OVERFLOW);
		T->data=ch;
		CreateBiTree(T->lchild);
		CreateBiTree(T->rchild);
	}
	return OK;
}




Status LevelTraverse(BiTree T,Status(*visit)(TElemType e))
//������������� 
{
	BiTree p;
	queue<BiTree> Q;
	if(T)
		Q.push(T);
	while(!Q.empty())
	{
		p=Q.front();
		Q.pop();
		if(!visit(p->data))
			return ERROR;
		if(p->lchild)
			Q.push(p->lchild);
		if(p->rchild)
			Q.push(p->rchild);
	}
	return OK;
} 


int main()
{
	BiTree T; 
	printf("���򴴽���������\n");
	CreateBiTree(T);
	printf("���������������");
	LevelTraverse(T,PrintElement); 

} 

