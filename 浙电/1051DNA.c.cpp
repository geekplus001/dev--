#include<stdio.h>
#define s[] s[]={.,!,X,#}
int main()
{
	int m,n,d[16],a[20][20],i,j,k;
	scanf("%d",&m);
	while(m--)
	{
		scanf("%d",&n);
		for(k=0;k<16;k++)
			scanf("%d",&d[k]);
		for(i=0;i<20;i++)
			for(j=0;j<20;j++)
				scanf("%d",&a[i][j]);
		for(i=0;i<20;i++)
			for(j=0;j<20;j++)
				if(a[i][j]!=0)
				{
					a[i][j]=a[i][j]+a[i][j+1]+a[i][j-1]+a[i-1][j]+a[i+1][j]; 
				}
	}
	return 0;
} 
