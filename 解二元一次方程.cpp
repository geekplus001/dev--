#include<stdio.h>
#include<math.h>
int main()
{
	float a,b,c,s,x1,x2;
	scanf("%f%f%f",&a,&b,&c);
	s=(pow(b,2)-4*a*c);
	if(s<0)
		printf("ÎÞÊµ¸ù");
	else 
	{
		x1=(-b+sqrt(s))/2*a;
		x2=(-b-sqrt(s))/2*a;
		printf("%f\n%f\n",x1,x2);
	}
	return 0;
}
