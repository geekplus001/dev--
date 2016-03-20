#include<stdio.h>
//#include<graphics.h>
#include<conio.h>
//#include<stdio.h>
main()
{

	float pi=3.14159265,r;

   system("color 12");
		//system("cls");
	printf("enter radius\n");
	scanf("%f",&r);
	if(r<0)
	printf("enter error\n");
	else
	printf("r=%.2f,c=%.2f,area=%2.f\n",r,2*pi*r,pi*r*r);
	system("pause");
	return 0;
} 
