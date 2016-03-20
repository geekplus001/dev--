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

#define LIST_INIT_SIZE 100 //线性表存储空间的初始分配量
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
	if(!L.elem)
	exit(OVERFLOW);
	L.length=0;//空表长度为0
	L.listsize=LIST_INIT_SIZE;
	return OK; 
	
} //InitList_sq

Status ListInsert_Sq(Sqlist &L,int i,ElemType e)
//在L中第i个位置之前插入新的数据元素e，L的长度加1
{
	Sqlist p,q;
	Sqlist newbase;
	if (i<1||i>L.length+1)
	return ERROR;
	if(L.length>=L.listsize)//增加分配 
	{
		newbase.elem=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase.elem)
		exit(OVERFLOW);
		L.elem=newbase.elem;//新基址
		L.listsize+=LISTINCREMENT; //增加存储容量 
		
	}
	q.elem=&(L.elem[i-1]);//q为插入位置 
    for(p.elem=&(L.elem[L.length-1]);p.elem>=q.elem;--p.elem) 
		*(p.elem+1)=*p.elem;//插入位置及之后元素右移	 
	*q.elem=e;//插入e 
	++L.length; 
	return OK; 
}//ListInsert_Sq

Status ListDelete_Sq(Sqlist&L,int i,ElemType &e)//删除第i个元素，用e返回值 
{
	Sqlist p,q;
	if(i<1||(i>L.length))
	return ERROR;
	p.elem=&(L.elem[i-1]);//被删除元素位置 
	e=*p.elem; 
	q.elem=L.elem+L.length-1;//表尾元素位置
	for(++p.elem;p.elem<=q.elem;++p.elem)
	{
		*(--p.elem)=*p.elem;//被删除元素之后的元素左移
		++p.elem;	
	}
	 
	--L.length;
	return OK; 
}//ListDelete_Sq

int LocateElem_Sq(Sqlist L,ElemType e,Status(* compare)(ElemType,ElemType))
//查找第一个与e满足compare（）关系的元素，若找到返回其未序，否则返回0
{
	Sqlist p;
	ElemType i;
	i=1;//初始值为第一个元素位序
	p.elem=L.elem;
	while(i<=L.length&&!(* compare)(*p.elem++,e)) 
	++i;
	if(i<=L.length)
	return i;
	else
	return 0; 
} //LocateElem_Sq


Status GetElem_L(Sqlist L,int i,ElemType &e)
// 当第i个元素存在时，赋给e返回OK
 
{
	if(i<1||i>L.length)
	return OVERFLOW;
	e=L.elem[i-1];
	return OK;
} //GetElem_L

 

/*Status ListDelete_L(LinkList &L,int i,ElemType &e)
//删除第i个元素并有e返回其值
{
    p=L;
	j=0;
	while(p->next&&j<i-1)//寻找第i个节点，并由p指向其前驱 
	{
		p=p->next;
		++j; 
	} 
	if(!(p->next)||j>i-1)
	return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
	return OK; 
} //ListDlete_L
*/
