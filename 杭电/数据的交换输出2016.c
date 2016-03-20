#include<stdio.h>
int main()
{
	int n,i,t,a[2000],min;
	while(scanf("%d",&n)&&n)
	{
		
			
				for(i=0;i<n;i++)
				scanf("%d",&a[i]);
				min=a[0];
				for(i=1;i<n;i++)
					if(a[i]<min)
					{min=a[i];t=i;}
				if(min!=a[0])
				a[t]=a[0];
				printf("%d",min);
				for(i=1;i<n;i++)
				printf(" %d",a[i]);
				printf("\n"); 
		
	        
	}return 0;
}
