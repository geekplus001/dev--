#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

/*设置颜色*/ 
void Set_Color(int color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);	//获取标准输出的句柄 <windows.h>
	//句柄 ：标志应用程序中的不同对象和同类对象中的不同的实例 方便操控，
    SetConsoleTextAttribute(hConsole, color);
	//是API设置字体颜色和背景色的函数 格式：SetConsoleTextAttribute(句柄,颜色);
}
/*定位光标*/
void Goto_XY(int x, int y)
{
	COORD pos = {y, x};
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

/*隐藏光标*/ 
void Hide_Cursor() 
{
	CONSOLE_CURSOR_INFO cursorInfo = { 1, FALSE };
	HANDLE g_hConsoleOutput;  // 控制台输出句柄
	g_hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(g_hConsoleOutput, &cursorInfo);  // 设置光标隐藏
	
}


