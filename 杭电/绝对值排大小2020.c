#include<stdio.h>
#include<math.h>
int main()
{
	int n,x,i,j,t,a[2000],b[2000];
	while(scanf("%d",&n)&&n)
	{
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n-1;i++)
		    for(j=0;j<n-1-i;j++)
		    {
				if(abs(a[j])<abs(a[j+1]))
				{t=a[j];a[j]=a[j+1];a[j+1]=t;}
			}
		for(i=0;i<n;i++)
			if(i==0)
			printf("%d",a[i]);
			else
			printf(" %d",a[i]);
			printf("\n");
	}
	return 0;
}
