#include<stdio.h> 
#include<stdlib.h>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0 
#define INFEASIBLE -1
#define OVERFLOW   -2
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status; 
typedef int ElemType; 

typedef char QElemType; 
#define MAXSIZE 100
typedef struct
{
	QElemType * base;
	int front;
	int rear;
	int length;
} SqQueue;

Status InitQueue(SqQueue &Q)
//构造空队列
{
	Q.base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	Q.length=0;
	return OK;
} 

int QueueLength(SqQueue Q)
//求队列长度
{
	return(Q.rear-Q.front+MAXSIZE)%MAXSIZE; 
	//return Q.length;
}
 

Status EnQueue(SqQueue &Q,QElemType e)
//插入e到队尾
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	Q.length++;
	return OK;
} 

Status DeQueue(SqQueue &Q,QElemType &e)
//删除队头元素
{
	if(Q.front==Q.rear)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	
	return OK;
} 

int DestroyQueue(SqQueue &Q)
//销毁队列
{
	free(Q.base);
	Q.base==NULL;
	return OK;
} 

int ClearQueue(SqQueue &Q)
//清空队列
{
	Q.rear==Q.front;
	return OK;
} 
