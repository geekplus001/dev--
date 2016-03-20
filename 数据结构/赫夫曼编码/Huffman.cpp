#include<stdio.h> 
#include<stdlib.h>
#include<string.h>
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
	unsigned int weight;
	unsigned int parent,lchild,rchild;
}HTNode, *HuffmanTree;

typedef char **HuffmanCode;


void HuffmanCoding(HuffmanTree &HT,HuffmanCode *HC,int *w,int n);
void Select(HuffmanTree &HT, int n, int &s1, int &s2);
void PrintHuffmanCode(HuffmanCode HC, char *q, int n);



void HuffmanCoding(HuffmanTree &HT,HuffmanCode &HC,int *w,int n)
//w存放n个字符权值，构造赫夫曼树HT，并求出n个字符的赫夫曼编码HC
{
	int m,i,c,start;
	int s1,s2;
	unsigned int f;
	HuffmanTree p;
	char *cd; 
	if(n<=2)
		return;
	m=2*n-1;
	HT=(HuffmanTree)malloc((m+1)*sizeof(HTNode));//0号单元未用
	for(p=HT+1,i=1;i<=n;++i,++p,++w)
	{
		p->weight = w[i-1];
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}

	for(;i<=m;++i,++p)
	{
		p->weight = 0;
		p->parent = 0;
		p->lchild = 0;
		p->rchild = 0;
	}
	
	for(i=n+1;i<=m;++i)//建赫夫曼树
	{
		Select(HT,i-1,s1,s2);
		//在HT[0...i-1]选择parent为0且weight最小的两个节点，其序号分别为s1，s2 
		HT[s1].parent=i;	HT[s2].parent=i;
		HT[i].lchild=s1;	HT[i].rchild=s2;
		HT[i].weight=HT[s1].weight+HT[s2].weight;
		
	} 
	//从叶子到跟逆向求每一个字符的赫夫曼编码
	HC=(HuffmanCode)malloc((n+1)*sizeof(char *));
	//分配n个字符编码的头指针向量 
	cd=(char *)malloc(n*sizeof(char));
	//分配求编码的工作区间 
	cd[n-1]='\0';
	
	for(i=1;i<=n;++i)//逐个字符求编码 
	{
		start = n-1;
		for(c = i, f = HT[i].parent; f != 0; c = f, f = HT[f].parent)
			if(HT[f].lchild==c)		
				cd[--start] = '0';
			else
		   	    cd[--start] = '1';
		HC[i] = (char *)malloc((n-start)*sizeof(char));//为第i个字符编码分配空间
		strcpy(HC[i],&cd[start]); 
	} 
	free(cd);
} 


void Select(HuffmanTree &HT, int n, int &s1, int &s2)
{
	int i,j,k;
	j=k=20000;
	for(i = 1; i <= n; i++)
	{
		if(HT[i].parent==0&&(HT[i].weight<j||HT[i].weight<k))
			{
				if(j<k)	{k=HT[i].weight;s2=i;}
				else	{j=HT[i].weight;s1=i;}
				
			}
		if(s1>s2)//放最小序号 
     		{
     			i=s1;
     			s1=s2;
     			s2=i;
     		}	
	}

}


void PrintHuffmanCode(HuffmanCode HC, char *q, int n)
//输出编号的赫夫曼编码 
{
	int i;
	printf("HuffmanCode is:\n");
	for(i=1;i<=n;i++)
	{
		printf("%c:",q[i]);
		puts(HC[i]);
		printf("\n");
	}

}


int main()
{
	HuffmanCode HC;
	HuffmanTree HT; 
	char e;
	//char s[10000];
	char *q;
	int i,k,j=1,n=1;//ss=0; 
	int p[26]={0}; 
	int *w;
	printf("请输入一篇英文句子或文章(以符号&为结束标志)：\n");
	while((e=getchar())!='&')
	{
		if(e>='A'&&e<='Z')
		{
			//s[ss++]=e+32;
			p[e-65]++; 
		}
		if(e>='a'&&e<='z')
		{
			//s[ss++]=e;
			p[e-97]++;
		}
		//else
		//	s[ss++]=e;	 
	} 
	//s[ss]='\0';
	for(i=0;i<=25;i++)
		if(p[i]!=0)
			n++;
	w=(int *)malloc((n+1)*sizeof(int));
	//q=(char *)malloc((n+1)*sizeof(char));	
	for(i=0;i<=25;i++)
	{
		if(p[i]!=0)
		{
			w[j++]=p[i];
			//q[j++]=i+97;
		}
	}
	HuffmanCoding(HT,HC,w,n);
	PrintHuffmanCode(HC,q,n);
	printf("码文：");
	for(i=1;i<=n;i++)
	{
		for(k=1;k<=w[i];k++)
			puts(HC[i]);	
	}
	printf("\n");
} 
