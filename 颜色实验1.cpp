#include "stdio.h"
#include "Windows.h"
int main() 
{
	
system("color 12");//nice 
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("����仰��ɫ��ɺ�ɫ\n");
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("����仰��ɫ��ɻ�ɫ\n");
   
}
