//1.2//解決輸了的情況// 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

#define Pt printf("*****目標**%d**啊哈哈come on!*****\n",N)
#define Pw printf("\ncongratulation！你贏了哦！~")
#define Pf printf("\nwhat a pity!你輸了哦~")

#define fi for(i=0; i<4; i++)
#define fj for(j=0; j<4; j++)
#define pij printf("%4d",a[i][j])
#define pb printf("%d ",b[i]);

int N;
int i,j,k,h,l,t=100,temp=0;
int a[4][4]={0};
int b[4]={0};

void source()//分數 
{
}
void win(int N)
{
	fi fj{
		if(a[i][j]==N)
			Pw;
	}
}

void fail(int N)
{
	temp=0;
	fi{
		for(j=0; j<3; j++){
			if(a[i][j]==0){
				temp=1;
				break;
			}
			else if(a[i][j]==a[i][j+1]){
				temp=1;
				break;
			}	
		}
	} 
	fi {
		for(j=0; j<3; j++){
			if(a[j][i]==0){
				temp=1;
				break;
			}	
			else if(a[j][i]==a[j+1][i]){
				temp=1;
				break;	
			}
		}
		if(temp==0)	Pf;
	}
}
void seed()
{
	t=100; 
	while(t--){
		h=rand()%4;
		l=rand()%4;
		t--;
		if(a[h][l]==0){
			a[h][l]=2;
			break;
		}
	}
	return ;
}

void gotoxy(int x, int y)
{
	COORD pos = {x, y};
	HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out, pos);
}

void l_add()
{
	fi {
		for(j=0,k=0; j<4; j++){
			if(a[i][j]!=0)
				b[k++]=a[i][j];
		}
		for(j=0; j<4; j++){
			a[i][j]=b[j];
		}
		memset(b,0,sizeof(b));
	}
	fi for(j=0; j<3; j++){
		if(a[i][j]==a[i][j+1]){
			a[i][j] += a[i][j+1];
			a[i][j+1]=0;
		}
	}
	fi {
		for(j=0,k=0; j<4; j++){
			if(a[i][j]!=0)
				b[k++]=a[i][j];
		}
		for(j=0; j<4; j++){
			a[i][j]=b[j];
		}
		memset(b,0,sizeof(b));
	}
	
}

void r_add()
{
	fi {
		for(j=3,k=3; j>=0; j--){
			if(a[i][j]!=0)
				b[k--]=a[i][j];
		}
		for(j=3; j>=0; j--){
			a[i][j]=b[j];
		}
		memset(b,0,sizeof(b));
	}
	fi for(j=3; j>0; j--){
		if(a[i][j]==a[i][j-1]){
			a[i][j] += a[i][j-1];
			a[i][j-1]=0;
		}
	}
	fi {
		for(j=3,k=3; j>=0; j--){
			if(a[i][j]!=0)
				b[k--]=a[i][j];
		}
		for(j=3; j>=0; j--){
			a[i][j]=b[j];
		}
		memset(b,0,sizeof(b));
	}
}

void u_add()
{
	fi {
		for(j=0,k=0; j<4; j++){
			if(a[j][i]!=0)
				b[k++]=a[j][i];
		}
		for(j=0; j<4; j++){
			a[j][i]=b[j];
		}
		memset(b,0,sizeof(b));
	}
	fi for(j=0; j<3; j++){
		if(a[j][i]==a[j+1][i]){
			a[j][i] += a[j+1][i];
			a[j+1][i]=0;
		}
	}
	fi {
		for(j=0,k=0; j<4; j++){
			if(a[j][i]!=0)
				b[k++]=a[j][i];
		}
		for(j=0; j<4; j++){
			a[j][i]=b[j];
		}
		memset(b,0,sizeof(b));
	}
}

void d_add()
{
	fi {
		for(j=3,k=3; j>=0; j--){
			if(a[j][i]!=0)
				b[k--]=a[j][i];
		}
		for(j=3; j>=0; j--){
			a[j][i]=b[j];
		}
		memset(b,0,sizeof(b));
	}
	fi for(j=3; j>0; j--){
		if(a[j][i]==a[j-1][i]){
			a[j][i] += a[j-1][i];
			a[j-1][i]=0;
		}
	}
	fi {
		for(j=3,k=3; j>=0; j--){
			if(a[j][i]!=0)
				b[k--]=a[j][i];
		}
		for(j=3; j>=0; j--){
			a[j][i]=b[j];
		}
		memset(b,0,sizeof(b));
	}
}

int main()
{
	system("title ******初測版1.1*2048*條魚*方向键控制*bug比较多~~*****");
	printf("輸入你希望達到的數（回車結束）：");
	scanf("%d",&N);
	system("cls");
	Pt;
	srand((int)time(0));
	seed();
	int i,j;
	fi
	{
		fj pij; 
		printf("\n");
	}
	while(1){
		while(1)
		{
			if(GetAsyncKeyState(VK_LEFT)){
				l_add();break;
			}
			else if(GetAsyncKeyState(VK_RIGHT)){
				r_add();break;
			}
			else if(GetAsyncKeyState(VK_UP)){
				u_add();break;
			}
			else if(GetAsyncKeyState(VK_DOWN)){
				d_add();break;
			}
			else if(GetAsyncKeyState(VK_ESCAPE))
				return 0;
		}
		//suijishu:
		seed();
		gotoxy(0,1); 
		fi{
			fj pij;
			printf("\n");
		}
		win(N);
		fail(N);
		system("pause");
	}
	return 0;
}
