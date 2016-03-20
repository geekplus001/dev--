ADT List
{
	数据对象：D={a[i]|a[i]∈ElemSet,i=1,2,...,n,n>=0}
	数据关系：R1{<a[i-1],a[i]>|a[i-1],a[i]∈D,i=2,...,n}
	基本操作：
	        
	         InitList(&L)
			 	操作结果：构造一个空的线性表L。
			 
			 ListInsert(&L,i,e)
			 	初始条件：线性表L已存在，1<=i<=ListLength(L)+1。
			 	操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1。
			
			 ListDelete(&L,i,&e)
			    初始条件：线性表L已存在且非空，1<=i<=ListLength(L)。
				操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1。
		 	
		 	 LocateElem(L,i,compare())
			    初始条件：线性表L已存在，compare（）是数据元素判定函数。
				操作结果：返回L中第一个与e满足关系compare（）的数据元素的位序。若这样的数据元素不存在，则返回值为0。
			
			 GetElem(L,i,&e)
			    初始条件：线性表L已存在，1<=i<=ListLength(L)。
				操作结果：用e返回L中第i个数据元素的值。 
//				
			 DestroyList(&L)
			    初始条件：线性表L已存在。
				操作结果：销毁线性表L。
			 
			 ClearList(&L)
			    初始条件：线性表L已存在。 
	            操作结果：将L重置为空表。
				
			 ListEmpty(L)
			    初始条件：线性表L已存在。
				操作结果：若L为空表返回TRUE否则返回FALSE。
				
			 ListLength(L)
			    初始条件：线性表L已存在。
				操作结果：翻译L中数据元素个数。
			
				 
			 PriorElem(L,cur_e,&pre_e)
			    初始条件：线性表L已存在。
				操作结果：若cue_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱，否则操作失败，pre_e无定义。
				
			 NextElem(L,cur_e,&next_e)
			    初始条件：线性表L已存在。
				操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后续，否则操作失败，next_e无定义。
				
				
		     ListTraverse(L,visit())
			    初始条件：线性表L已存在。
				操作结果：依次对L的每个数据元素调用函数visit()。一旦visit()失败，则操作失败。
								 
} ADT List 


Status ChangeList(SqList &L)//顺序表的逆置 
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
// 已知顺序线性表La，Lb的元素按非递减排列，归并La，Lb得到新的顺序表Lc也按非递减排列 
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

