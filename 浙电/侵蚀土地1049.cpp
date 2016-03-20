#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1416
int main()
{
	int i,j,N;
	double *r,s=50.0,R=sqrt(100/PI),*x,*y;
	scanf("%d",&N);
	x=(double*)malloc(N*sizeof(double));
	r=(double*)malloc(N*sizeof(double));
	y=(double*)malloc(N*sizeof(double));
	for(i=0;i<N;i++)
	{
		scanf("%lf%lf",&x[i],&y[i]);
		r[i]=sqrt(x[i]*x[i]+y[i]*y[i]);
	
		for(j=1;;j++)
		{
			if(R>=r[i])
			{
				printf("Property %d: This property will begin eroding in year %d.\n",i+1,j);
		        R=sqrt(100/PI);
		        s=50.0;
				break;
		    }
			else
		    {
		    	s+=50.0;
		    	R=sqrt((2*s)/PI);
		    }	
		}
	}
	printf("END OF OUTPUT.\n");
	return 0;
	
}
