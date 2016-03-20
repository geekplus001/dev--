#include "source.h"

#define colorother 207
#define colorfish 207
#define row 20	//行 
#define col 60	//列 
#define UP 8
#define DW 2
#define LF 4
#define RH 6
/****************全局变量*****************/
int LenFish;			//鱼的长度； 
int speed = 500;		//鱼初始位置；
int score = 0;			//游戏分数； 
int level = 1;			//游戏等级；（1~7）； 
/*****************************************/ 

typedef int elemType;//定义类型 

typedef struct Node{//节点 
	elemType Pos_X;
	elemType Pos_Y;
	Node *next;
}Node;

/****************打印边界*****************/
void PrintBound(){
	int i, j;
	for(i=0; i<=col; i++){
		Goto_XY(0, i);		printf("*");
		Goto_XY(row, i);	printf("*");
	}
	for(i=0; i<=row; i++){
		Goto_XY(i, 0);		printf("*");
		Goto_XY(i, col);	printf("*");
	}
} 
/*1、链表初始化*/
void InitFish(Node **pNode){
	*pNode = NULL;
}

/*2、建立新链表*/ 
Node *CreatFish(Node *pHead, int x, int y){
	Node *p1;
	Node *p2;
	
	p1 = p2 = (Node *)malloc(sizeof(Node));//申请新节点;
	
	p1->Pos_X = x;
	p1->Pos_Y = y;
	p1->next = pHead;
	return p1;
}

/*3、打印链表，链表遍历；*/
void PrintFish(Node *pHead){
	Node *p;
	p = pHead;
	if(pHead == NULL){
		Goto_XY(19, 35);
		puts("严重错误！\n");
	}
	else{
		Goto_XY(p->Pos_X, p->Pos_Y);
		Set_Color(colorfish);
		printf("%d", level); 
		p = p->next;
		while(NULL != p){
			Goto_XY(p->Pos_X, p->Pos_Y);
			Set_Color(colorfish);
			puts("0"); 
			p = p->next;
		}
	}
}

/* 4、返回链表长度*/
int SizeFish(Node *pHead){
	Node *p;
	int size = 0;
	p = pHead;
	while(p != NULL){
		size++; //遍历size大小的实际长度
		p = p->next; 
	}
	return size;
}

/*5、鱼身的变化*/
Node *ChangeFish(Node *pFish, int x_temp, int y_temp){
	Node *pHead;
	Node *pTemp;
	
	/**************向前走（链表中添加一位）*************************/
	pFish = CreatFish(pFish, pFish->Pos_X+x_temp, pFish->Pos_Y+y_temp);
	pHead = pFish;
	pTemp = pHead;
	/***************向前挪一位（链表中删除最后一位）****************/ 
	while(pHead->next != NULL){
		pHead = pHead->next;
	}
	
	pHead = NULL;
	pFish = pTemp;
	return pFish;
}
/******************************************/

/****************6、删除鱼尾巴****************/
void DelFish(Node **pFish){
	Node *pHead;
	Node *pTemp; 
	Node *p;
	
	pHead = *pFish;
	pTemp = pHead;
	
	p = pHead;
	pHead = p->next;
	while(pHead->next !=NULL){
		p = pHead;
		pHead = pHead->next;
	}	
	p->next = NULL;
	
	*pFish = pTemp;
}
/***************************************************/ 
/******************7、放下苹果**********************/
void BuildApp(int x, int y){
	Goto_XY(x, y);
	puts("@");
}
/***************************************************/ 
/******************8、主函数************************/
int main()
{
	/*隐藏光标*/
	Hide_Cursor(); 
	/*打印边界*/
	PrintBound(); 
	/*****************定义*鱼*指针*******************/ 
	Node *pFish;
	
	/*****************定义变量***********************/
	int direction = RH; 	//鱼行进方向，初始化为右方向 ； 
	int length = 0;			//鱼身长度 ； 
	int X_temp, Y_temp;		//输入信号 ； 
	char key;		 		//获取键盘输入； 
	InitFish(&pFish);		//初始化鱼身；
	int x_app, y_app;		//苹果位置；

	/************************************************/ 
	
	/***********鱼身初始化 身长为3个单位*************/ 
	int x1 = 10, y1 = 39, x2 = 10, y2 = 40, x3 = 10, y3 = 41;
	pFish = CreatFish(pFish, x1, y1);
	pFish = CreatFish(pFish, x2, y2);
	pFish = CreatFish(pFish, x3, y3);
	x_app = x3;
	y_app = y3;
	/*************************************************/ 
	
	/*******************鱼身变化**********************/
	while(1){
		
		/**************吃到苹果后的变化***************/
		while(pFish->Pos_X == x_app && pFish->Pos_Y == y_app){//判断鱼头是否吃到苹果 
			/********苹果的位置作为鱼的生长部分*******/ 
			pFish = CreatFish(pFish, x_app, y_app);
			/***************苹果的位置****************/ 
			x_app = rand()%(row-1)+1;
			y_app = rand()%(col-1)+1;
			/*************吃到苹果分数增加************/
			score += level; 
			/*****************************************/ 
		}
		/******************打印苹果*******************/
		BuildApp(x_app, y_app);
		/************当检测到有控制信号时*************/
		if(kbhit()){
			key = getch();
			switch( key ){
				case 'W':
				case 'w':
					if(direction != UP && direction != DW){
						X_temp = -1;
						Y_temp = 0;
						direction = UP;
					}
					break;
				case 'S': 
				case 's':
					if(direction != DW && direction != UP){
						X_temp = 1;
						Y_temp = 0;
						direction = DW;
					}
					break;
				case 'A': 
				case 'a':
					if(direction != LF && direction != RH){
						X_temp =  0;
						Y_temp = -1;
						direction = LF;
					}
					break;
				case 'D':
				case 'd':
					if(direction != RH && direction != LF){
						X_temp = 0;
						Y_temp = 1;
						direction = RH;
					}
					break;
				case ' ':
					Goto_XY(10, 24);
					Set_Color(111);
					puts("   pause   ");
					Goto_XY(11,21);
					system("pause");
					break;			
				default : break;
				
			}	
		}
		else{
			/*********************************************/ 
		
			/****************没有控制信号的输入***********/
			switch( direction ){
				case UP:
					X_temp = -1;
					Y_temp = 0;
					break;
				case DW:
					X_temp = 1;
					Y_temp = 0;
					break;
				case LF:
					X_temp = 0;
					Y_temp = -1;
					break;
				case RH:
					X_temp = 0;
					Y_temp = 1;
					break;
				default :
					break;
			}
			
		}
			
		/*******************鱼变化********************/
		pFish = ChangeFish(pFish, X_temp, Y_temp);
		DelFish(&pFish);//删除鱼尾巴 
		/*********************************************/ 
		
		/******************游戏属性计算***************/
		LenFish = SizeFish(pFish);	//鱼长度； 
		level = LenFish / 10 + 1;		//等级计算；
		speed = 600 - level*100;	//鱼行进速度； 
		/*********************************************/ 
		/*******************打印鱼身******************/ 
		PrintBound();
		PrintFish(pFish);
		/****************打印信息**********************/
		Set_Color(colorother);
		Goto_XY(1, 61); puts("******************");
		Goto_XY(2, 61);	puts("*   贪吃条鱼鱼   *"); 
		Goto_XY(3, 61);	puts("*    - v1.00 -   *");
		Goto_XY(4, 61);	puts("******************");
		Goto_XY(9, 61); printf("*---2014.10.08---*");
		Goto_XY(10, 61);printf("*   条鱼工作室   *"); 
		Goto_XY(11, 61);puts("******************");
		Set_Color(111);
		Goto_XY(5, 61);	printf("*  level    %004d *", level);
		Goto_XY(6, 61);	printf("*  speed    %004d *", speed);
		Goto_XY(7, 61);	printf("*  score    %004d *", score);
		Goto_XY(8, 61); printf("*  length   %004d *", LenFish);
		Set_Color(colorother);
		/**********************************************/ 
		Sleep(speed);
		/*********************************************/
		
		/*************判断鱼是否超出边界**************/
		if(pFish->Pos_X<1||pFish->Pos_X>=row||pFish->Pos_Y<1||pFish->Pos_Y>=col){
			Goto_XY(10, 20);
			Set_Color(192);
			puts("Your Fish is dead!!!");
			getchar();
			return 0;
		}
		/**********************************************/ 
		
		system("cls");
	} 
	/*************************************************/ 
	
	
	return 0;
}
