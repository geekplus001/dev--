//#include<stdio.h> 

#include<iostream>
using namespace std;

int main() 
{ 
    int m;
    static int a[50000]={0,1};//��һλ���� 
    int i,j,carry,tmp,lenth=1;//carry��ʾ��λ 
    cout<<"������һ������"<<endl; 
    cin>>m; 
    for (i=2;i<=m;i++) 
    { 
        carry=0; 
        for (j=1;j<=lenth;j++) 
        { 
            //�˷�ת��Ϊ�ӷ��ͽ�λ 
            tmp=a[j]*i+carry; 
            a[j]=tmp%10; 
            carry=tmp/10; 
 
            //����н�λ������ǰ��չһλ 
            if (j==lenth&&carry!=0) 
                lenth++; 
        } 
    } 
    for(int k=lenth;k>=1;k--) 
        cout<<a[k]; 
} 
