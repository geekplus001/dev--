#include<stdio.h>
int main()
{
	int i,j,n=10, m = 0;
	
	
	float t,a[n];
	printf("����������:");
	for(i=0;i<n;i++)
		scanf("%f",&a[i]);
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
			a[j]>a[j+1]?(t=a[j],a[j]=a[j+1],a[j+1]=t):m++;
	for(i=0;i<n;i++)
	printf("%f<",a[i]);
	return 0;
}
