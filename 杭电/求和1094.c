#include<stdio.h>
int main()
{
	int n,a[2000],i,s=0;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			s=s+a[i];
		}
		printf("%d\n",s);
		s=0;
	}
	return 0;
}
