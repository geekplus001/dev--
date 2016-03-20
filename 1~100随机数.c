#include<stdio.h>
#include<windows.h> 
#include<time.h>
int main()
{
	int x;
	srand((int)time(0));
	while(!kbhit())
	{
	
	x=1+rand()%100;
	printf("%5d",x);
	Sleep(600);

   }
   	return 0;
}
