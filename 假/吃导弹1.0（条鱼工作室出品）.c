#include <stdio.h>/***���Ե���1.0��*******���㹤���ҳ�Ʒ*****�ް�Ȩ******��ӭת��************/ 
#include <time.h> 
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define daodan printf("�ڡ�")			//���� 
#define chuan printf("��");				//�ɴ� 
/*****************��������***************/ 
int a,b;
void Position(int x, int y)				//���λ�� 
{
	COORD pos = { x - 1, y - 1 };
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}
void Win()								//ʤ����Ľ��� 
{
	Position(10,5);
	printf("you success!!");
	Position(10,6);
	printf("�٣���ͦ������С�ӣ�����������"); 
}
void Fail()								//ʧ�ܺ�Ľ��� 
{
	Position(5,5);
	printf("you lost!!\n");
	printf("�ٽ���������\n");
	printf("�ȴ���һ��...");
} 
void Laix(int v, int fen)				//�˵���ʾ���������������Ѷȣ��÷�...�� 
{
	Position(1,1);
	printf("Σ�գ���������Ϯ����\n");
	printf("�������������������\n");
	printf("��ESC���˳�\n");
	Position(40,3);
	printf("you get:%d",fen);
	
}
void Daodan(int x, int y)				//����λ�� 
{
	Position(x,y);daodan;
}
/**************������*************/ 
int main()
{
	int x=25,y=10,v,temp;
	a=80;b=5;
	//Pris();
	printf("��ѡ���Ѷȵȼ���1~5����");
	scanf("%d",&v);
	int fen=0;
	while(1)
	{
		srand((int)time(0));			//��ϵͳʱ����Ϊ���������������
		temp=rand()%11+10;				//�����������10~15�� 
		b=temp;
		while(1)
		{
			Daodan(a--,b);
			Laix(v,fen);
			Position(x,y);
			chuan;
			Sleep(v*10);
			system("cls");
			if(GetAsyncKeyState(VK_UP))				y--;	//������ 
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
/******���Ե���1.0��**********���㹤���ҳ�Ʒ*****�ް�Ȩ******��ӭת��******************************/ 
