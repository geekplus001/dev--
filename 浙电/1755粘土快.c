#include<stdio.h> 
struct stu
{
	int a[1000];
	char name[1000];
}s[1000];
int main()
{
	int x,i,v,b,max,min,y[1000];
	while(scanf("%d",&x)&&x!=-1)
	{
		for(i=0;i<x;i++)
		{
			scanf("%d%d%d%s",&s[i].a[0],&s[i].a[1],&s[i].a[2],s[i].name);
	        y[i]=s[i].a[0]*s[i].a[1]*s[i].a[2];
		}
		max=min=y[0];
		b=v=0; 
		for(i=1;i<x;i++)
		{
			if(y[i]>max)
			{
				max=y[i];
				b=i;
			}
	        if(y[i]<min)
			{
				min=y[i];
				v=i;
			}
			
		}
	    printf("%s took clay from %s.\n",s[b].name,s[v].name);	
	} 
	return 0;
}
