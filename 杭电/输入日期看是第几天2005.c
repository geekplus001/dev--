#include<stdio.h>
int main()
{
	int leap(int a);
	int a,b,c,d=0;
	while(scanf("%d/%d/%d",&a,&b,&c)!=EOF)
	{
		if(b>2)
			if(leap(a)==1)d=d+29;
			else d=d+28;
		switch(b)
		{
			case 2:
			case 3:d=d+31;break;
			case 4:d=d+62;break;
			case 5:d=d+92;break;
			case 6:d=d+123;break;
			case 7:d=d+153;break;
			case 8:d=d+184;break;
			case 9:d=d+215;break;
			case 10:d=d+245;break;
			case 11:d=d+276;break;
			case 12:d=d+306;break;
		}
		d=d+c;
		printf("%d\n",d);
		d=0;	
    }
    return 0;
}
int leap(int a)
{
	if(a%4==0&&a%100!=0||a%400==0)
	return 1;
}
