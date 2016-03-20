#include<stdio.h>
//#include<stdlib.h>
#include<malloc.h>
int main()
{
	int m,i,*p;
	printf("请输入你想输入多少个整数：\n");
	scanf("%d",&m);
	p=(int*)malloc(m*sizeof(int));
	printf("请输入你要输入的数字：\n");
	for(i=0;i<m;i++)
	scanf("%d",&p[i]);
	for(i=0;i<m;i++)
	printf("%d ",p[i]+1);
	return 0;
}
