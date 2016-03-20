#include<stdio.h>

#include<math.h>
int main()
{
	int m,n,i;
	float a,t;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		a=t=n;
		for(i=0;i<m-1;i++)
		{
			t=sqrt(t);
			a=a+t;
		}
		printf("%.2f\n",a);
	}
	return 0;
}
