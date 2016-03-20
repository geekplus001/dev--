#include<stdio.h>
#include<math.h>
int main()
{
	int a,b,s;
	printf("please enter two numbers\n");
	scanf("%d%d",&a,&b);
	s=sqrt(a)+sqrt(b);
	printf("两数平方根和为：%d\n",s);
	return 0;
	
}
