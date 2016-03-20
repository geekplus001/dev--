#include<stdio.h>
int main()
{
	int n,i,s=1;
	while(scanf("%d",&n)!=EOF)
	{
		int a[5000];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		for(i=0;i<n;i++)
		
			if(a[i]%2!=0)
			s=s*a[i];
		
		printf("%d\n",s);
		s=1;
	}
	return 0;
}
