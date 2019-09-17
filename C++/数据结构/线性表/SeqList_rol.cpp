#include <iostream>
using namespace std;

#define ok 0
#define error -1
#define LEFT_ROL 0
#define RIGHT_ROL 1

class SeqList
{
	private:
		int *list;
		int maxsize;
		int size;
	public:
		SeqList();
		SeqList(int *l, int ms, int s);
		~SeqList();
		int list_size();
		int list_insert(int i, int item);
		int list_del(int i);
		int list_get(int i);
		void list_display();
		int multiInsert(int i, int n, int item[]);
		int multiDel(int i, int n);
		int mergeUp(SeqList& var);
		int mergeDown(SeqList& var);
		int Rol(int diretion, int n);
		bool ListEmpty();
		int LocateElem(int e,int(*compare)(int,int));
};

SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

SeqList::SeqList(int *l, int ms=1000, int s=0)
{
	//list = l;
	list = new int[maxsize];
	maxsize = ms;
	size = s;
	for(int i=0; i<size; i++)
	{
		list[i] = l[i];
	}
}

SeqList::~SeqList()
{
	delete []list;
}

int SeqList::list_size()
{
	return size;
}

int SeqList::list_insert(int i, int item)
{
	if(1<=i && i<=size && (size+1<=maxsize))
	{
		for(int j=size; j>i-1; j--)
		{
			list[j] = list[j-1];
		}
		list[i-1] = item;
		size += 1;
		return ok;
	}
	else if(i==size+1)
	{
		list[i-1] = item;
		size+=1;
	}
	else return error;
}

int SeqList::list_get(int i)
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

int SeqList::list_del(int i)
{
	if(i<=size&&(size-1>=0))
	{
		for(int j=i-1; j<size; j++)
		{
			list[j] = list[j+1];
		}
		size-=1;
		return ok;
	}
	else{
		return error;
	}
}

void SeqList::list_display()
{
	for(int i=0;i<size;i++)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int SeqList::multiInsert(int i,int n,int item[])
{
	if(i>0&&i<=size&&(size+n<=maxsize))
	{
		for(int j=size+n-1; j>i-1; j--)
		{
			list[j] = list[j-n];
		}
		for(int j=i-1;j<i+n-1;j++)
		{
			list[j] = item[j-i+1];
		}
		size+=n;
		return 0;
	}
	else if(i==size+1&&(size+n<=maxsize))
	{
		for(int j=i-1;j<i+n-1;j++)
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
		for(int j=i-1; j<size-n+1; j++)
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

int SeqList::mergeUp(SeqList& var)
{
	multiInsert(size,var.size,var.list);
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size;j++)
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
	for(int i=0;i<size;i++)
		for(int j=i+1;j<size;j++)
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
		for(int i=0;i<size-n;i++)
		{
			temp[i]=list[i+n];
		}
		for(int i=size-n;i<size;i++)
		{
			temp[i]=list[i-size+n];
		}
		for(int i=0;i<size;i++)
		{
			list[i]=temp[i];
		}
		delete []temp;
	}
	else if(direction==RIGHT_ROL)
	{
		int *temp = new int[size];
		for(int i=0;i<n;i++)
		{
			temp[i]=list[i+size-n];
		}
		for(int i=n;i<size;i++)
		{
			temp[i]=list[i-n];
		}
		for(int i=0;i<size;i++)
		{
			list[i]=temp[i];
		}
		delete []temp;
	}
	else return error;
}

bool SeqList::ListEmpty()
{
	if(0==size)
	{
		return true;
	}
	else return false;
}

int SeqList::LocateElem(int e,int(*compare)(int,int))
{
	int *p = list;
	int i = 1;
	for(; !(*compare)(*p++,e); ++i)
		;
	if(i<=size)	return i;
	else return error;
}


int main()
{
	int s,insLoc,delLoc,getLoc,n,d;
	
	cin>>s;
	int *l = new int[1000];
	for(int i=0;i<s;i++)
	{
		cin>>l[i];
	}
	SeqList sl(l,1000,s);
	
	sl.list_display();
	
	cin>>d>>n;
	sl.Rol(d,n);
	sl.list_display();
	
	cin>>d>>n;
	sl.Rol(d,n);
	sl.list_display();
	
	delete []l;
}
