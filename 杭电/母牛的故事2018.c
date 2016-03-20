#include<stdio.h>
int main()
{
	int n,s=0,t,i;
	while(scanf("%d",&n)&&n)
	{
		t=n/4;
		s=s+n;
		for(i=1;i<=t;i++)
		s=s+i*(n-4);
		printf("%d\n",s);
		s=0;
	}
	return 0;
}
