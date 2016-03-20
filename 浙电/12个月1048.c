#include<stdio.h> 
int main()
{
	int i;
	double a[12];
	double s ;
	for(i = 0; i < 12; i++)
	{
		scanf("%lf", &a[i]);
		s=s+a[i];
	}
	printf("$%.2lf",s/12); 
	return 0;
}
