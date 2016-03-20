#include<stdio.h> 
#include<stdlib.h>
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0 
#define INFEASIBLE -1
#define OVERFLOW   -2
//Status �Ǻ��������ͣ���ֵ�Ǻ������״̬����
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
//����ն���
{
	Q.base=(QElemType*)malloc(MAXSIZE*sizeof(QElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	Q.length=0;
	return OK;
} 

int QueueLength(SqQueue Q)
//����г���
{
	return(Q.rear-Q.front+MAXSIZE)%MAXSIZE; 
	//return Q.length;
}
 

Status EnQueue(SqQueue &Q,QElemType e)
//����e����β
{
	if((Q.rear+1)%MAXSIZE==Q.front)
		return ERROR;
	Q.base[Q.rear]=e;
	Q.rear=(Q.rear+1)%MAXSIZE;
	Q.length++;
	return OK;
} 

Status DeQueue(SqQueue &Q,QElemType &e)
//ɾ����ͷԪ��
{
	if(Q.front==Q.rear)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXSIZE;
	
	return OK;
} 

int DestroyQueue(SqQueue &Q)
//���ٶ���
{
	free(Q.base);
	Q.base==NULL;
	return OK;
} 

int ClearQueue(SqQueue &Q)
//��ն���
{
	Q.rear==Q.front;
	return OK;
} 
