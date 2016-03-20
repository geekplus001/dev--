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

typedef struct
{
	char *ch;
	int length;
} HString;

Status StrAssign(HString &T,char * chars)
//����һ�����ڴ�����chars�Ĵ�T
{
	int i,t;
	char * c;
	if(T.ch)
	free(T.ch);
	for(i=0,c=chars;c;++i,++c)//��chars����i 
	if(!i)
	{T.ch=NULL;T.length=0;}
	else
	{
		if(!(T.ch=(char*)malloc(i*sizeof(char))))
			exit(OVERFLOW);
		for(t=0;t<i;t++)
			T.ch[t]=chars[t];
		T.length=i;
	}
	return OK;
} 

int StrLength(HString S)
//������ 
{
	return S.length; 
}

int StrCompare(HString S,HString T)
//S>T����>0 
{
	int i;
	for(i=0;i<S.length&&i<T.length;i++)
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
	return S.length-T.length;
} 

Status ClearString(HString &S)
//���S
{
	if(S.ch)
	{free(S.ch);S.ch=NULL;}
	S.length=0;
	return OK;
} 

Status Concat(HString &T,HString S1,HString S2)
//��T������S1,S2���ӳɵ��´�
{
	int i;
	if(T.ch)
		free(T.ch);
	if(!(T.ch=(char*)malloc((S1.length+S2.length)*sizeof(char))));
		exit(OVERFLOW);		
	for(i=0;i<S1.length;i++)
		T.ch[i]=S1.ch[i];
	for(i=0;i<S2.length;i++)
		T.ch[i+S1.length]=S2.ch[i];
	T.length=S1.length+S2.length;
	return OK;
} 

Status SubString(HString &Sub,HString S,int pos,int len)
//��Sub����S�ĵ�pos���ַ��𳤶�Ϊlen���Ӵ�
{
	int i;
	if(pos<1||pos>S.length||len<0||len>S.length-pos+1)
		return ERROR;
	if(Sub.ch)
		free(Sub.ch);
	if(!len)
		{Sub.ch=NULL;Sub.length=0;}
	else
	{
		Sub.ch=(char*)malloc(len*sizeof(char));
		for(i=0;i<len;i++)
			Sub.ch[i]=S.ch[pos-1+i];
		Sub.length=len;
	}
	return OK;
} 

Status StrInsert(HString &S,int pos,HString T)
//�ڵ�pos���ַ�ǰ���봮T
{
	int i;
	if(pos<1||pos>S.length+1)
		return ERROR;
	if(T.length)
	{
		if(!(S.ch=(char*)realloc(S.ch,(S.length+T.length)*sizeof(char))));
			exit(OVERFLOW);
		for(i=S.length-1;i>pos;--i)
			S.ch[i+T.length]=S.ch[i];
		for(i=0;i<T.length;i++)
			S.ch[pos-1+i]=T.ch[i];
		S.length+=T.length;
	}
	return OK;
} 

int Index (HString S,HString T,int pos)
//TΪ�ǿմ���������S�е�pos���ַ�֮����ں�T��ȵ��Ӵ����򷵻ص�һ���������Ӵ���S�е�λ�ã����򷵻�0 
{
	HString Sub;
	int n,m,i;
	if(pos>0)
	{
		n=StrLength(S);
		m=StrLength(T);
		i=pos;
		while(i<=n-m+1)
		{
			SubString(Sub,S,i,m);
			if(StrCompare(Sub,T)!=0)
				++i;
			else
				return i;
		}
	}
	return 0;
} 
