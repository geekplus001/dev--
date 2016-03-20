#include<stdio.h>
int main()
{
	int a,b;
	void action1(int,int),action2(int,int);
	char ch;
	printf("plese enter two integer numbers:");
	scanf("%d%d",&a,&b);
	getchar();
	printf("enter a or A to sum.\nenter b or B to product.\n");
	ch=getchar();
	switch(ch)
	{
		case'a':
		case'A':action1(a,b);break;
		case'b':
		case'B':action2(a,b);break;
		default:putchar('\a');
	}
	return 0;
}
void action1(int x,int y)
{
	printf("x+y=%d",x+y);
}
void action2(int x,int y)
{
	printf("x*y=%d",x*y);
}
