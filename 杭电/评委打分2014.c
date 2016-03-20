#include<stdio.h>
int main()
{
	int n,i,a[1000],max,min,s=0;
	double aver;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		max=min=a[0];
		for(i=1;i<n;i++)
		{
			if(a[i]<min)min=a[i];
			if(a[i]>max)max=a[i];
		}
		for(i=0;i<n;i++)
			s=s+a[i];
		aver=(s-max-min)*1.0/(n-2);
		printf("%.2lf\n",aver);
		s=0;
	}
	return 0;
}
