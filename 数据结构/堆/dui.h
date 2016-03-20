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

typedef struct
{
	char *ch;
	int length;
} HString;

Status StrAssign(HString &T,char * chars)
//生成一个等于串常量chars的串T
{
	int i,t;
	char * c;
	if(T.ch)
	free(T.ch);
	for(i=0,c=chars;c;++i,++c)//求chars长度i 
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
//串长度 
{
	return S.length; 
}

int StrCompare(HString S,HString T)
//S>T返回>0 
{
	int i;
	for(i=0;i<S.length&&i<T.length;i++)
		if(S.ch[i]!=T.ch[i])
			return S.ch[i]-T.ch[i];
	return S.length-T.length;
} 

Status ClearString(HString &S)
//清空S
{
	if(S.ch)
	{free(S.ch);S.ch=NULL;}
	S.length=0;
	return OK;
} 

Status Concat(HString &T,HString S1,HString S2)
//用T返回由S1,S2连接成的新串
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
//用Sub返回S的第pos个字符起长度为len的子串
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
//在第pos个字符前插入串T
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
//T为非空串，若主串S中第pos个字符之后存在和T相等的子串，则返回第一个这样的子串在S中的位置，否则返回0 
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
