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
    cout<<"��������С���� �У���";
    cin>>row>>col;
    memset(a,0,sizeof(a));
    cout<<"�������"<<endl;
    for(i=1;i<=row;i++) 
	{       
		for(j=1;j<=col;j++)
			cin>>a[i][j];
    }    
	for(i=1;i<=row;i++) 
	{       //��ԭʼ�����Ҳ������������        
		for(j=col+1;j<=col*2;j++) 
			a[i][j]=(j-i==col)?(1.0):(0.0); 
	}    //���г��ȱ任 
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
	}    //���    
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
