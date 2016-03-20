#include<stdio.h> 
#include<conio.h> 
#include<malloc.h> 
#include<string.h> 

typedef struct 

{ 
	char studentNumber[10];/*ѧ��ѧ��*/ 
	char studentName[20];/*ѧ������*/ 
	char className[20];/*�༶����*/ 
	float mark1;/*��1�ųɼ�*/ 
	float mark2;/*��2�ųɼ�*/ 
	float mark3;/*��3�ųɼ�*/ 
	struct STUDENT *next; 
}STUDENT; 
STUDENT *headLink;/*�����ͷָ��*/ 

/*�����Ǻ�������*/ 

void ReadInfoFormFile(void);      //���ļ��ж�ѧ����Ϣ��������
void DesplayMenu(void); 	      //��ʾ�˵��������û������� �����Ӧ�Ĺ���  
void CreateHeadLink(void);        //���������ͷ 
STUDENT *MallocNode(void);        //����һ���½�㣬�������ʼ�� 
void GetInformation(STUDENT *t);  //Ҫ���û�������Ϣ���½����
void OutputInformation(void);     //��ʾ����ѧ������Ϣ
void DesplayInfoBystudentName(void);//�����û������������ʾ��ѧ������Ϣ
void DesplayInfoBystudentNumber(void);//�����û������ѧ����ʾ��ѧ������Ϣ
void DesplayOneNode(STUDENT *t);  //���һ��������Ϣ 
void InsertOneNode(STUDENT *t);   //���½��ӵ�������
void DeleteNodeBystudentNumber(void);//�����û������ѧ��ɾ����ѧ��
void ChangeMarkByName(void);     //�����û�����������޸�ѧ���ɼ�
void ChangeMarkByNumber(void);   //�����û������ѧ���޸�ѧ���ɼ�
void SaveLinkToFile(void);       //�������ݺ����˳�
void DesplayMarkSegment(void);  //��ʾ�������ε�ѧ���ɼ�
void CompositorByTotalMark(void);//���ܳɼ����� 
int choose;/*���ڽ����û���ѡ��*/ 

/*������*/ 

main() 
{ 
	CreateHeadLink(); //�������ܣ����������ͷ 
	ReadInfoFormFile(); //�������ܣ����ļ��ж�ѧ����Ϣ��������   
	DesplayMenu();//�������ܣ���ʾ�˵��������û������� �����Ӧ�Ĺ���  
} 
/************************************ 
�������ܣ����ļ��ж�ѧ����Ϣ�������� 
************************************/ 
void ReadInfoFormFile(void) 
{ 
	FILE *fp; 
	STUDENT *p; 
	fp=fopen("student.txt","r"); 
	if(!fp) 
	{ 
		printf("�ļ�������\n"); 
		return; 
	} 
	p=MallocNode(); 
	while(fscanf(fp,"%s%s%s%f%f%f",p->studentNumber,p->studentName,p->className,&p->mark1,&p->mark2,&p->mark3)>0) 
	{ 
		InsertOneNode(p); 
		p=MallocNode(); 
	} 
	fclose(fp); 
} 
/************************************ 
�������ܣ���ʾ�˵��������û������� 
�����Ӧ�Ĺ��� 
************************************/ 
void DesplayMenu(void) 
{ 
	STUDENT *p; 
	printf("-------��ѡ����Ӧ����------------\n\n"); 
	printf("| 1 ��ʾ����ѧ������Ϣ |\n"); 
	printf("| 2 ��������ѯ |\n"); 
	printf("| 3 ��ѧ�Ų�ѯ |\n"); 
	printf("| 4 ����ѧ�� |\n"); 
	printf("| 5 ɾ��ѧ�� |\n"); 
	printf("| 6 �������޸�ѧ���ɼ� |\n"); 
	printf("| 7 ��ѧ���޸�ѧ���ɼ� |\n"); 
	printf("| 8 ��������ѧ����Ϣ |\n"); 
	printf("| 9 ��ʾ����Ͳ�����ѧ���ɼ� |\n"); 
	printf("| 10 ������������� |\n"); 
	printf("| 11 �˳� |\n\n"); 
	scanf("%d",&choose);/*ȡ���û���ѡ��*/ 
	switch(choose) 
	{ 
		case 1: 
		OutputInformation();/*��ʾ����ѧ������Ϣ*/ 
		break; 
		case 2: 
		DesplayInfoBystudentName(); 
		break; 
		case 3: 
		DesplayInfoBystudentNumber();/*�����û������ѧ����ʾ��ѧ������Ϣ*/ 
		break; 
		case 4: 
		p=MallocNode();/*������һ���½��*/ 
		GetInformation(p);/*Ҫ���û�������Ϣ���½����*/ 
		InsertOneNode(p);/*���½��ӵ�������*/ 
		break; 
		case 5: 
		DeleteNodeBystudentNumber();/*�����û������ѧ��ɾ����ѧ��*/ 
		break; 
		case 6: 
		ChangeMarkByName();/*�����û�����������޸�ѧ���ɼ�*/ 
		break; 
		case 7: 
		ChangeMarkByNumber();/*�����û������ѧ���޸�ѧ���ɼ�*/ 
		break; 
		case 8: 
		SaveLinkToFile();/*��������*/ 
		break; 
		case 9: 
		DesplayMarkSegment();/*��ʾ�������ε�ѧ���ɼ�*/ 
		break; 
		case 10: 
		CompositorByTotalMark(); 
		break; 
		case 11: 
		SaveLinkToFile();/*�������ݺ����˳�*/ 
		free(headLink); 
		exit(1); 
		break; 
		default: 
		break; 
	} 
	DesplayMenu();/*�ݹ����*/ 
} 
/************************************ 
�������ܣ����������ͷ 
************************************/ 
void CreateHeadLink(void) 
{ 
	STUDENT *p; 
	p=(STUDENT*)malloc(sizeof(STUDENT)); 
	headLink=p; 
	p->next=NULL; 
} 
/************************************ 
�������ܣ�����һ���½�㣬�������ʼ�� 
************************************/ 
STUDENT *MallocNode(void) 
{ 
	STUDENT *p; 
	int i; 
	p=(STUDENT*)malloc(sizeof(STUDENT)); 
	if(p==NULL) 
	return NULL; 
	for(i=0;i<10;i++) 
		p->studentNumber[i]='\0'; 
	for(i=0;i<20;i++) 
		p->studentName[i]='\0'; 
	for(i=0;i<20;i++) 
		p->className[i]='\0'; 
	p->mark1=0.0; 
	p->mark2=0.0; 
	p->mark3=0.0; 
	p->next=NULL; 
	return p; 
} 
/************************************ 
�������ܣ�ȡ���û������ѧ����Ϣ 
************************************/ 
void GetInformation(STUDENT *t) 
{ 
	printf("������ѧ��ѧ�ţ�\n"); 
	scanf("%s",t->studentNumber); 
	printf("������ѧ��������\n"); 
	scanf("%s",t->studentName); 
	printf("������������ڰ༶��\n"); 
	scanf("%s",t->className); 
	printf("�������1�ųɼ���\n"); 
	scanf("%f",&(t->mark1)); 
	printf("�������2�ųɼ���\n"); 
	scanf("%f",&(t->mark2)); 
	printf("�������3�ųɼ���\n"); 
	scanf("%f",&(t->mark3)); 
} 
/************************************ 
�������ܣ�������Ľ�β������һ����� 
************************************/ 
void InsertOneNode(STUDENT *t) 
{ 
	STUDENT *p; 
	p=headLink; 
	while(p->next) 
	{ 
		p=p->next; 
	} 
	p->next=t; 
} 
/************************************ 
�������ܣ������û������ѧ��������ʾ��ѧ������Ϣ 
************************************/ 
void DesplayInfoBystudentName(void) 
{ 
	STUDENT *p; 
	char studentName[20]; 
	char flag=0; 
	p=headLink->next; 
	printf("������ѧ��������\n"); 
	scanf("%s",studentName); 
	while(p)  
	{ 
		if(strcmp(p->studentName,studentName)==0) 
		{ 
			printf("ѧ��\t����\t�༶\t�ɼ�1\t�ɼ�1\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n"); 
			DesplayOneNode(p); 
			flag=1; 
			break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("�Բ��𣬲���������Ϊ %s ��ѧ��\n",studentName); 
} 
/************************************ 
�������ܣ������û������ѧ����ʾ��ѧ������Ϣ 
************************************/ 
void DesplayInfoBystudentNumber(void) 
{ 
	STUDENT *p; 
	char studentNumber[10]; 
	char flag=0; 
	p=headLink->next; 
	printf("������ѧ��ѧ�ţ�\n"); 
	scanf("%s",studentNumber); 
	while(p) 
	{ 
		if(strcmp(p->studentNumber,studentNumber)==0) 
		{ 
			printf("ѧ��\t����\t�༶\t�ɼ�1\t�ɼ�1\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n"); 
			DesplayOneNode(p); 
			flag=1; 
			break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("�Բ��𣬲�����ѧ��Ϊ %s ��ѧ��\n",studentNumber); 
} 
/************************************ 
�������ܣ����һ��������Ϣ 
************************************/ 
void DesplayOneNode(STUDENT *t) 
{ 
	printf("%s\t",t->studentNumber); 
	printf("%s\t",t->studentName); 
	printf("%s\t",t->className); 
	printf("%.2f\t",t->mark1); 
	printf("%.2f\t",t->mark2); 
	printf("%.2f\t",t->mark3); 
	printf("%.2f\t",t->mark1+t->mark2+t->mark3); 
	printf("%.2f\t\n",(t->mark1+t->mark2+t->mark3)/3); 
} 
/************************************ 
�������ܣ������û������ѧ��ɾ����ѧ�� 
************************************/ 
void DeleteNodeBystudentNumber(void) 
{ 
	char studentNumber[10]; 
	STUDENT *p,*q; 
	char flag=0; 
	printf("������Ҫɾ����ѧ��ѧ�ţ�"); 
	scanf("%s",studentNumber); 
	p=headLink; 
	q=headLink->next; 
	while(q) 
	{ 
		if(strcmp(q->studentNumber,studentNumber)==0) 
		{ 
			p->next=q->next; 
			free(q); 
			flag=1; 
			break; 
		} 
		p=p->next; 
		q=q->next; 
	} 
	if(!flag) 
	{ 
		printf("�����ڸ�ѧ�ŵ�ѧ��\n"); 
		return; 
	} 
	printf("�ɹ�ɾ��\n"); 
} 
/************************************ 
�������ܣ���ʾ����ѧ������Ϣ 
************************************/ 
void OutputInformation(void) 
{ 
	STUDENT *p; 
	p=headLink->next; 
	if(p==NULL) 
	{ 
		printf("����û��ѧ����Ϣ����������ѧ����Ϣ\n\n"); 
		return; 
	} 
	printf("ѧ��\t����\t�༶\t�ɼ�1\t�ɼ�1\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n"); 
	while(p) 
	{ 
		DesplayOneNode(p); 
		p=p->next; 
	} 
} 
/************************************ 
�������ܣ���������������޸ĳɼ� 
************************************/ 
void ChangeMarkByName(void) 
{ 
	STUDENT *p; 
	char studentName[20]; 
	char flag=0; 
	float mark1,mark2,mark3; 
	p=headLink->next; 
	printf("������ѧ��������\n"); 
	scanf("%s",studentName); 
	while(p) 
	{ 
		if(strcmp(p->studentName,studentName)==0) 
		{ 
			printf("�������µĵ�1�ųɼ���\n"); 
			scanf("%f",&mark1); 
			printf("�������µĵ�2�ųɼ���\n"); 
			scanf("%f",&mark2); 
			printf("�������µĵ�3�ųɼ���\n"); 
			scanf("%f",&mark3); 
			p->mark1=mark1; 
			p->mark2=mark2; 
			p->mark3=mark3; 
			flag=1; 
			printf("�޸ĳɹ�\n"); 
			break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("�Բ��𣬲���������Ϊ %s ��ѧ��\n",studentName); 
} 
/************************************ 
�������ܣ����������ѧ���޸ĳɼ� 
************************************/ 
void ChangeMarkByNumber(void) 
{ 
	STUDENT *p; 
	char studentNumber[20]; 
	char flag=0; 
	float mark1,mark2,mark3; 
	p=headLink->next; 
	printf("������ѧ��ѧ�ţ�\n"); 
	scanf("%s",studentNumber); 
	while(p) 
	{ 
		if(strcmp(p->studentNumber,studentNumber)==0) 
		{ 
			printf("�������µĵ�1�ųɼ���\n"); 
			scanf("%f",&mark1); 
			printf("�������µĵ�2�ųɼ���\n"); 
			scanf("%f",&mark2); 
			printf("�������µĵ�3�ųɼ���\n"); 
			scanf("%f",&mark3); 
			p->mark1=mark1; 
			p->mark2=mark2; 
			p->mark3=mark3; 
			flag=1; 
			printf("�޸ĳɹ�\n"); 
		break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("�Բ��𣬲�����ѧ��Ϊ %s ��ѧ��\n",studentNumber); 
} 
/************************************ 
�������ܣ������������ݵ��ļ��� 
************************************/ 
void SaveLinkToFile(void) 
{ 
	STUDENT *p; 
	FILE *fp; 
	p=headLink->next; 
	if(p==NULL) 
	{ 
		printf("����û��ѧ����Ϣ����������ѧ����Ϣ\n\n"); 
		return; 
	} 
	fp=fopen("student.txt","w+"); 
	if(!fp) 
	{ 
		printf("�ļ�������\n"); 
		return; 
	} 
	while(p) 
	{ 
		fprintf(fp,"%s %s %s %f %f %f\n",p->studentNumber,p->studentName,p->className,p->mark1,p->mark2,p->mark3); 
		p=p->next; 
	} 
	fclose(fp); 
} 
/************************************ 
�������ܣ���ʾ����Ͳ�����ѧ���ɼ� 
************************************/ 
void DesplayMarkSegment(void) 
{ 
	STUDENT *p; 
	int count=0; 
	p=headLink->next; 
	printf("60������(������)��ѧ���ɼ����£�\n"); 
	printf("ѧ��\t����\t�༶\t�ɼ�1\t�ɼ�1\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n"); 
	while(p) 
	{ 
		if((6>((int)(p->mark1/10)))||(6>((int)(p->mark2/10)))||(6>((int)(p->mark3/10))))/*ֻҪ��һ�Ʋ��������Ϊ����������*/ 
		{ 
			count++; 
			DesplayOneNode(p); 
		} 
		p=p->next; 
	} 
	printf("�������ѧ��һ����%d��\n",count); 
	p=headLink->next; 
	printf("�ɼ������ѧ���ɼ����£�\n"); 
	printf("ѧ��\t����\t�༶\t�ɼ�1\t�ɼ�1\t�ɼ�3\t�ܳɼ�\tƽ���ɼ�\n\n"); 
	count=0; 
	while(p) 
	{ 
		if((8<=((int)(p->mark1/10)))&&(8<=((int)(p->mark2/10)))&&(8<=((int)(p->mark3/10)))) 
		{ 
			count++; 
			DesplayOneNode(p); 
		} 
		p=p->next; 
	} 
	printf("�ɼ������ѧ��һ����%d��\n",count); 
} 
/************************************ 
�������ܣ����ܳɼ����� 
************************************/ 
void CompositorByTotalMark(void) 
{ 
STUDENT exchange,*r,*p,*q; 
r=headLink->next; 
if(r==NULL) 
{ 
printf("���ڻ�ûѧ����Ϣ,��������ѧ����Ϣ\n"); 
return; 
} 
while(r)/*����whileѭ��ʵ������*/ 
	{ 
	p=r; 
	q=r->next; 
	while(q) 
		{ 
			if((q->mark1+q->mark2+q->mark3)>(p->mark1+p->mark2+p->mark3)) 
			{ 
				strcpy(exchange.studentNumber,q->studentNumber);/*�ȸ���q�����Ϣ��exchange*/ 
				strcpy(exchange.studentName,q->studentName); 
				strcpy(exchange.className,q->className); 
				exchange.mark1=q->mark1; 
				exchange.mark2=q->mark2; 
				exchange.mark3=q->mark3; 
			
				strcpy(q->studentNumber,p->studentNumber);/*�ٸ���p�����Ϣ��q*/ 
				strcpy(q->studentName,p->studentName); 
				strcpy(q->className,p->className); 
				q->mark1=p->mark1; 
				q->mark2=p->mark3; 
				q->mark3=p->mark3; 
				strcpy(p->studentNumber,exchange.studentNumber);/*�����exchange�����Ϣ��p*/ 
				strcpy(p->studentName,exchange.studentName); 
				strcpy(p->className,exchange.className); 
				p->mark1=exchange.mark1; 
				p->mark2=exchange.mark2; 
				p->mark3=exchange.mark3; 
			} 
			q=q->next; 
		} 
		r=r->next; 
	} 
	OutputInformation(); 
} 
