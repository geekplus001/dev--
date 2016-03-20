#include<stdio.h>
int main()
{
	int m,n,i,a,b,c,s=0;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(100<=m<=n<=999)
		{
			for(i=m;i<=n;i++)
			{
				a=i%10;
				b=i/10%10;
				c=i/100;
				if(i==a*a*a+b*b*b+c*c*c)
				{
					if(s==0)
					printf("%d",i);
					else
					printf(" %d",i);
					s=s+1;
				}
			} 
			if(s==0)
			printf("no\n");
			else 
			printf("\n");
		}
		s=0;
    }
    return 0;
}
