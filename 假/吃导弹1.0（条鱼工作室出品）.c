#include <stdio.h>/***《吃导弹1.0》*******条鱼工作室出品*****无版权******欢迎转载************/ 
#include <time.h> 
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define daodan printf("口■")			//导弹 
#define chuan printf("口");				//飞船 
/*****************函数声明***************/ 
int a,b;
void Position(int x, int y)				//光标位置 
{
	COORD pos = { x - 1, y - 1 };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void Win()								//胜利后的界面 
{
	Position(10,5);
	printf("you success!!");
	Position(10,6);
	printf("嘿！！挺厉害啊小子！！继续！！"); 
}
void Fail()								//失败后的界面 
{
	Position(5,5);
	printf("you lost!!\n");
	printf("再接再厉！！\n");
	printf("等待下一波...");
} 
void Laix(int v, int fen)				//菜单显示！（操作方法，难度，得分...） 
{
	Position(1,1);
	printf("危险！！导弹来袭！！\n");
	printf("操作方法：方向键控制\n");
	printf("按ESC键退出\n");
	Position(40,3);
	printf("you get:%d",fen);
	
}
void Daodan(int x, int y)				//导弹位置 
{
	Position(x,y);daodan;
}
/**************主函数*************/ 
int main()
{
	int x=25,y=10,v,temp;
	a=80;b=5;
	//Pris();
	printf("请选择难度等级（1~5）：");
	scanf("%d",&v);
	int fen=0;
	while(1)
	{
		srand((int)time(0));			//将系统时间作为产生随机数的种子
		temp=rand()%11+10;				//产生随机数（10~15） 
		b=temp;
		while(1)
		{
			Daodan(a--,b);
			Laix(v,fen);
			Position(x,y);
			chuan;
			Sleep(v*10);
			system("cls");
			if(GetAsyncKeyState(VK_UP))				y--;	//鼠标控制 
			else if(GetAsyncKeyState(VK_DOWN))		y++;
			else if(GetAsyncKeyState(VK_LEFT))		x--;
			else if(GetAsyncKeyState(VK_RIGHT))		x++;
			else if(GetAsyncKeyState(VK_ESCAPE))	return 0;
			if(b==y&&a==x)
			{
				Win();
				fen += x; 
				Sleep(1000);
				a=80;
				break;
			}
			else if(a<x)
			{
				Fail();
				fen -= x;
				Sleep(1000);
				a=80;
				break;
			}
		}
	}
	return 0;
} 
/******《吃导弹1.0》**********条鱼工作室出品*****无版权******欢迎转载******************************/ 
