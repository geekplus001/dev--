#include<stdio.h>
#include<time.h>
#include<windows.h>
//#include<stdlib.h>
int main()
{
	int i,m,n;
	double x;
	srand((unsigned int)time(0));
	while(1)
	{
	
		for(i=0;i<10;i++)
		{
		   //n=rand();
		   //m=rand();
		   x=rand()*1.0/RAND_MAX;
		   	Sleep(300);
		   printf("%.5lf\n",x);	
		}
	
	}
	return 0;
}
