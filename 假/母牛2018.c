#include<stdio.h>
int ss(int n)
{
    if(n<=4)return n;
    if(n==5)return 6;
    return (ss(n-1)+ ss(n-3));
}
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
         printf("%d\n",ss(n));
    }
    return 0;
}

