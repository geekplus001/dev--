#include<stdio.h>
int main()
{
	int m,i,j,a[1000],sign=-1;
	float s=1;
	scanf("%d",&m);
	
	for(i=0;i<m;i++)
	scanf("%d",&a[i]);
	for(i=0;i<m;i++)
	{
		for(j=2;j<=a[i];j++)
		{
			s=s+sign*1.0/j;
			sign=sign*(-1);
	    }
		printf("%.2f\n",s);
		s=1;
		sign=-1;
	}
	return 0;
}
