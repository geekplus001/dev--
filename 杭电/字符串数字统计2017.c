#include<stdio.h>
#include<string.h>
main() 
{
	int i,j,k,n,count=0;
	char a[2000];	
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		{
			scanf("%s",a);
			j=strlen(a);
			for(k=0;k<j;k++)
			{
				if('0'<=a[k]&&a[k]<='9')
				count=count+1;
			}
			printf("%d\n",count);
			count=0;
		}
	}
	return 0;
}
