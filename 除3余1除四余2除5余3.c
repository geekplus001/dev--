#include<stdio.h>
int main()
{
	long long i;
	for(i=1;i<10000000000;i++)
	{
		if(i%3==1&&i%4==2&&i%5==3)
		{
		printf("%lld\n",i);
		break;
     	}
	}
	return 0;
}
