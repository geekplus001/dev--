#include <iostream>
#include <cstring>

using namespace std;

#define ElemType 	 int
#define Status	     int

#define OK			 1
#define NO 			 0
#define OVERFLOW 	-1
#define UNDERFLOW	-2
#define TRUE		 1
#define ERROR		-1
#define FALSE		 0

#define MAXSIZE	  	 12500

class Triple
{
	public:
		int 		i, j;
		ElemType	e;
};

class TSMatrix
{
	private:
		Triple	data[MAXSIZE + 1];
		int		rpos[MAXSIZE + 1];
		int 	mu, nu, tu;
	
	public:
		TSMatrix(){};
		TSMatrix(int mu, int nu, int tu, Triple const *D);
		TSMatrix FastTransposeSMatrix();
		~TSMatrix(){};
		void Print();
		TSMatrix operator*(TSMatrix const &D);
};

Triple D1[MAXSIZE + 1] =
{
	{0, 0, 0},
	{1, 1, 3},
	{1, 4, 5},
	{2, 2, -1},
	{3, 1, 2},
};

Triple D2[MAXSIZE + 1] = 
{
	{0, 0, 0},
	{1, 2, 2},
	{2, 1, 1},
	{3, 1, -2},
	{3, 2, 4},
};

Triple D3[MAXSIZE + 1];

int num[MAXSIZE];
int ctemp[MAXSIZE];
int cpos[MAXSIZE];

TSMatrix::TSMatrix(int mu, int nu, int tu, Triple const *D):mu(mu), nu(nu), tu(tu)
{
	//构造函数，同时初始化 
	for(int i = 1; i <= tu; ++i)
	{
		data[i].i = D[i].i;
		data[i].j = D[i].j;
		data[i].e = D[i].e;
	}
	
	memset(num, 0, sizeof(num));
		
	for(int i = 1; i <= tu; ++i)
		++num[data[i].i];
	
	rpos[1] = 1;
	for(int i = 2; i <= tu; ++i)
		rpos[i] = rpos[i - 1] + num[i - 1];
}

TSMatrix TSMatrix::FastTransposeSMatrix()
{
	//快速转置 
	int 		p;
	TSMatrix 	Q;
	
	memset(num, 0, sizeof(num));
		
	for(int i = 1; i <= tu; ++i)
		++num[data[i].j];
	
	cpos[1] = 1;
	for(int i = 2; i <= nu; ++i)
		cpos[i] = cpos[i - 1] + num[i - 1];
	
	Q.mu = nu;
	Q.nu = mu;
	Q.tu = tu;
	if(Q.tu)
		for(int i = 1; i <= tu; ++i)
		{
			p = cpos[data[i].j]++;
			
			Q.data[p].i = data[i].j;
			Q.data[p].j = data[i].i;
			Q.data[p].e = data[i].e;
		}
	
	return Q;
}

void TSMatrix::Print()
{
	//打印函数 
	cout << "矩阵的三元组：" << endl;
	cout << "   i   " << "j   " << 'e' << endl;
	for(int i = 1; i <= tu; ++i)
		cout << "   " << data[i].i << "   " << data[i].j << "   " << data[i].e <<endl;
	
	cout << endl; 
}

TSMatrix TSMatrix::operator*(TSMatrix const &D)
{
	//重载*进行三元组矩阵乘法 
	TSMatrix Q;
	
	Q.tu = 0;
	Q.mu = mu;
	Q.nu = D.nu;
	
	if(Q.mu * Q.nu != 0)
	{
		for(int arow = 1; arow <= mu; ++arow)
		{
			memset(ctemp, 0, sizeof(ctemp));
			Q.rpos[arow] = Q.tu + 1;
			
			int tp;
			if(arow < mu)
				tp = rpos[arow + 1];
			else
				tp = tu + 1;
				
			for(int p = rpos[arow]; p < tp; ++p)
			{
				int brow = data[p].j;
				int t;
				if(brow < D.mu)
					t = D.rpos[brow + 1];
				else
					t = D.tu + 1;
					
				for(int q = D.rpos[brow]; q < t; ++q)
				{
					int ccol = D.data[q].j;
					ctemp[ccol] += data[p].e * D.data[q].e;
				}
			}
			
			for(int i = 1; i <= D.nu; ++i)
				if(ctemp[i])
				{
					if(++Q.tu > MAXSIZE)
					{
						Q.tu = -1;
						return Q;
					}
					
					Q.data[Q.tu].i = arow;
					Q.data[Q.tu].j = i;
					Q.data[Q.tu].e = ctemp[i];
				}
		}
	}
	
	return Q;
}

int main()
{
	TSMatrix M(3, 4, 4, D1);
	TSMatrix N(4, 2, 4, D2);
	TSMatrix Q;
	
	M.Print();
	Q = M.FastTransposeSMatrix();
	Q.Print();
	
	Q = M * N;
	Q.Print();
	return 0;
}

