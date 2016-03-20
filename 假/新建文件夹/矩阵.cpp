#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cstring>
using namespace std; 
int main()
{    
	double a[50][50];
    int row,col,i,j,k;
    cout<<"输入矩阵大小（行 列）：";
    cin>>row>>col;
    memset(a,0,sizeof(a));
    cout<<"输入矩阵："<<endl;
    for(i=1;i<=row;i++) 
	{       
		for(j=1;j<=col;j++)
			cin>>a[i][j];
    }    
	for(i=1;i<=row;i++) 
	{       //在原始矩阵右侧加上特征矩阵        
		for(j=col+1;j<=col*2;j++) 
			a[i][j]=(j-i==col)?(1.0):(0.0); 
	}    //进行初等变换 
    for(i=1;i<=row;i++)
    {       
		if(a[i][i]!=1.0)
		{          
			double tmp=a[i][i];
			a[i][i]=1.0;
			for(int j=i+1;j<=col*2;j++)
				a[i][j]/=tmp; 
	    }      
		for(k=1;k<=row;k++)
		{          
			if(i!=k) 
			{             
				double tmp=a[k][i];
				for(int j=1;j<=col*2;j++)
					a[k][j]-=(tmp*a[i][j]); 
		    }          
			else continue;
	   } 
	}    //输出    
	cout<<setiosflags(ios::fixed); 
	for(i=1;i<=row;i++)  
	{       
		for(j=col+1;j<=col*2;j++)
		cout<<setprecision(4)<<a[i][j]<<'\t'; 
		cout<<endl;  
    }    
	system("pause");
    return 0;
}
