#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*������ɫ*/ 
void Set_Color(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//��ȡ��׼����ľ�� <windows.h>
	//��� ����־Ӧ�ó����еĲ�ͬ�����ͬ������еĲ�ͬ��ʵ�� ����ٿأ�
    SetConsoleTextAttribute(hConsole, color);
	//��API����������ɫ�ͱ���ɫ�ĺ��� ��ʽ��SetConsoleTextAttribute(���,��ɫ);
}
/*��λ���*/
void Goto_XY(int x, int y)
{
	COORD pos = {y, x};
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

/*���ع��*/ 
void Hide_Cursor() 
{
	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };
	HANDLE g_hConsoleOutput;  // ����̨������
	g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // ���ù������
	
}


