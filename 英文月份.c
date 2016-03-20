#include<stdio.h>
#include<malloc.h>
#include<string.h>
int main()
{
    int x; 
    char*p;
    printf("输入1~12显示相应英文月份,输入0结束"); 
    p=(char*)malloc(sizeof(char)*12*3+1);
    strcpy(p,"JanFebMarAprMayJunJulAguSepAucNovDec");  
    do
    {     
        scanf("%d",&x);
        printf("%c%c%c\n",p[x*3-3],p[x*3-2],p[x*3-1]);
    }while(x!=0);
        return 0; 
}
