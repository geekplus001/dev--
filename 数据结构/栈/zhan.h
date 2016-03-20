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
//构造一个空表
{
	S.base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base)
	exit(OVERFLOW);
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return OK;
	
} //InitStack

Status DestroyStack(SqStack &S)
//销毁栈
{
	free(S.base);
	S.base=S.top=NULL;
	S.stacksize = 0;  
    return OK;  
} 

Status ClearStack(SqStack &S)
//置空栈
{
	S.top = S.base;  
    return OK;  	
} 

Status StackEmpty(SqStack S)  
//判断栈是否空 
{  
    if(S.top == S.base)  
        return TRUE;  
    else  
        return FALSE;  
}  



Status GetTop(SqStack S,SElemType &e)
//若栈非空，e返回S的栈顶元素
{
	if(S.top==S.base)
	return ERROR;
	e=*(S.top-1);
	return OK;
} //GetTop

Status Push(SqStack &S,SElemType e)
//插入e为新的栈顶元素
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
//若栈不空，则删除S的栈顶元素，e返回其值
{
	if(S.top==S.base)
	return ERROR;
	e=*--S.top;
	return OK;
} //Pop

int StackLength(SqStack S)
//返回栈长
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
