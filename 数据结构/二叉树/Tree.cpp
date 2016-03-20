#include<stdio.h> 
#include<stdlib.h>


#include<stack>
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


Status PreOderTraverse(BiTree T,Status(*Visit)(TElemType e))
//����ݹ���� 
{
	if(T)
	{
		if(Visit(T->data))
			if(PreOderTraverse(T->lchild,Visit))
				if(PreOderTraverse(T->rchild,Visit))
					return OK;
		return ERROR;
	}
	else
		return OK;
}
Status PrintElement(TElemType e)
{
	printf("%c",e);
	return OK;
}


Status InOrderTraverse(BiTree T,Status (*visit)(TElemType e))
//����ǵݹ����
{
	stack<BiTree> S;
	BiTree p;
	p=T;					
	while(p||!S.empty())
	{
		if(p)
			{
				S.push(p);
				p=p->lchild;
			}
		else
			{
				p = S.top();
				S.pop();
				//Pop(S,p);
				if(!visit(p->data))
					return ERROR;
				p=p->rchild;
			}
	}
	return OK;
} 

int main()
{
	BiTree T; 
	printf("���򴴽���������\n");
	CreateBiTree(T);
	printf("��������������Ķ�������");
	PreOderTraverse(T,PrintElement);
	printf("\n��������������Ķ�������");
	InOrderTraverse(T,PrintElement);
} 
