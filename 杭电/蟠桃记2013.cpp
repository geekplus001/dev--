#include<stdio.h>
int main()
{
	int n,i,s=1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n-1;i++)
			s=(s+1)*2;
		printf("%d\n",s);
		s=1;
    }
    return 0;
}
