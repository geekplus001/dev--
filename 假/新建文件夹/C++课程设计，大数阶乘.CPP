#include<iostream>
using namespace std;
int main()
{  int a[10000],n,j,i;
   for(i=0;i<=10000;i++)
	   a[i]=0;
   cout<<"请输入一个阶乘数,n="<<endl;
   cin>>n;
   a[0]=1;
   for(i=1;i<=n;i++)
   {   
	   for(j=0;j<9999;j++)
		   a[j]=a[j]*i;
	   for(j=0;j<9999;j++)
		   if(a[j]>=10)
		   {  
			   a[j+1]=a[j]/10+a[j+1];
			   a[j]=a[j]%10;
		   }
   }
   cout<<"最后结果是"<<n<<"!="<<endl;



 for(i=9999;i>=0;i--)
	 if(a[i]>0)break;
	 j=i;
	 for(;j>=0;j--)
		 cout<<a[j]<<" ";
		 cout<<endl;
return 0;	 
}
	 
