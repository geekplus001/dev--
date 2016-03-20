
#include"lianbiao.h"
void shanchu(LinkList &L,int mink,int maxk)
{
	//LinkList p,q;
	p=L;
	while (p->next)
	{
		if(p->next->data>mink&&p->next->data<maxk)
		{
			q=p->next;
			p->next=q->next;
			free(q);
			
		}
		else
		p=p->next;
	}
}
int main()
{
	//InitList_L(L);
	LinkList L;
	LinkList g,h; 
	int i,s,mink,maxk; 
	printf("请输入你要建立的链表的长度：");
	scanf("%d",&s);
		L=(LinkList)malloc(sizeof(LNode));
		L->next=NULL; 
		g=L; 
	printf("请依此输入链表元素：");
	for(i=0;i<s;i++)
	{
		h=(LinkList)malloc(sizeof(LNode));
		g->next=h;
		scanf("%d",&h->data);
		g=g->next; 
	} 
	h->next=NULL;
	printf("请输入要删除的元素范围，先输入最小值再输入最大值："); 
	scanf("%d%d",&mink,&maxk);
//	scanf("%d",&maxk);
	shanchu(L,mink,maxk);
	printf("操作结果：");
	g=L->next;
	while(g)
	{
		printf("%d ",g->data);
		g=g->next; 
	} 
	return 0; 
} 
