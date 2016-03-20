#include <stdio.h>
#include <stdlib.h> 
#include <windows.h>

//#define _STACK_CPP

#define ElemType 	 char
#define Status	     int

#define OK			 1
#define NO 			 0
#define OVERFLOW 	-1
#define TRUE		 1
#define FALSE		 0
#define Left		 -2
#define Right		 2 

#define MAX_STR		 100

typedef struct lNode
{
	ElemType Data;
	struct lNode *next;
}LNODE, *PLNODE;

typedef struct stack
{
	struct lNode *Top;
	PLNODE		  Base; 
}STACK, *PSTACK;

Status InitStack(STACK &Stack);
Status Push(STACK &Stack, ElemType Data);
Status Pop(STACK &Stack);
void TravelStack(STACK Stack);
void DestoryStack(STACK &Stack);
void CheckStr(STACK &Stack, char *str, int len);
Status Empty(STACK Stack);
ElemType GetTop(STACK Stack);
void CheckStr(STACK &Stack, char *str, int len);
void CheckStrOrder(STACK &Stack, char *str, int len);
Status IsWhere(ElemType ch);
Status Match(ElemType Temp, ElemType Wait); 
 
int main ()
{
	int 	length = 0;
	char 	str[MAX_STR];
	STACK 	Stack;
	
	InitStack(Stack);
/*
	for(int i = 0; i < 3; ++i)
	{
		int e; 
		scanf ("%d", &e);
		Push(Stack, e);
	}
	
	DestoryStack(Stack);
	
	TravelStack(Stack);
*/

#ifdef _STACK_CPP

	
	printf("\n请输入所要识别的字符串序列：");
	gets(str);
	length = strlen(str);
	
	CheckStr(Stack, str, length);

#else

	printf("\n请输入需要判断的括号的字符串：");
	gets(str);
	length = strlen(str);
	
	CheckStrOrder(Stack, str, length);
	
#endif
	return 0;
}

Status InitStack(STACK &Stack)
{
	//初始化栈 
	Stack.Top = (PLNODE)malloc(sizeof(LNODE));
	if(!Stack.Top)
		return (OVERFLOW);
	
	Stack.Top->next = NULL;
	Stack.Base 		= Stack.Top;
	Stack.Top->Data = -1;
	
	return OK;
}

Status Push(STACK &Stack, ElemType Data)
{
	//往栈中压入元素
	PLNODE p = NULL;
	
	p = (PLNODE)malloc(sizeof(LNODE));
	if(!p)
		return (OVERFLOW);
		
	p->next   = Stack.Top;
	p->Data	  = Data;
	Stack.Top = p;
	
	return OK;
}

Status Pop(STACK &Stack)
{
	//元素出栈 
	if(Stack.Base == Stack.Top)
		return ERROR;
	
	PLNODE p  = NULL;
	
	p 		  = Stack.Top;
	Stack.Top = Stack.Top->next;
	free(p);
	p 		  = NULL; 
	
	return OK;	
}

void TravelStack(STACK Stack)
{
	//遍历栈 
	PLNODE p = NULL;
	
	printf("\n栈中元素：");
	
	p = Stack.Top;
	while (p != Stack.Base)
	{
		printf(" %c", p->Data);
		p = p->next;
	}
	
	putchar('\n');
}

void DestoryStack(STACK &Stack)
{
	//销毁栈 
	PLNODE p = NULL, Temp = NULL;
	
	p = Stack.Top;
	while(p != Stack.Base)
	{
		Temp = p;
		p 	 = p->next;
		free(Temp);
	}
	
	Stack.Top = p; 
}

ElemType GetTop(STACK Stack)
{
	//取栈顶元素 
	ElemType Temp = 0x3f;
	
	if(!Empty(Stack))
	{
		Temp 	  = Stack.Top->Data;
		Stack.Top = Stack.Top->next;
	}
	
	return Temp;
}

Status Empty(STACK Stack)
{
	//判断栈是否为空 
	if(Stack.Top == Stack.Base)
		return TRUE;
	
	return FALSE; 
}

void CheckStr(STACK &Stack, char *str, int len)
{
	//判断给出的序列是否为模式序列 
	
	int Flag = 0, pos = 0;
	
	for (int i = 0; i < len; ++i)
	{
		if(str[i] == '&')
		{
			pos = i + 1;
			break;
		}
		Push(Stack, str[i]);
	}
	
	while(str[pos] != '@' && pos <= len)
		if(!Empty(Stack) && GetTop(Stack) == str[pos])
		{
			Pop(Stack);
			++pos;
		} 
		else
		{
			Flag = 1;
			break;
		}
	
	if(!Empty(Stack))
		Flag = 1;
	
	DestoryStack(Stack);
	
	printf("\n %s %s是‘a+b&b+a’类型的模式字符串\n", str, Flag ? "不" : "");
	
}

void CheckStrOrder(STACK &Stack, char *str, int len)
{
	//检查是否括号是否配对
	
	int Flag = 0;
	ElemType Temp;
	 
	for (int i = 0; i < len; ++i)
	{

		if(IsWhere(str[i]) == Left)
			Push(Stack, str[i]);
		else
		{
			if(Empty(Stack))
			{
				Flag = 1;
				break;
			}
			Temp = GetTop(Stack);
			if(!Match(Temp, str[i]))
				Push(Stack, str[i]);
			else
				Pop(Stack);
		}
	}
	
	DestoryStack(Stack);
	
	printf("\n字符串 %s 括号%s配对\n", str, Empty(Stack) && !Flag ? "" : "不"); 
}

Status IsWhere(ElemType ch)
{
	//判断括号的左右 
	if(ch == '(' || ch == '[' || ch == '{')
		return Left;
	
	return Right;
}

Status Match(ElemType Temp, ElemType Wait)
{
	//判断括号是否匹配 
	
	if(Temp == '(' && Wait == ')')
		return OK;
	
	if(Temp == '[' || Wait == ']')
		return OK;
		
	if(Temp == '{' || Wait == '}')
		return OK;
	
	return NO;
}
