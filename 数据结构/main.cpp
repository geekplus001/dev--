#include "source.h"

#define colorother 207
#define colorfish 207
#define row 20	//�� 
#define col 60	//�� 
#define UP 8
#define DW 2
#define LF 4
#define RH 6
/****************ȫ�ֱ���*****************/
int LenFish;			//��ĳ��ȣ� 
int speed = 500;		//���ʼλ�ã�
int score = 0;			//��Ϸ������ 
int level = 1;			//��Ϸ�ȼ�����1~7���� 
/*****************************************/ 

typedef int elemType;//�������� 

typedef struct Node{//�ڵ� 
	elemType Pos_X;
	elemType Pos_Y;
	Node *next;
}Node;

/****************��ӡ�߽�*****************/
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
/*1�������ʼ��*/
void InitFish(Node **pNode){
	*pNode = NULL;
}

/*2������������*/ 
Node *CreatFish(Node *pHead, int x, int y){
	Node *p1;
	Node *p2;
	
	p1 = p2 = (Node *)malloc(sizeof(Node));//�����½ڵ�;
	
	p1->Pos_X = x;
	p1->Pos_Y = y;
	p1->next = pHead;
	return p1;
}

/*3����ӡ�������������*/
void PrintFish(Node *pHead){
	Node *p;
	p = pHead;
	if(pHead == NULL){
		Goto_XY(19, 35);
		puts("���ش���\n");
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

/* 4������������*/
int SizeFish(Node *pHead){
	Node *p;
	int size = 0;
	p = pHead;
	while(p != NULL){
		size++; //����size��С��ʵ�ʳ���
		p = p->next; 
	}
	return size;
}

/*5������ı仯*/
Node *ChangeFish(Node *pFish, int x_temp, int y_temp){
	Node *pHead;
	Node *pTemp;
	
	/**************��ǰ�ߣ����������һλ��*************************/
	pFish = CreatFish(pFish, pFish->Pos_X+x_temp, pFish->Pos_Y+y_temp);
	pHead = pFish;
	pTemp = pHead;
	/***************��ǰŲһλ��������ɾ�����һλ��****************/ 
	while(pHead->next != NULL){
		pHead = pHead->next;
	}
	
	pHead = NULL;
	pFish = pTemp;
	return pFish;
}
/******************************************/

/****************6��ɾ����β��****************/
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
/******************7������ƻ��**********************/
void BuildApp(int x, int y){
	Goto_XY(x, y);
	puts("@");
}
/***************************************************/ 
/******************8��������************************/
int main()
{
	/*���ع��*/
	Hide_Cursor(); 
	/*��ӡ�߽�*/
	PrintBound(); 
	/*****************����*��*ָ��*******************/ 
	Node *pFish;
	
	/*****************�������***********************/
	int direction = RH; 	//���н����򣬳�ʼ��Ϊ�ҷ��� �� 
	int length = 0;			//������ �� 
	int X_temp, Y_temp;		//�����ź� �� 
	char key;		 		//��ȡ�������룻 
	InitFish(&pFish);		//��ʼ������
	int x_app, y_app;		//ƻ��λ�ã�

	/************************************************/ 
	
	/***********�����ʼ�� ��Ϊ3����λ*************/ 
	int x1 = 10, y1 = 39, x2 = 10, y2 = 40, x3 = 10, y3 = 41;
	pFish = CreatFish(pFish, x1, y1);
	pFish = CreatFish(pFish, x2, y2);
	pFish = CreatFish(pFish, x3, y3);
	x_app = x3;
	y_app = y3;
	/*************************************************/ 
	
	/*******************����仯**********************/
	while(1){
		
		/**************�Ե�ƻ����ı仯***************/
		while(pFish->Pos_X == x_app && pFish->Pos_Y == y_app){//�ж���ͷ�Ƿ�Ե�ƻ�� 
			/********ƻ����λ����Ϊ�����������*******/ 
			pFish = CreatFish(pFish, x_app, y_app);
			/***************ƻ����λ��****************/ 
			x_app = rand()%(row-1)+1;
			y_app = rand()%(col-1)+1;
			/*************�Ե�ƻ����������************/
			score += level; 
			/*****************************************/ 
		}
		/******************��ӡƻ��*******************/
		BuildApp(x_app, y_app);
		/************����⵽�п����ź�ʱ*************/
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
		
			/****************û�п����źŵ�����***********/
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
			
		/*******************��仯********************/
		pFish = ChangeFish(pFish, X_temp, Y_temp);
		DelFish(&pFish);//ɾ����β�� 
		/*********************************************/ 
		
		/******************��Ϸ���Լ���***************/
		LenFish = SizeFish(pFish);	//�㳤�ȣ� 
		level = LenFish / 10 + 1;		//�ȼ����㣻
		speed = 600 - level*100;	//���н��ٶȣ� 
		/*********************************************/ 
		/*******************��ӡ����******************/ 
		PrintBound();
		PrintFish(pFish);
		/****************��ӡ��Ϣ**********************/
		Set_Color(colorother);
		Goto_XY(1, 61); puts("******************");
		Goto_XY(2, 61);	puts("*   ̰��������   *"); 
		Goto_XY(3, 61);	puts("*    - v1.00 -   *");
		Goto_XY(4, 61);	puts("******************");
		Goto_XY(9, 61); printf("*---2014.10.08---*");
		Goto_XY(10, 61);printf("*   ���㹤����   *"); 
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
		
		/*************�ж����Ƿ񳬳��߽�**************/
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
