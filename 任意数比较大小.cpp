#include<stdio.h>
int main()
{
	int n,i,j;
	
	printf("你想输入几个数n=");
	scanf("%d",&n);
	float t,a[n];
	printf("输入数字:");
	for(i=0;i<n;i++)
	scanf("%f",&a[i]);
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		if(a[j]>a[j+1])
		{ 
		  t=a[j];
		  a[j]=a[j+1];
		  a[j+1]=t;
		} 
	}
	for(j=0;j<n-1;j++)
	printf("%f<",a[j]);
	printf("%f",a[n-1]);
	return 0;
	
}
