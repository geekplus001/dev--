#include<stdio.h> 
struct stu
{
	int a[1000];
	char name[1000];
	int y;
}s[1000];
int main()
{
	struct stu *w,*p[1000];
	int x,i,j,k,t;
	while(scanf("%d",&x)&&x!=-1)
	{
		for(i=0;i<x;i++)
		{
			scanf("%d%d%d%s",&s[i].a[0],&s[i].a[1],&s[i].a[2],s[i].name);
	        s[i].y=s[i].a[0]*s[i].a[1]*s[i].a[2];
	        p[i] = &s[i];
        }
		for(i=0;i<x-1;i++)
		{
	        k=i;	
			for(j=0;j<x-1-i;j++)
			{
				if(s[j].y>s[j+1].y)
				k=j;
				if(k!=i)
				{
		        	t=s[j].y;
					s[j+1].y=s[j].y;
					s[j].y=t;
					w=p[j];
					p[j]=p[j+1];
					p[j+1]=w;					
				}
				
			}
		}
		printf("%s took clay from %s.\n",p[x-1]->name,p[0]->name);
	}
	return 0;
}
