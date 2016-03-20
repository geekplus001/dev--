#include<stdio.h> 
#include<conio.h> 
#include<malloc.h> 
#include<string.h> 

typedef struct 

{ 
	char studentNumber[10];/*学生学号*/ 
	char studentName[20];/*学生姓名*/ 
	char className[20];/*班级名称*/ 
	float mark1;/*第1门成绩*/ 
	float mark2;/*第2门成绩*/ 
	float mark3;/*第3门成绩*/ 
	struct STUDENT *next; 
}STUDENT; 
STUDENT *headLink;/*链表表头指针*/ 

/*以下是函数声明*/ 

void ReadInfoFormFile(void);      //从文件中读学生信息到链表中
void DesplayMenu(void); 	      //显示菜单，根据用户的输入 完成相应的功能  
void CreateHeadLink(void);        //建立链表表头 
STUDENT *MallocNode(void);        //申请一个新结点，并将其初始化 
void GetInformation(STUDENT *t);  //要求用户输入信息到新结点中
void OutputInformation(void);     //显示所有学生的信息
void DesplayInfoBystudentName(void);//根据用户输入的名字显示该学生的信息
void DesplayInfoBystudentNumber(void);//根据用户输入的学号显示该学生的信息
void DesplayOneNode(STUDENT *t);  //输出一个结点的信息 
void InsertOneNode(STUDENT *t);   //将新结点加到链表中
void DeleteNodeBystudentNumber(void);//根据用户输入的学号删除该学生
void ChangeMarkByName(void);     //根据用户输入的姓名修改学生成绩
void ChangeMarkByNumber(void);   //根据用户输入的学号修改学生成绩
void SaveLinkToFile(void);       //保存数据后再退出
void DesplayMarkSegment(void);  //显示各分数段的学生成绩
void CompositorByTotalMark(void);//按总成绩排序 
int choose;/*用于接受用户的选择*/ 

/*主函数*/ 

main() 
{ 
	CreateHeadLink(); //函数功能：建立链表表头 
	ReadInfoFormFile(); //函数功能：从文件中读学生信息到链表中   
	DesplayMenu();//函数功能：显示菜单，根据用户的输入 完成相应的功能  
} 
/************************************ 
函数功能：从文件中读学生信息到链表中 
************************************/ 
void ReadInfoFormFile(void) 
{ 
	FILE *fp; 
	STUDENT *p; 
	fp=fopen("student.txt","r"); 
	if(!fp) 
	{ 
		printf("文件不存在\n"); 
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
函数功能：显示菜单，根据用户的输入 
完成相应的功能 
************************************/ 
void DesplayMenu(void) 
{ 
	STUDENT *p; 
	printf("-------请选择相应功能------------\n\n"); 
	printf("| 1 显示所有学生的信息 |\n"); 
	printf("| 2 按姓名查询 |\n"); 
	printf("| 3 按学号查询 |\n"); 
	printf("| 4 增加学生 |\n"); 
	printf("| 5 删除学生 |\n"); 
	printf("| 6 按姓名修改学生成绩 |\n"); 
	printf("| 7 按学号修改学生成绩 |\n"); 
	printf("| 8 保存所有学生信息 |\n"); 
	printf("| 9 显示优秀和不及格学生成绩 |\n"); 
	printf("| 10 排序结果并输出绩 |\n"); 
	printf("| 11 退出 |\n\n"); 
	scanf("%d",&choose);/*取得用户的选择*/ 
	switch(choose) 
	{ 
		case 1: 
		OutputInformation();/*显示所有学生的信息*/ 
		break; 
		case 2: 
		DesplayInfoBystudentName(); 
		break; 
		case 3: 
		DesplayInfoBystudentNumber();/*根据用户输入的学号显示该学生的信息*/ 
		break; 
		case 4: 
		p=MallocNode();/*先申请一个新结点*/ 
		GetInformation(p);/*要求用户输入信息到新结点中*/ 
		InsertOneNode(p);/*将新结点加到链表中*/ 
		break; 
		case 5: 
		DeleteNodeBystudentNumber();/*根据用户输入的学号删除该学生*/ 
		break; 
		case 6: 
		ChangeMarkByName();/*根据用户输入的姓名修改学生成绩*/ 
		break; 
		case 7: 
		ChangeMarkByNumber();/*根据用户输入的学号修改学生成绩*/ 
		break; 
		case 8: 
		SaveLinkToFile();/*保存数据*/ 
		break; 
		case 9: 
		DesplayMarkSegment();/*显示各分数段的学生成绩*/ 
		break; 
		case 10: 
		CompositorByTotalMark(); 
		break; 
		case 11: 
		SaveLinkToFile();/*保存数据后再退出*/ 
		free(headLink); 
		exit(1); 
		break; 
		default: 
		break; 
	} 
	DesplayMenu();/*递归调用*/ 
} 
/************************************ 
函数功能：建立链表表头 
************************************/ 
void CreateHeadLink(void) 
{ 
	STUDENT *p; 
	p=(STUDENT*)malloc(sizeof(STUDENT)); 
	headLink=p; 
	p->next=NULL; 
} 
/************************************ 
函数功能：申请一个新结点，并将其初始化 
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
函数功能：取得用户输入的学生信息 
************************************/ 
void GetInformation(STUDENT *t) 
{ 
	printf("请输入学生学号：\n"); 
	scanf("%s",t->studentNumber); 
	printf("请输入学生姓名：\n"); 
	scanf("%s",t->studentName); 
	printf("请输入该生所在班级：\n"); 
	scanf("%s",t->className); 
	printf("请输入第1门成绩：\n"); 
	scanf("%f",&(t->mark1)); 
	printf("请输入第2门成绩：\n"); 
	scanf("%f",&(t->mark2)); 
	printf("请输入第3门成绩：\n"); 
	scanf("%f",&(t->mark3)); 
} 
/************************************ 
函数功能：在链表的结尾处增加一个结点 
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
函数功能：根据用户输入的学生姓名显示该学生的信息 
************************************/ 
void DesplayInfoBystudentName(void) 
{ 
	STUDENT *p; 
	char studentName[20]; 
	char flag=0; 
	p=headLink->next; 
	printf("请输入学生姓名：\n"); 
	scanf("%s",studentName); 
	while(p)  
	{ 
		if(strcmp(p->studentName,studentName)==0) 
		{ 
			printf("学号\t姓名\t班级\t成绩1\t成绩1\t成绩3\t总成绩\t平均成绩\n\n"); 
			DesplayOneNode(p); 
			flag=1; 
			break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("对不起，不存在姓名为 %s 的学生\n",studentName); 
} 
/************************************ 
函数功能：根据用户输入的学号显示该学生的信息 
************************************/ 
void DesplayInfoBystudentNumber(void) 
{ 
	STUDENT *p; 
	char studentNumber[10]; 
	char flag=0; 
	p=headLink->next; 
	printf("请输入学生学号：\n"); 
	scanf("%s",studentNumber); 
	while(p) 
	{ 
		if(strcmp(p->studentNumber,studentNumber)==0) 
		{ 
			printf("学号\t姓名\t班级\t成绩1\t成绩1\t成绩3\t总成绩\t平均成绩\n\n"); 
			DesplayOneNode(p); 
			flag=1; 
			break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("对不起，不存在学号为 %s 的学生\n",studentNumber); 
} 
/************************************ 
函数功能：输出一个结点的信息 
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
函数功能：根据用户输入的学号删除该学生 
************************************/ 
void DeleteNodeBystudentNumber(void) 
{ 
	char studentNumber[10]; 
	STUDENT *p,*q; 
	char flag=0; 
	printf("请输入要删除的学生学号："); 
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
		printf("不存在该学号的学生\n"); 
		return; 
	} 
	printf("成功删除\n"); 
} 
/************************************ 
函数功能：显示所有学生的信息 
************************************/ 
void OutputInformation(void) 
{ 
	STUDENT *p; 
	p=headLink->next; 
	if(p==NULL) 
	{ 
		printf("现在没有学生信息，请先输入学生信息\n\n"); 
		return; 
	} 
	printf("学号\t姓名\t班级\t成绩1\t成绩1\t成绩3\t总成绩\t平均成绩\n\n"); 
	while(p) 
	{ 
		DesplayOneNode(p); 
		p=p->next; 
	} 
} 
/************************************ 
函数功能：根据输入的姓名修改成绩 
************************************/ 
void ChangeMarkByName(void) 
{ 
	STUDENT *p; 
	char studentName[20]; 
	char flag=0; 
	float mark1,mark2,mark3; 
	p=headLink->next; 
	printf("请输入学生姓名：\n"); 
	scanf("%s",studentName); 
	while(p) 
	{ 
		if(strcmp(p->studentName,studentName)==0) 
		{ 
			printf("请输入新的第1门成绩：\n"); 
			scanf("%f",&mark1); 
			printf("请输入新的第2门成绩：\n"); 
			scanf("%f",&mark2); 
			printf("请输入新的第3门成绩：\n"); 
			scanf("%f",&mark3); 
			p->mark1=mark1; 
			p->mark2=mark2; 
			p->mark3=mark3; 
			flag=1; 
			printf("修改成功\n"); 
			break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("对不起，不存在姓名为 %s 的学生\n",studentName); 
} 
/************************************ 
函数功能：根据输入的学号修改成绩 
************************************/ 
void ChangeMarkByNumber(void) 
{ 
	STUDENT *p; 
	char studentNumber[20]; 
	char flag=0; 
	float mark1,mark2,mark3; 
	p=headLink->next; 
	printf("请输入学生学号：\n"); 
	scanf("%s",studentNumber); 
	while(p) 
	{ 
		if(strcmp(p->studentNumber,studentNumber)==0) 
		{ 
			printf("请输入新的第1门成绩：\n"); 
			scanf("%f",&mark1); 
			printf("请输入新的第2门成绩：\n"); 
			scanf("%f",&mark2); 
			printf("请输入新的第3门成绩：\n"); 
			scanf("%f",&mark3); 
			p->mark1=mark1; 
			p->mark2=mark2; 
			p->mark3=mark3; 
			flag=1; 
			printf("修改成功\n"); 
		break; 
		} 
		p=p->next; 
	} 
	if(!flag) 
	printf("对不起，不存在学号为 %s 的学生\n",studentNumber); 
} 
/************************************ 
函数功能：保存链表数据到文件中 
************************************/ 
void SaveLinkToFile(void) 
{ 
	STUDENT *p; 
	FILE *fp; 
	p=headLink->next; 
	if(p==NULL) 
	{ 
		printf("现在没有学生信息，请先输入学生信息\n\n"); 
		return; 
	} 
	fp=fopen("student.txt","w+"); 
	if(!fp) 
	{ 
		printf("文件不存在\n"); 
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
函数功能：显示优秀和不及格学生成绩 
************************************/ 
void DesplayMarkSegment(void) 
{ 
	STUDENT *p; 
	int count=0; 
	p=headLink->next; 
	printf("60分以下(不及格)的学生成绩如下：\n"); 
	printf("学号\t姓名\t班级\t成绩1\t成绩1\t成绩3\t总成绩\t平均成绩\n\n"); 
	while(p) 
	{ 
		if((6>((int)(p->mark1/10)))||(6>((int)(p->mark2/10)))||(6>((int)(p->mark3/10))))/*只要有一科不及格就认为该生不及格*/ 
		{ 
			count++; 
			DesplayOneNode(p); 
		} 
		p=p->next; 
	} 
	printf("不及格的学生一共有%d人\n",count); 
	p=headLink->next; 
	printf("成绩优秀的学生成绩如下：\n"); 
	printf("学号\t姓名\t班级\t成绩1\t成绩1\t成绩3\t总成绩\t平均成绩\n\n"); 
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
	printf("成绩优秀的学生一共有%d人\n",count); 
} 
/************************************ 
函数功能：按总成绩排序 
************************************/ 
void CompositorByTotalMark(void) 
{ 
STUDENT exchange,*r,*p,*q; 
r=headLink->next; 
if(r==NULL) 
{ 
printf("现在还没学生信息,请先输入学生信息\n"); 
return; 
} 
while(r)/*两层while循环实现排序*/ 
	{ 
	p=r; 
	q=r->next; 
	while(q) 
		{ 
			if((q->mark1+q->mark2+q->mark3)>(p->mark1+p->mark2+p->mark3)) 
			{ 
				strcpy(exchange.studentNumber,q->studentNumber);/*先复制q结点信息到exchange*/ 
				strcpy(exchange.studentName,q->studentName); 
				strcpy(exchange.className,q->className); 
				exchange.mark1=q->mark1; 
				exchange.mark2=q->mark2; 
				exchange.mark3=q->mark3; 
			
				strcpy(q->studentNumber,p->studentNumber);/*再复制p结点信息到q*/ 
				strcpy(q->studentName,p->studentName); 
				strcpy(q->className,p->className); 
				q->mark1=p->mark1; 
				q->mark2=p->mark3; 
				q->mark3=p->mark3; 
				strcpy(p->studentNumber,exchange.studentNumber);/*最后复制exchange结点信息到p*/ 
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
