#include<stdio.h>
#include<malloc.h>
int main()
{
	long long int n,i,j,m,k;
    float t;
	struct Student  //struct���Զ��嵽��� 
	{
		long long int num;
		float score;
	};
	struct Student *p;
	printf("������ѧ��������\n");
	scanf("%lld",&n);
	p=malloc(sizeof(struct Student));//���� 
	printf("������ѧ����ѧ�źͳɼ���\n");
	for(i=0;i<n;i++)
		scanf("%lld%f",&p[i].num,&p[i].score);
	for(i=0;i<n-1;i++)//ð������ 
		for(j=0;j<n-i-1;j++) 
		{
			if(p[j].score>p[j+1].score)//k������t�� 
			{
				t=p[j].score;
				p[j].score=p[j+1].score;
				p[j+1].score=t;
				k=p[j].num;
				p[j].num=p[j+1].num;
				p[j+1].num=k;
			}
			
		}
	printf("��������¼ȡ��ѧ��������\n");
    scanf("%lld",&m);
    printf("¼ȡ������Ϊ��\n");
    printf("%5.2f\n",p[n-m].score);
    printf("��¼ȡ��ѧ���ǣ�\n");
    for(i=n-m;i<n;i++)
    printf("%-15lld%5.2f\n",p[i].num,p[i].score);
    return 0;
}
