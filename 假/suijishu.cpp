#include <stdio.h>
#include <windows.h>
//#include <stdlib.h>
#include <time.h>
int main()
{
	int i;
	double n;
	while(1)
	{
		srand((int)time(0));
		for(i=0; i<10; i++)
		{
			n=(1+ (rand()%100000))/1000.0;
			printf("%.4f\n",n);
			Sleep(300);
		}
	}
	return 0;
}
