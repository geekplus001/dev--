#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
void gotoxy(int x,int y)
{
	COORD pos={x,y};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}
void print()
{
	int i;
	printf("���������ө����������������������������������ө�������\n");
		for(i=0;i<10;i++)
			printf("��\n");
	
		for(i=2;i<=11;i++)
		{
			gotoxy(i,4);
			printf("��");
    		gotoxy(i,22);
			printf("��");
			gotoxy(i,26);
			printf("��");
		}
    gotoxy(12,1);
    printf("���������۩����������������������������������۩�������");
	gotoxy(2,2);
		printf("����\n\n\n");
		printf("���\n\n\n���\n\n\n���\n\n\n����") ; 
	gotoxy(2,12);
	    printf("������         ���");
	gotoxy(13,1);
	printf("���򣺼�   1\n��   2\n��   3\n��   4\n�˳�  0\n��ѡ��");
}
double add(int a )
{
	int i;
	double *p;
	double r=0.0;

	printf("���������֣�");
	p=(double*)malloc(a*sizeof(double));
	for(i=0;i<a;i++)
	{
		scanf("%lf",&p[i]);
        r=r+p[i];
	}
	gotoxy(2,6);
	for(i=0;i<a;i++)
		printf("%lf ",p[i]);
	gotoxy(2,24);
		printf("%lf",r);
	return r;
 }
 double cut(int a)
 {
 	int i;
 	double *p;
 	double r=0.0;

	printf("���������֣�");
	p=(double*)malloc(a*sizeof(double));
	for(i=0;i<a;i++)
	{
		scanf("%lf",&p[i]);
		r=r-p[i];
	}
	gotoxy(4,6);
	    for(i=0;i<a;i++)
		printf("%lf ",p[i]);
	gotoxy(4,24);
		printf("%lf",r+p[0]);
	return r+p[0];
 	
 }
 double multiply(int a)
 {
 	int i;
 	double *p;
 	double r=1.0;

	printf("���������֣�");
	p=(double*)malloc(a*sizeof(double));
	for(i=0;i<a;i++)
	{
		scanf("%lf",&p[i]);
		r=r*p[i];
	}
	gotoxy(6,6);
	for(i=0;i<a;i++)
		printf("%lf",p[i]);
	gotoxy(6,24);
	printf("%lf",r);
	return r;
 	
 }
 double division(int a)
 {
 	int i;
 	double *p;
 	double r;
	printf("���������֣�");
	p=(double*)malloc(a*sizeof(double));
	for(i=0;i<a;i++)
		scanf("%lf",&p[i]);
	r=p[0]/p[1];
	for(i=2;i<a;i++)
	    r=r/p[i];
	gotoxy(8,6);
	for(i=0;i<a;i++)
		printf("%lf ",p[i]);
	gotoxy(8,24);
		printf("%lf",r);
	return r;
 	    
 }
double result(int x)
{
	int a;
	printf("�������㼸������");
	scanf("%d",&a);
 
	switch (x)
	{
		
		case 1:add(a);break;
		case 2:cut(a);break;
		case 3:multiply(a);break;
		case 4:division(a);break;
	
		default:printf("enter data error!\n");
	}
}

 int main()
 {
 	int x;
 	while(1)
 	{
	 	
	 	print();
	 	scanf("%d",&x);
	 	if(x==0)
	 	    return 0;
	 	
	 	result(x);
	 	getchar();
	 	getchar();
	 	system("cls");
	 }
 	return 0;
 }
