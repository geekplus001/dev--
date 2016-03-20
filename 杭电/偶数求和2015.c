#include<stdio.h>
int main()
{
	int n,m,t,i,j,k,x=2,s=0,aver;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		t=n/m;
		for(i=0;i<t;i++)
		{
			for(j=0;j<m;j++)
			{
				s=s+x;
				x=x+2;
			}
			aver=s/m;
			if(i==0)
			printf("%d",aver);
			else
			printf(" %d",aver);
			s=0;
		}
		if(n-m*t!=0)
		{
			for(k=0;k<n-m*t;k++)
			{
				s=s+x;
				x=x+2;
			}
			printf(" %d\n",s/(n-m*t));
			s=0;
		}
		else
		printf("\n");
		x=2;
	}
	return 0;
}
