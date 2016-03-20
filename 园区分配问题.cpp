#include<stdio.h>
#include<string.h>
#include<windows.h> 
#include<time.h>

int main()
{
	char A[] = {"温雅"};
	char B[] = {"王迪"};
	char C[] = {"黄志强"};
	char D[] = {"梁守婧"};
	char E[] = {"李潇"};
	char F[] = {"郭燕洁"};
	char G[] = {"高禄峰"};
	char H[] = {"孟亚彬"}; 
	char J[] = {"小明"};
/*	char K[] = {"小晨"}; 
	char L[] = {"小鱼"};
	char M[] = {"小飞"};
	char N[] = {"小占"}; */
	int a[4] = {1,1,1,1};
	int b[4] = {1,1,1,1};
	int c[4] = {1,1,1,1};
	int d[4] = {1,1,1,1};
	int e[4] = {1,1,1,1};
	int f[4] = {1,1,1,1};
	int g[4] = {1,1,1,1};
	int h[4] = {1,1,1,1};
	int j[4] = {1,1,1,1};
/*	int k[4] = {1,1,1,1}; 
	int l[4] = {1,1,1,1}; 
	int m[4] = {1,1,1,1};
	int n[4] = {1,1,1,1};*/
	char s[4][5] = {"柳园","荷园","菊园","松园"};
	int X[] = {3,2,2,2};
	int x,i;
	
	srand((int)time(0));
	for(i=0;i<4;i++)
	{
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&a[x]!=0)
			{
				printf("%s:%s\n",A,s[x]);
				a[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&b[x]!=0)
			{
				printf("%s:%s\n",B,s[x]);
				b[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&c[x]!=0)
			{
				printf("%s:%s\n",C,s[x]);
				c[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&d[x]!=0)
			{
				printf("%s:%s\n",D,s[x]);
				d[x] = 0;
				X[x]--;
				break;
			}
		
		}
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&e[x]!=0)
			{
				printf("%s:%s\n",E,s[x]);
				e[x] = 0;
				X[x]--;
				break;
			}
		
		}
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&f[x]!=0)
			{
				printf("%s:%s\n",F,s[x]);
				f[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&g[x]!=0)
			{
				printf("%s:%s\n",G,s[x]);
				g[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&h[x]!=0)
			{
				printf("%s:%s\n",H,s[x]);
				h[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&j[x]!=0)
			{
				printf("%s:%s\n",J,s[x]);
				j[x] = 0;
				X[x]--;
				break;
			}
		}
		
/*		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&k[x]!=0)
			{
				printf("%s:%s\n",K,s[x]);
				k[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&l[x]!=0)
			{
				printf("%s:%s\n",L,s[x]);
				l[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&m[x]!=0)
			{
				printf("%s:%s\n",M,s[x]);
				m[x] = 0;
				X[x]--;
				break;
			}
		}
		
		while(1)
		{
			x = rand()%4;
			if(X[x]!=0&&n[x]!=0)
			{
				printf("%s:%s\n",N,s[x]);
				n[x] = 0;
				X[x]--;
				break;
			}
		}*/
 		printf("------------我是华丽的分割线-------------\n");
 		X[0] = 3;
		X[1] = 2;
		X[2] = 2;
		X[3] = 2;
	}
	return 0;
}
