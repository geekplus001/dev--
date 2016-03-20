#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>
#define wx 30
#define wy 30
static int fx,fy,cot=3;
static struct snake *head=NULL;
static struct snake *prev,*current;

struct food
{
	int _fx,_fy;
};
struct food sfood[(wx-2)*(wy-2)];//需先定义结构体模板再定义数组 

struct snake
{
	int sx,sy;
	struct snake *next,*pre;
};

void gotoxy (int x,int y)
{
	COORD pos={x,y};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}

void count()
{
	gotoxy (wx*2.1,wy*0.5);
	printf ("You score:%d",cot-3);
}

void creat_food()//使用顺序表生成食物 
{
	
	int i,k=2,j=4;
	for (i=0;i<=(wx-2)*(wy-2)-cot-1;i++)
	{
		creat :
			if (j>2*wx-2)
			{
				j=4;
				k++;
			}
			current=head;
			while (current!=NULL)
			{
				if (current->sx==j && current->sy==k)
				{
				    j=j+2;
				    goto creat;
				}
				current=current->next;
			}
			sfood[i]._fx=j;
			sfood[i]._fy=k;
			j=j+2;
	}
	srand (time (NULL));
	i=rand()%((wx-2)*(wy-2)-cot);
	fx=sfood[i]._fx;
	fy=sfood[i]._fy;
	gotoxy (fx,fy);
	printf ("★");
	cot++;
}

void gameprint()//游戏开始画面函数（先是欢迎界面，然后是游戏规则）
{
	char a;
	gotoxy(10,8);
	printf("┏┅┅┅┅┅┅┅┅┅┅┅┅┅┓");
	gotoxy(10,9);
	printf("┠    Welcome to Snake.     ┨");
	gotoxy(10,10);
	printf("┠         by_zhu.          ┨");
	gotoxy(10,11);
	printf("┗┅┅┅┅┅┅┅┅┅┅┅┅┅┛");
	gotoxy(41,7);
	printf("┏┯┯┯┯┯┯┯┓");
	gotoxy(41,8);
	printf("┠   Game Tips  ┨");
	gotoxy(41,9);
	printf("┠   ↑    Up   ┨");
	gotoxy(41,10);
	printf("┠   ↓   Down  ┨");
	gotoxy(41,11);
	printf("┠   ←   Left  ┨");
	gotoxy(41,12);
	printf("┠   →   Right ┨");
	gotoxy(41,13);
	printf("┗┷┷┷┷┷┷┷┛");
	gotoxy(25,15);
    printf ("press any key to continue");
    while (!kbhit ())//闪烁 
    {
    	Sleep(100);
    	gotoxy(25,15);
        printf ("                         ");
		Sleep (100);
    	gotoxy(25,15);
        printf ("press any key to continue");
    }
    a=getch();
    a=getch();
}

void wall()//画墙函数 
{
	system("cls");//清屏 
	int i;
	gotoxy (1,1);
	printf ("◆");
    gotoxy (2*wx,1);
    printf ("◆");
    gotoxy (1,wy);
    printf ("◆");
    gotoxy (2*wx,wy);
    printf ("◆");
    for (i=2;i<=wy-1;i++)
    {
    	gotoxy (1,i);
    	printf ("◆");
    	gotoxy (2*wx,i);
    	printf ("◆");
    }
    for (i=3;i<=2*wx-2;i=i+2)
    {
    	gotoxy (i+1,1);
    	printf ("◆");
    	gotoxy (i,wy);
    	printf ("◆");
    }
}

int gameover ()
{
	system ("cls");
	gotoxy (20,10);
	printf ("You loss");
	while (head!=NULL)
	{
		current=head;
		head=head->next;
		free (current);
	}
	exit (1);
}

void hit_wall(int dir)
{
	int _sx=prev->sx,_sy=prev->sy;
	switch (dir)
	{
		case 0:
			_sx=_sx+2;
			break;
		case 1:
			_sy++;
			break;
		case 2:
			_sx=_sx-2;
			break;
		case 3:
			_sy--;
			break;
		default :
			break;
	}
	if (2*wx==_sx || 2==_sx || wy==_sy || 1==_sy)
	gameover();
}

void eat_itself(int dir)
{
	current=head;
	int _sx=prev->sx,_sy=prev->sy;
	switch (dir)
	{
		case 0:
			_sx=_sx+2;
			break;
		case 1:
			_sy++;
			break;
		case 2:
			_sx=_sx-2;
			break;
		case 3:
			_sy--;
			break;
		default :
			break;
	}
	while (current!=NULL)
	{
		if (current->sx==_sx && current->sy==_sy)
		gameover();
		current=current->next;
	}
}

int eat_food(int dir)
{
	int _sx=prev->sx,_sy=prev->sy;
	switch (dir)
	{
		case 0:
			_sx=_sx+2;
			break;
		case 1:
			_sy++;
			break;
		case 2:
			_sx=_sx-2;
			break;
		case 3:
			_sy--;
			break;
		default :
			break;
	}
	if (fx==_sx && fy==_sy)
	{
		current=(struct snake *)malloc (sizeof (struct snake));
		current->sx=fx;
		current->sy=fy;
		gotoxy (fx,fy);
		printf("☉");
		current->next=NULL;
		current->pre=prev;
		prev->next=current;
		prev=current;
		count ();
		creat_food ();
		return 0;
	}
	else
	return 1;
}

void eat_nothing(int dir)
{
	int _sx=prev->sx,_sy=prev->sy;
	switch (dir)
	{
		case 0:
			_sx=_sx+2;
			break;
		case 1:
			_sy++;
			break;
		case 2:
			_sx=_sx-2;
			break;
		case 3:
			_sy--;
			break;
		default :
			break;
	}
	current=(struct snake *)malloc (sizeof (struct snake));
	current->sx=_sx;
	current->sy=_sy;
	gotoxy (current->sx,current->sy);
	printf ("☉");
	gotoxy (head->sx,head->sy);
	printf ("  ");
	head=head->next;
	free (head->pre);
	prev->next=current;
	current->next=NULL;
	current->pre=prev;
	prev=current;
}

void snakemove()
{
	int j,i,dir=0;
	char odr2=' ';
	for (i=0;i<=2;i++)
	{
		current=(struct snake *)malloc (sizeof (struct snake));
		current->sx=26+2*i;
		current->sy=15;
		gotoxy (current->sx,current->sy);
		printf ("☉");
		if (head==NULL)
		{
			head=current;
			current->pre=NULL;
		}
		else
		{
			prev->next=current;
			current->pre=prev;
		}
		current->next=NULL;
		prev=current;
	}
	count ();
	creat_food ();
	while (odr2!='q')
	{
		
		while (!kbhit())
		{
			if (cot>=3 && cot<10)
			j=220;
			else
			if (cot>=10 && cot<20)
			j=190;
			else
			if (cot>=20 && cot<40)
			j=160;
			else
			if (cot>=40 && cot<70)
			j=130;
			else
			if (cot>=70)
			j=100;
			Sleep (j);
		    switch (dir)
			{
				case 0:
				    eat_itself (dir);
					hit_wall (dir);
					if(eat_food (dir))
					eat_nothing (dir);
					break;
				case 1:
					eat_itself (dir);
					hit_wall (dir);
					if (eat_food (dir))
					eat_nothing (dir);
					break;
				case 2:
					eat_itself (dir);
					hit_wall (dir);
					if (eat_food (dir))
					eat_nothing (dir);
					break;
				case 3:
					eat_itself (dir);
					hit_wall (dir);
					if (eat_food(dir))
					eat_nothing (dir);
					break;
			}
		}
		odr2=getch ();
		if(odr2==77 && dir!=2) dir=0;
        if(odr2==80 && dir!=3) dir=1;
        if(odr2==75 && dir!=0) dir=2;
        if(odr2==72 && dir!=1) dir=3;
	}
	gameover();
}

int main()
{
	start:
		gameprint ();
		wall ();
		snakemove ();
}
