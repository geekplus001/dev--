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

#define LIST_INIT_SIZE 100 //���Ա�洢�ռ�ĳ�ʼ������
#define LISTINCREMENT 10  //���Ա�洢�ռ�ķ�������
typedef struct
{
	ElemType *elem;      //�洢�ռ��ַ
	int length;         //��ǰ����
	int listsize;      //��ǰ����Ĵ洢��������sizeof��ElemType��Ϊ��λ��
	 
}Sqlist;



Status InitList_Sq(Sqlist &L)//����һ�������Ա�L
{
	L.elem=(ElemType*)malloc(LIST_INIT_SIZE*sizeof(ElemType));
	if(!L.elem)
	exit(OVERFLOW);
	L.length=0;//�ձ���Ϊ0
	L.listsize=LIST_INIT_SIZE;
	return OK; 
	
} //InitList_sq

Status ListInsert_Sq(Sqlist &L,int i,ElemType e)
//��L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1
{
	Sqlist p,q;
	Sqlist newbase;
	if (i<1||i>L.length+1)
	return ERROR;
	if(L.length>=L.listsize)//���ӷ��� 
	{
		newbase.elem=(ElemType *)realloc(L.elem,(L.listsize+LISTINCREMENT)*sizeof(ElemType));
		if(!newbase.elem)
		exit(OVERFLOW);
		L.elem=newbase.elem;//�»�ַ
		L.listsize+=LISTINCREMENT; //���Ӵ洢���� 
		
	}
	q.elem=&(L.elem[i-1]);//qΪ����λ�� 
    for(p.elem=&(L.elem[L.length-1]);p.elem>=q.elem;--p.elem) 
		*(p.elem+1)=*p.elem;//����λ�ü�֮��Ԫ������	 
	*q.elem=e;//����e 
	++L.length; 
	return OK; 
}//ListInsert_Sq

Status ListDelete_Sq(Sqlist&L,int i,ElemType &e)//ɾ����i��Ԫ�أ���e����ֵ 
{
	Sqlist p,q;
	if(i<1||(i>L.length))
	return ERROR;
	p.elem=&(L.elem[i-1]);//��ɾ��Ԫ��λ�� 
	e=*p.elem; 
	q.elem=L.elem+L.length-1;//��βԪ��λ��
	for(++p.elem;p.elem<=q.elem;++p.elem)
	{
		*(--p.elem)=*p.elem;//��ɾ��Ԫ��֮���Ԫ������
		++p.elem;	
	}
	 
	--L.length;
	return OK; 
}//ListDelete_Sq

int LocateElem_Sq(Sqlist L,ElemType e,Status(* compare)(ElemType,ElemType))
//���ҵ�һ����e����compare������ϵ��Ԫ�أ����ҵ�������δ�򣬷��򷵻�0
{
	Sqlist p;
	ElemType i;
	i=1;//��ʼֵΪ��һ��Ԫ��λ��
	p.elem=L.elem;
	while(i<=L.length&&!(* compare)(*p.elem++,e)) 
	++i;
	if(i<=L.length)
	return i;
	else
	return 0; 
} //LocateElem_Sq


Status GetElem_L(Sqlist L,int i,ElemType &e)
// ����i��Ԫ�ش���ʱ������e����OK
 
{
	if(i<1||i>L.length)
	return OVERFLOW;
	e=L.elem[i-1];
	return OK;
} //GetElem_L

 

/*Status ListDelete_L(LinkList &L,int i,ElemType &e)
//ɾ����i��Ԫ�ز���e������ֵ
{
    p=L;
	j=0;
	while(p->next&&j<i-1)//Ѱ�ҵ�i���ڵ㣬����pָ����ǰ�� 
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
