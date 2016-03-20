#include<stdio.h>
int main()
{
	int n,i,a=0,b=0,c=0;
	float x[2000];
	while(scanf("%d",&n)!=EOF)
	{
		if(n!=0)
		{
			for(i=0;i<n;i++)
			scanf("%f",&x[i]);
			for(i=0;i<n;i++)
			{
				if(x[i]==0)b=b+1;
				if(x[i]<0)a=a+1;
				if(x[i]>0)c=c+1;
			}
			printf("%d %d %d\n",a,b,c);
			a=b=c=0;
	    }
	    else continue;
	}
	return 0;
}
