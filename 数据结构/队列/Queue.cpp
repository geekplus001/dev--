#include"Queue.h"

int main()
{
	int i,j;
	QElemType e, ch;
	SqQueue Q;
	InitQueue (Q);
	printf("ѭ�����еļ�⡣\n���г���100��\n��������Ҫ�����Ķ��еĳ��ȣ�");
	scanf("%d",&j); 
	getchar();
	printf("��������У�");
	for(i=0;i<j;i++)
	{
		scanf("%c%c",&e, &ch);
		EnQueue(Q,e);
	}
		 
	printf("�����Ķ����ǣ�");
	for(i=Q.front ;i<Q.length;i++)
		printf("%c ",Q.base[i]);
	printf("\n������һ��Ԫ����ӵ���β��");
	scanf("%c",&e);
	EnQueue(Q,e);
	printf("���ڶ���Ϊ��");
	for(i=Q.front;i<Q.length;i++)
		printf("%c ",Q.base[i]);
	DeQueue(Q,e);
	printf("\nɾ����ͷ��Ķ��У�");
	for(i=Q.front;i<Q.length;i++)
		printf("%c ",Q.base[i]);
	printf("\n���г��ȣ�");
	
	printf("%d",(Q.rear-Q.front+MAXSIZE)%MAXSIZE);
	return 0;	 
}
