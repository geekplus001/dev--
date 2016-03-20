#include<stdio.h>
#include<string.h>
#define N 1001
int main()
{
	int a[N],b[N],i,j,n,long1,long2,max,times=1;
	char s1[N],s2[N];
	scanf("%d",&n);
	while(n--)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		
		scanf("%s%s",s1,s2);
		printf("Case %d:\n",times++);
		printf("%s + %s = ",s1,s2);
		long1=strlen(s1);
		long2=strlen(s2);
		
		for(j=N-1,i=long1-1;i>=0;i--)
			a[j--]=s1[i]-'0';
		for(j=N-1,i=long2-1;i>=0;i--)
			b[j--]=s2[i]-'0';
		if(long1>long2)
			max=long1;
		else
			max=long2;
		for(i=N-1;i>=N-max;i--)
		{
			a[i]+=b[i];
			if(a[i]>9)
			{
				a[i]-=10;
				a[i-1]++;
			}
		}
		if(a[N-max-1]==0)
		for(i=N-max;i<=N-1;i++)
			printf("%d",a[i]);
		else
		for(i=N-max-1;i<=N-1;i++)
			printf("%d",a[i]);
		printf("\n");
		if(n!=0)
			printf("\n");
		
	} 
	return 0;
}
