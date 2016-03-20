#include<stdio.h>
int main()
{
	int a[2000],i,j=0,n,m;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		for(i=0;i<n;i++)
			if(a[i]>m)
			{
				j=i;break;
			}
			else
			j=1;
		if(j==1)
		{
			a[n]=m;
			for(i=0;i<n+1;i++)
			{
				if(i==0)
				printf("%d",a[i]);
				else
				printf(" %d",a[i]);
			}
				printf("\n");
		}
		else
		{
			for(i=n-1;i>=j;i--)
			a[i+1]=a[i];
			a[j]=m;
			for(i=0;i<=n;i++)
			{
				if(i==0)
				printf("%d",a[i]);
				else
				printf(" %d",a[i]);
			}
				printf("\n");
		}
		j=0;
	}
	return 0;
}
