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

typedef char SElemType;


#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
typedef struct
{ 
	SElemType *base;
	SElemType *top;
	int stacksize;
   	
}SqStack;

Status  InitStack (SqStack &S)
//����һ���ձ�
{
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)
	exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
	
} //InitStack

Status DestroyStack(SqStack &S)
//����ջ
{
	free(S.base);
	S.base=S.top=NULL;
	S.stacksize = 0;  
    return OK;  
} 

Status ClearStack(SqStack &S)
//�ÿ�ջ
{
	S.top = S.base;  
    return OK;  	
} 

Status StackEmpty(SqStack S)  
//�ж�ջ�Ƿ�� 
{  
    if(S.top == S.base)  
        return TRUE;  
    else  
        return FALSE;  
}  



Status GetTop(SqStack S,SElemType &e)
//��ջ�ǿգ�e����S��ջ��Ԫ��
{
	if(S.top==S.base)
	return ERROR;
	e=*(S.top-1);
	return OK;
} //GetTop

Status Push(SqStack &S,SElemType e)
//����eΪ�µ�ջ��Ԫ��
{
	if(S.top-S.base>=S.stacksize)
	{
		S.base=(SElemType*)realloc(S.base,(S.stacksize+STACKINCREMENT)*sizeof(SElemType));
		if(!S.base)
		exit(OVERFLOW);
		S.top=S.base+S.stacksize;
		S.stacksize+=STACKINCREMENT; 
	}
	*S.top++=e;
	return OK;
} //Push

Status Pop(SqStack &S,SElemType &e)
//��ջ���գ���ɾ��S��ջ��Ԫ�أ�e������ֵ
{
	if(S.top==S.base)
	return ERROR;
	e=*--S.top;
	return OK;
} //Pop

int StackLength(SqStack S)
//����ջ��
{
	/*int i=0;
	while(S.base!=S.top)
		{
			i++;
			S.top--; 
		} 
	return i; */
	return S.top - S.base;  
} //StackLength 

Status StackTraverse(SqStack S, Status(* visit)(SElemType))  
{  
    while(S.top > S.base)  
        visit(*S.base++);  
    printf("\n");  
    return OK;  
}  
  
Status visit(SElemType e)  
{  
    printf("%d ",e);  
    return OK;  
}  
