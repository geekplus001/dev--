#include<stdio.h>
//#include<stdlib.h>
#include<malloc.h>
int main()
{
	int m,i,*p;
	printf("����������������ٸ�������\n");
	scanf("%d",&m);
	p=(int*)malloc(m*sizeof(int));
	printf("��������Ҫ��������֣�\n");
	for(i=0;i<m;i++)
	scanf("%d",&p[i]);
	for(i=0;i<m;i++)
	printf("%d ",p[i]+1);
	return 0;
}
