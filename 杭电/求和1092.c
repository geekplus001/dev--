#include<stdio.h>
int main()
{
	int n,i,a[2000],s=0;
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		s=s+a[i];
		printf("%d\n",s);
		s=0;
	}
	return 0;
}
