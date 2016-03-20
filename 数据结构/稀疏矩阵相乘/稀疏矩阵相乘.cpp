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

#define MAXSIZE 12500
#define MAXRC  10000 
typedef struct 
{
	int i,j;
	ElemType e;
} Triple;

typedef struct 
{
	Triple data[MAXSIZE+1];
	int mu,nu,tu;
}TSMatrix;

typedef struct    
{
	Triple data[MAXSIZE+1];
	int rpos[MAXRC+1];
	int mu,nu,tu;
}RLSMatrix;



Status CreateSMaxstrix(RLSMatrix &M)
//����ϡ�����
{
	int g,h,e;
    M.tu=0; 
	printf("������Ҫ��������������������");
	scanf("%d%d",&M.mu,&M.nu);
	printf("����������Ԫ�أ�");
	for(g=1;g<=M.mu;g++) 
	{
		M.rpos[g]=M.tu;
		for(h=1;h<=M.nu;h++)
		{
			scanf("%d",&e);
			if(e!=0)
			{
				
				M.tu++; 
			    M.data[M.tu].e=e;
				M.data[M.tu].i=g;	 
				M.data[M.tu].j=h; 
			} 
		} 
	}
} 

Status PrintSMaxtrix(RLSMatrix &M)
{
	int i;
	printf("ϡ��������Ԫ����%d:\n",M.tu);
	printf("Ԫ������Ϊ��");
	for(i=1;i<=M.tu;i++)
		printf("%d(�У�%d �У�%d)",M.data[i].e,M.data[i].i,M.data[i].j); 
}

Status MultSMatrix(RLSMatrix M,RLSMatrix N,RLSMatrix &Q)
//ϡ��������
{
	int arow,brow,tp,ccol;
	int p,t,q;
	int ctemp[12500];
	if(M.nu!=N.mu)
		return ERROR;
	Q.mu=M.mu;
	Q.nu=N.nu;
	Q.tu=0;
	if(M.tu*N.tu!=0)
	{
		for(arow=1;arow<=M.mu;++arow)
		{
			ctemp[arow]=0;
			Q.rpos[arow]=Q.tu+1;
			if(arow<M.mu)
				tp=M.rpos[brow+1];
			else
				tp=M.tu+1;
			for(p=M.rpos[arow];p<tp;++p)
			{
				brow=M.data[p].j;
				if(brow<N.mu)
					t=N.rpos[brow+1];
				else
					t=N.tu+1;
				for(Q.rpos[brow];q<t;++q)
				{
					ccol=N.data[q].j;
					ctemp[ccol]+=M.data[p].e*N.data[q].e;
					
				}
			}	
			for(ccol=1;ccol<Q.nu;++ccol)
				if(ctemp[ccol])
				{
					if(++Q.tu>MAXSIZE)
						return ERROR;
					Q.data[Q.tu].i=arow;
					Q.data[Q.tu].j=ccol;
					Q.data[Q.tu].e=ctemp[ccol];
				}
		}
	}
	return OK;
} 

int main()
{
	RLSMatrix M,N,Q;
	printf("������˵ĵ�һ������\n"); 
	CreateSMaxstrix(M);
    PrintSMaxtrix(M); 
	printf("������˵ĵڶ�������\n");
	CreateSMaxstrix(N);  
	PrintSMaxtrix(N); 
	MultSMatrix(M,N,Q);
	printf("������˽����\n");
    PrintSMaxtrix(Q); 
}
