#include"zhan.h"
int Match_sign() 
{
	SqStack S;
	int i=0; 
	char e[10000],a; 
	InitStack (S);
	printf("������ʽ�ӣ�");
	scanf("%s",e); 
    while (e[i]!='\0')
    {
    	switch(e[i])
		{
			case '(':  
				Push(S,e[i]);
				i++;break;
			case '[':
				Push(S,e[i]); 
				i++;break;
			case '{':
				Push(S,e[i]);
				i++;break;
			case ')':
				Pop(S,a);
				if(a!='(')
				{
					printf("��ƥ�䡣\n");
					return 0;
				}
				else
				{
					i++;
					break;
				}
		
			case ']':
			Pop(S,a);
			if(a!='[')
			{
				printf("��ƥ�䡣\n");
				return 0;
			}
			else
			{
				i++;
				break;
			}
		
			case '}':
			Pop(S,a);
			if(a!='{')
			{
				printf("��ƥ�䡣\n");
				return 0;
			}
			else
		    {
				i++;
				break;
			}
		
			default:
			i++;
			break;
		} 
    }
    if(S.top==S.base)
	printf("ƥ�䡣\n");
	else
	printf("��ƥ�䡣\n"); 
}
int main() 
{
	
	Match_sign();
	return 0;
}
