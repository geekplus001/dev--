#include<stdio.h>
int main()
{
	float a[10],t;
	int i,j;
	printf("ÇëÊäÈë10¸öÊı\n");
	for(i=0;i<10;i++)
	scanf("%f",&a[i]);
	printf("\n");
	for(i=0;i<9;i++)
	  for(j=0;j<9-i;j++)
	  if(a[j]>a[j+1])
	  {
	  t=a[j];
	  a[j]=a[j+1];
	  a[j+1]=t;
  	  }
	for(i=0;i<10;i++)
	printf("%.4f<",a[i]);
	return 0;
}
