#include<stdio.h>
int main()
{
	int t,i,m,n,x=0,y=0;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		if(m>n){t=m;m=n;n=t;}
		for(i=m;i<=n;i++)
		if(i%2==0)x=x+i*i;
		else y=y+i*i*i;
		printf("%d %d\n",x,y);
		x=0;y=0;
	}
	return 0;	
}
