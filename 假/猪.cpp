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
	printf("�ٺ٣���̯���¶���\n");
	Sleep(4000);
	printf("������˼\n");
	Sleep(4000);
	printf("��ĵ��Խ�����150����Զ��ػ�����ʽ�������ļ�.......\n");
	Sleep(4000);
	printf("ֻ�����롰��Ҫ��΢�֡��ſ�ֹͣ�ػ�����\n");
	Sleep(4000);
	printf("����������ǹز�����Ŷ\n");
	Sleep(4000);
	printf("��ֻ��3�λ���\n");
	Sleep(4000);
	printf("���ֱ�ӹرմ������ֻ�п޵Ļ�����.......\n");
	Sleep(4000);
	printf("�Ͽ�˵�ɣ�ʱ�䲻����\n");
	do
	{
		gets(ch);
		i=3-counter;
		counter ++;
		if(strcmp(ch,"��Ҫ��΢��")==0)
		{
		printf("���ҵ���˿�ɹ�������������\n",i);
		system("shutdown -a");
		exit(0);
		}
		else if (counter>3)
		{ printf("��Ļ����Ѿ����꣬��ȴ�........\n");
		break;
		}
		else if(strcmp(ch,"��Ҫ��΢��")!=0)
		printf("����?\n���˷���һ�α���Ļ���\n�㻹��%d�λ���\n",i);
		
	}while(1);
} 



