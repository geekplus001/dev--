#include"Queue.h"

int main()
{
	int i,j;
	QElemType e, ch;
	SqQueue Q;
	InitQueue (Q);
	printf("循环队列的检测。\n队列长度100。\n请输入你要创建的队列的长度：");
	scanf("%d",&j); 
	getchar();
	printf("请输入队列：");
	for(i=0;i<j;i++)
	{
		scanf("%c%c",&e, &ch);
		EnQueue(Q,e);
	}
		 
	printf("构建的队列是：");
	for(i=Q.front ;i<Q.length;i++)
		printf("%c ",Q.base[i]);
	printf("\n请输入一个元素添加到对尾：");
	scanf("%c",&e);
	EnQueue(Q,e);
	printf("现在队列为：");
	for(i=Q.front;i<Q.length;i++)
		printf("%c ",Q.base[i]);
	DeQueue(Q,e);
	printf("\n删除队头后的队列：");
	for(i=Q.front;i<Q.length;i++)
		printf("%c ",Q.base[i]);
	printf("\n队列长度：");
	
	printf("%d",(Q.rear-Q.front+MAXSIZE)%MAXSIZE);
	return 0;	 
}
