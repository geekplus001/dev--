ADT List
{
	���ݶ���D={a[i]|a[i]��ElemSet,i=1,2,...,n,n>=0}
	���ݹ�ϵ��R1{<a[i-1],a[i]>|a[i-1],a[i]��D,i=2,...,n}
	����������
	        
	         InitList(&L)
			 	�������������һ���յ����Ա�L��
			 
			 ListInsert(&L,i,e)
			 	��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)+1��
			 	�����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1��
			
			 ListDelete(&L,i,&e)
			    ��ʼ���������Ա�L�Ѵ����ҷǿգ�1<=i<=ListLength(L)��
				���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1��
		 	
		 	 LocateElem(L,i,compare())
			    ��ʼ���������Ա�L�Ѵ��ڣ�compare����������Ԫ���ж�������
				�������������L�е�һ����e�����ϵcompare����������Ԫ�ص�λ��������������Ԫ�ز����ڣ��򷵻�ֵΪ0��
			
			 GetElem(L,i,&e)
			    ��ʼ���������Ա�L�Ѵ��ڣ�1<=i<=ListLength(L)��
				�����������e����L�е�i������Ԫ�ص�ֵ�� 
//				
			 DestroyList(&L)
			    ��ʼ���������Ա�L�Ѵ��ڡ�
				����������������Ա�L��
			 
			 ClearList(&L)
			    ��ʼ���������Ա�L�Ѵ��ڡ� 
	            �����������L����Ϊ�ձ�
				
			 ListEmpty(L)
			    ��ʼ���������Ա�L�Ѵ��ڡ�
				�����������LΪ�ձ���TRUE���򷵻�FALSE��
				
			 ListLength(L)
			    ��ʼ���������Ա�L�Ѵ��ڡ�
				�������������L������Ԫ�ظ�����
			
				 
			 PriorElem(L,cur_e,&pre_e)
			    ��ʼ���������Ա�L�Ѵ��ڡ�
				�����������cue_e��L������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ�����������ʧ�ܣ�pre_e�޶��塣
				
			 NextElem(L,cur_e,&next_e)
			    ��ʼ���������Ա�L�Ѵ��ڡ�
				�����������cur_e��L������Ԫ�أ��Ҳ������һ��������next_e�������ĺ������������ʧ�ܣ�next_e�޶��塣
				
				
		     ListTraverse(L,visit())
			    ��ʼ���������Ա�L�Ѵ��ڡ�
				������������ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ�ܡ�
								 
} ADT List 


Status ChangeList(SqList &L)//˳�������� 
{
	ElemType i,j,temp;
	i=0;
	j=L.length-1;
	while(j-i>0)
	{
		temp=a[j];
		a[j]=a[i];
		a[i]=temp;
		j--;
		i++;
	} 
	return OK;
}//ChangeList

void MergeList-Sq(SqList La,SqList Lb,SqList &Lc)
// ��֪˳�����Ա�La��Lb��Ԫ�ذ��ǵݼ����У��鲢La��Lb�õ��µ�˳���LcҲ���ǵݼ����� 
{
	pa=La.elem;
	pb=Lb.elem;
	Lc.listsize=Lc.length=La.length+Lb.length;
	pc=Lc.elem=(ElemType*)malloc(Lc.listsize*sizeof(ElemType));
	if(!Lc.elem)
	exit(OVERFLOW);
	pa_last=La.elem+La.length-1;
	pb_last=Lb.elem+Lb.length-1;
	while(pa<=pa_last&&pb<=pb_last)
	{
		if(* pa<=* pb)
		*pc++=*pa++;
		else
		*pc++=*pb++;
		 
	} 
	while(pa<=pa_last)
	*pc++=*pa++;
	while(pb<=pb_last)
	*pc++=*pb++; 
} //MergeList_Sq

