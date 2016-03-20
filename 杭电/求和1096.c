#include<stdio.h>
int main()
{
	int n,m,i,j,s=0,a[2000];
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%d",&m);
			for(j=0;j<m;j++)
			{
				scanf("%d",&a[j]);
				s=s+a[j];
			}
			if(i!=n-1)
			printf("%d\n\n",s);
			else
			printf("%d\n",s);
			s=0;	
		}
	}
	return 0;	
}
