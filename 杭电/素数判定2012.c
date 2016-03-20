#include<stdio.h>
int main()
{
	int prime(int t); 
	int x,y,i,count=0;
	while(scanf("%d%d",&x,&y)!=EOF)
	{
		count=0;
		if(x!=0||y!=0)
		{
			for(i=x;i<=y;i++)
			{
				if(prime(i*i+i+41)==0)
				{printf("Sorry\n");break;} 
				else
				count=count+1;
		    }
		    if(count==y-x+1)
		    printf("OK\n");    
		}	
	}
	return 0;
}
int prime(int t)
{
	int j,n=1;
	for(j=2;j<=t/2;j++)
	{
		if(t%j==0)
		{
			n=0;break;
		}
	}
	return(n);
}
