#include<stdio.h>
#include<malloc.h>
#include<math.h>
int prime(int x)
{
    int *p,i,j,k=1,count=1,ok;
    p=malloc(x*sizeof(int));
    for(i=3;i<=x;i++)
    {
    	for(j=2;j<=sqrt(x);j++)
    		if(i%j==0){ok=0;break;}
    		else {ok=1;continue;}
    	if(ok==1)
    	{
    		p[k++]=i;
    		count++;
    	}
    }
    {
    	p[0]=2;
    	for(i=0;i<count;i++)
    		for(j=0;j<count-i-1;j++)
    			if(p[j]<p[j+1]){k=p[j];p[j]=p[j+1];p[j+1]=k;}
    	for(i=0;i<3;i++)
    	    printf("%d\n",p[i]);
    }
}
int main()
{
	int x;
	scanf("%d",&x);
	prime(x);
	return 0;
}
