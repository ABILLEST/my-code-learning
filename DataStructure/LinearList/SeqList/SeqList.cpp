#include <iostream>
using namespace std;

#define ok 0
#define error -1
#define LEFT_ROL 0
#define RIGHT_ROL 1
#define ElemType int
#define Status int

Status equal(ElemType a, ElemType b)
{
	if(a==b){
		return 1;
	}
	else return 0;
}

class SeqList
{
	private:
		ElemType *list;
		int maxsize;
		int size;
	public:
		SeqList();
		SeqList(int *l, int ms, int s);
		~SeqList();
		Status list_size();
		Status list_insert(int i, ElemType item);
		Status list_del(int i, ElemType &item);
		Status list_get(int i);		//按序号查找元素 
		void list_display();
		Status multiInsert(int i, int n, ElemType item[]);
		Status multiDel(int i, int n);
		Status mergeUp(SeqList& var);
		Status mergeDown(SeqList& var);
		Status Rol(int diretion, int n);
		Status ListEmpty();
		Status LocateElem(ElemType e,ElemType(*compare)(ElemType,ElemType));	//按内容查找元素 
		Status list_union(SeqList& lb);
		
		friend void merge(SeqList* LA, SeqList* LB, SeqList* LC);
};

SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new ElemType[maxsize];
}

SeqList::SeqList(ElemType *l, int ms=1000, int s=0)
{
	list = l;
	maxsize = ms;
	size = s;
}

SeqList::~SeqList()
{
	delete []list;
}

int SeqList::list_size()
{
	return size;
}

int SeqList::list_insert(int i, ElemType item)
{
	if(i<1 || i>size+1) return error;
	if(size >= maxsize) return error;
	
	ElemType *q = &(list[i-1]);
	ElemType *p = NULL;
	
	//插入位置后数据元素后移 
	for(p=&(list[size-1]); p>=q; --p)
	{
		*(p+1) = *p;
	}
	
	*q = item;
	++size;
	
	p = NULL;
	q = NULL;
	free(q);
	free(p);
	return ok;
}

int SeqList::list_get(ElemType i)
{
	if(i<=size && i>=1)
	{
		cout<<*(list+i-1)<<endl;
		return ok;
	}
	else{
		cout<<"error"<<endl;	
	}
}

int SeqList::list_del(int i, ElemType &item)
{
	//指针法 
	if((i<1) || (i>size)) return error;
	
	ElemType *p = &(list[i-1]);		//删除位置
	item = *p;
	
	ElemType *q = list+size-1;	//表尾位置
	
	for(++p; p<=q; ++p) *(p-1) = *p;	//元素前移 
	--size;
	
	return ok;
	
	//数组法 
//	if(i<=size&&(size-1>=0))
//	{
//		for(int j=i-1; j<size; ++j)
//		{
//			list[j] = list[j+1];
//		}
//		size-=1;
//		return ok;
//	}
//	else{
//		return error;
//	}
}

void SeqList::list_display()
{
	for(int i=0;i<size;++i)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int SeqList::multiInsert(int i,int n,int item[])
{
	if(i>0&&i<=size+1&&(size+n<=maxsize))
	{
		for(int j=size+n-1; j>i-1; --j)
		{
			list[j] = list[j-n];
		}
		for(int j=i-1;j<i+n-1;++j)
		{
			list[j] = item[j-i+1];
		}
		size+=n;
		return 0;
	}
	else return -1;
}

int SeqList::multiDel(int i, int n)
{
	if(i<=size&&(size-n>=0)&&(i+n-1<=size))
	{
		for(int j=i-1; j<size-n+1; ++j)
		{
			list[j] = list[j+n];
		}
		size-=n;
		return ok;
	}
	else{
		return error;
	}
}

//先合并后排序，O(n^2) 
int SeqList::mergeUp(SeqList& var)
{
	multiInsert(size,var.size,var.list);
	for(int i=0;i<size;++i)
		for(int j=i+1;j<size;++j)
		{
			if(list[i]>list[j])
			{
				int temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
}

int SeqList::mergeDown(SeqList& var)
{
	multiInsert(size,var.size,var.list);
	for(int i=0;i<size;++i)
		for(int j=i+1;j<size;++j)
		{
			if(list[i]<list[j])
			{
				int temp = list[j];
				list[j] = list[i];
				list[i] = temp;
			}
		}
}

int SeqList::Rol(int direction,int n)
{
	if(direction==LEFT_ROL)
	{
		int *temp = new int[size];
		for(int i=0;i<size-n;++i)
		{
			temp[i]=list[i+n];
		}
		for(int i=size-n;i<size;++i)
		{
			temp[i]=list[i-size+n];
		}
		for(int i=0;i<size;++i)
		{
			list[i]=temp[i];
		}
		delete []temp;
	}
	else if(direction==RIGHT_ROL)
	{
		int *temp = new int[size];
		for(int i=0;i<n;++i)
		{
			temp[i]=list[i+size-n];
		}
		for(int i=n;i<size;++i)
		{
			temp[i]=list[i-n];
		}
		for(int i=0;i<size;++i)
		{
			list[i]=temp[i];
		}
		delete []temp;
	}
	else return error;
}

Status SeqList::ListEmpty()
{
	if(0==size)
	{
		return true;
	}
	else return false;
}

int SeqList::LocateElem(int e,int(*equal)(int,int))
{
	int *p = list;
	int i = 1;
	for(; i<=size && !(*equal)(*p++,e); ++i)
		;
	if(i<=size)	return i;
	else return error;
}

//把所有在lb中但不在list中的数据元素插入到list中 ,O(n^2)
Status SeqList::list_union(SeqList& lb)
{
	for(int i=1; i<=lb.size; ++i)
	{
		int e = lb.list[i-1];
		if(LocateElem(e,equal)==-1)
		{
			list_insert(size+1, e);
		}
	}
	
	return ok;
}

void merge(SeqList* LA, SeqList* LB, SeqList* LC)
{
	int i,j,k,l;
	i=0;j=0;k=0;
	
	while(i<=LA->size && j<=LB->size)
	{
		if(LA->list[i] <= LB->list[j])
		{
			LC->list[k] = LA->list[i];
			i++;k++;
		}
		else
		{
			LC->list[k] = LB->list[j];
			j++;k++;
		}
	}
	while(i<=LA->size)	//表A比表B长时
	{
		LC->list[k] = LA->list[i];
		i++;k++;
	}
	while(i<=LB->size)	//表B比表A长时
	{
		LC->list[k] = LB->list[j];
		j++;k++;
	}
	
	LC->size = LA->size+LB->size;
}


int main()
{
	int s,insLoc,item,delLoc,getLoc,e;
	cin>>s;
	 
	int *l = new int[100];
	for(int i=0;i<s;i++)
	{
		cin>>l[i];
	}
	SeqList sl(l,1000,s);
	
	sl.list_display();
	
	cin>>insLoc>>item;
	if(sl.list_insert(insLoc,item)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>insLoc>>item;
	if(sl.list_insert(insLoc,item)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>delLoc;
	if(sl.list_del(delLoc,e)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>delLoc;
	if(sl.list_del(delLoc,e)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>getLoc;
	sl.list_get(getLoc);
	
	cin>>getLoc;
	sl.list_get(getLoc);
	
	//delete []l1;
	//delete []l2;
}
