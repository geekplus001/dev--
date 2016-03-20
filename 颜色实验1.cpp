#include "stdio.h"
#include "Windows.h"
int main() 
{
	
system("color 12");//nice 
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED);
    printf("把这句话颜色变成红色\n");
    SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN);
    printf("把这句话颜色变成黄色\n");
   
}
