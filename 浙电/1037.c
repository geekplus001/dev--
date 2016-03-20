#include<stdio.h>
#include<math.h>
int main()
{
	int n,a,b,i;
	float s;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&a,&b);
		if(a*b%2==0)
		s=a*b;
		else
		s=a*b-1+sqrt(2);
		printf("Scenario #%d:\n",i);
		printf("%.2f\n\n",s);
	}
	return 0;
}
