#include"zhan.h"
int Match_expression(SqStack &S,char a[])
{
	int l,i; 
	char e; 
	l=StackLength(S);
	for(i=0;i<l;i++) 
	{
	    Pop(S,e);
		if(e!=a[i])
		{
			printf("²»Æ¥Åä¡£\n"); 
			return 0; 
		}	
	 
	}
	printf("Æ¥Åä¡£\n");
	return 0; 
}
int main()
{
	char a[10000],e; 
	int i=0; 
	SqStack S; 
	InitStack (S);
	printf("ÇëÊäÈë£º");
	scanf("%c",&e);
	while(e!='@')
	{
		Push(S,e);
		scanf("%c",&e);
	}
	scanf("%c",&a[i]);
	while(a[i]!='\n') 
	{
		i++; 
		scanf("%c",&a[i]);
		 
	}	
	Match_expression(S,a);
	
}
