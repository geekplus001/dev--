#include<stdio.h>
#define n 4
#define m 4
double sumation(double a1, double a2, int o);

int main()
{
	double sum2,sum3,sum4;
	int i1,i2,i3,i4,j1,j2,j3,a[n];                                 //a[]为输入的整数
	char op[m]={'+','-','*','/'};                            //op[]为运算符号
	printf("4 integers (0-10):  ");
	scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3]);
	printf("\n");
	for(i1=0;i1<n;i1++)
	    {
			for(i2=0;i2<n;i2++)
		        if(i2!=i1)
		        {	
					for(j1=0;j1<m;j1++)
		              {
						   sum2=sumation(a[i1],a[i2],j1);
			               for(i3=0;i3<n;i3++)
			                  if(i3!=i1&&i3!=i2)
			                    {
									for(j2=0;j2<m;j2++)
			                        {
										 sum3=sumation(sum2,a[i3],j2);
				                         for(i4=0;i4<n;i4++)
				                            if(i4!=i1&&i4!=i2&&i4!=i3)
				                              {
											  	  for(j3=0;j3<m;j3++)
				                                  {
													   sum4=sumation(sum3,a[i4],j3);
					                                   if(sum4==24.0)
					                                   {
													   	  if((op[j1]=='+'||op[j1]=='-')&&(op[j2]=='*'||op[j2]=='/'))
					                                          printf("(%d %c %d) %c %d %c %d = 24\n",a[i1],op[j1],a[i2],op[j2],a[i3],op[j3],a[i4]);
					                                      else 
					                                      if((op[j2]=='+'||op[j2]=='-')&&(op[j3]=='*'||op[j3]=='/'))
					                                          printf("(%d %c %d %c %d) %c %d = 24\n",a[i1],op[j1],a[i2],op[j2],a[i3],op[j3],a[i4]);
					                                        else
					                                          printf("%d %c %d %c %d %c %d = 24\n",a[i1],op[j1],a[i2],op[j2],a[i3],op[j3],a[i4]);
					                                   }
				                                  }
				                              }
			                        }
			                    }
		               }
		        }
	    }
	    return 0;
}


double sumation(double a1, double a2, int o)
{
	double sum;
	if(o==0) 
	   sum=a1+a2;
	else 
	   if(o==1) 
	     sum=a1-a2;
	   else 
	     if(o==2) 
	       sum=a1*a2;
	     else 
	       {
			   if(a2==0.0)                                 //如果除以零，设置结果为一大数
		          sum=100000.0;
		        else
		          sum=a1/a2;
	       }
	return sum;
}
