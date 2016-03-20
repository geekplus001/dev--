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

	
	printf("\n��������Ҫʶ����ַ������У�");
	gets(str);
	length = strlen(str);
	
	CheckStr(Stack, str, length);

#else

	printf("\n��������Ҫ�жϵ����ŵ��ַ�����");
	gets(str);
	length = strlen(str);
	
	CheckStrOrder(Stack, str, length);
	
#endif
	return 0;
}

Status InitStack(STACK &Stack)
{
	//��ʼ��ջ 
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
	//��ջ��ѹ��Ԫ��
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
	//Ԫ�س�ջ 
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
	//����ջ 
	PLNODE p = NULL;
	
	printf("\nջ��Ԫ�أ�");
	
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
	//����ջ 
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
	//ȡջ��Ԫ�� 
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
	//�ж�ջ�Ƿ�Ϊ�� 
	if(Stack.Top == Stack.Base)
		return TRUE;
	
	return FALSE; 
}

void CheckStr(STACK &Stack, char *str, int len)
{
	//�жϸ����������Ƿ�Ϊģʽ���� 
	
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
	
	printf("\n %s %s�ǡ�a+b&b+a�����͵�ģʽ�ַ���\n", str, Flag ? "��" : "");
	
}

void CheckStrOrder(STACK &Stack, char *str, int len)
{
	//����Ƿ������Ƿ����
	
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
	
	printf("\n�ַ��� %s ����%s���\n", str, Empty(Stack) && !Flag ? "" : "��"); 
}

Status IsWhere(ElemType ch)
{
	//�ж����ŵ����� 
	if(ch == '(' || ch == '[' || ch == '{')
		return Left;
	
	return Right;
}

Status Match(ElemType Temp, ElemType Wait)
{
	//�ж������Ƿ�ƥ�� 
	
	if(Temp == '(' && Wait == ')')
		return OK;
	
	if(Temp == '[' || Wait == ']')
		return OK;
		
	if(Temp == '{' || Wait == '}')
		return OK;
	
	return NO;
}
