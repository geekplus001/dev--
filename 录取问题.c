#include<stdio.h>
#include<malloc.h>
int main()
{
	long long int n,i,j,m,k;
    float t;
	struct Student  //struct可以定义到外边 
	{
		long long int num;
		float score;
	};
	struct Student *p;
	printf("请输入学生人数：\n");
	scanf("%lld",&n);
	p=malloc(sizeof(struct Student));//开辟 
	printf("请输入学生的学号和成绩：\n");
	for(i=0;i<n;i++)
		scanf("%lld%f",&p[i].num,&p[i].score);
	for(i=0;i<n-1;i++)//冒泡排序 
		for(j=0;j<n-i-1;j++) 
		{
			if(p[j].score>p[j+1].score)//k可以用t换 
			{
				t=p[j].score;
				p[j].score=p[j+1].score;
				p[j+1].score=t;
				k=p[j].num;
				p[j].num=p[j+1].num;
				p[j+1].num=k;
			}
			
		}
	printf("请输入你录取的学生人数：\n");
    scanf("%lld",&m);
    printf("录取分数线为：\n");
    printf("%5.2f\n",p[n-m].score);
    printf("被录取的学生是：\n");
    for(i=n-m;i<n;i++)
    printf("%-15lld%5.2f\n",p[i].num,p[i].score);
    return 0;
}
