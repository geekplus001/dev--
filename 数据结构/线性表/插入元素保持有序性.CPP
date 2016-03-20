#include<stdio.h>
#include"suanfa.h"
/*#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
#define LISTINCREMENT 10  //线性表存储空间的分配增量

typedef struct
{
	ElemType *elem;      //存储空间基址
	int length;         //当前长度
	int listsize;      //当前费配的存储容量（以sizeof（ElemType）为单位）
	 
}Sqlist;

Status InitList_Sq(Sqlist &L)//构造一个空线性表L
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!Elem)
	exit(OVERFLOW);
	L.length=0;//空表长度为0
	L.listsize=LIST_INIT_SIZE;
	return OK; 
	
} //InitList_sq
*/
Status InsertOrderList(Sqlist&a,ElemType x)
//顺序表a中的元素递增有序，本算法将x插入其中适当位置保持其有序性 
{
	int i,j;
	if(a.length==a.listsize)
	return OVERFLOW;
	else
	{
		i=a.length-1;
		while(i>0&&x<a.elem[i])
		i--;
		for(j=a.length-1;j>=i+1;j--)
			 a.elem[j+1]=a.elem[j];
	    a.elem[i+1]=x;
	    a.length++;
	} 
	    return OK;
}//InsertOrderList

int main()
{
	int t,s,i,j,temp;
	int g[5000];
	printf("请输入您要输入整数表列的元素个数："); 
	scanf("%d",&t);
Sqlist L;
InitList_Sq(L); 
	L.elem=(ElemType*)realloc(L.elem,(t+2)*sizeof(ElemType));
	L.length=t; 
	printf("\n请输入："); 
	for(i=0;i<t;i++)
		scanf("%d",&g[i]);
	for(i=0;i<t-1;i++)
		for(j=i+1;j<t;j++)
		
			if(g[i]>g[j])
			{
				temp=g[i];
				g[i]=g[j];
				g[j]=temp;
			}
	for(i=0;i<t;i++)
	L.elem[i]=g[i];
//	ListInsert_Sq(L,i,g[i]);
	printf("下为您输入的表列：\n");
	for(i=0;i<t;i++)
	printf("%d ",L.elem[i]); 
	printf("\n");
	printf("请输入您要插入的元素:");
    scanf("%d",&s);
    InsertOrderList(L,s);
    printf("最后结果：");
	for(i=0;i<t+1;i++)
	printf("%d ",L.elem[i]); 
    return 0;
} 
