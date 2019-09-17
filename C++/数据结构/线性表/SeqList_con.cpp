#include <iostream>
using namespace std;

#define ok 0
#define error -1

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
		int multiinsert(int i, int n, int item[]);
		int multidel(int i, int n);
		int con(SeqList& var);
};

SeqList::SeqList()
{
	maxsize = 1000;
	size = 0;
	list = new int[maxsize];
}

SeqList::SeqList(int *l, int ms=1000, int s=0)
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

int SeqList::list_insert(int i, int item)
{
	if(i>0&&i<=size&&(size+1<=maxsize))
	{
		for(int j=size; j>i-1; j--)
		{
			list[j] = list[j-1];
		}
		list[i-1] = item;
		size+=1;
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
	if(i<=size&&i>0)
	{
		cout<<*(list+i-1);
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
	cout<<list_size()<<" ";
	for(int i=0;i<size;i++)
	{
		cout<<list[i]<<" ";
	}
	cout<<endl;
}

int SeqList::multiinsert(int i,int n,int item[])
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

int SeqList::multidel(int i, int n)
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

int SeqList::con(SeqList& var)
{
	multiinsert(size,var.size,var.list);
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


int main()
{
	int s,insLoc,delLoc,getLoc,n;
	
	cin>>s;
	int *l1 = new int[1000];
	for(int i=0;i<s;i++)
	{
		cin>>l1[i];
	}
	SeqList sl1(l1,1000,s);
	
	cin>>s;
	int *l2 = new int[1000];
	for(int i=0;i<s;i++)
	{
		cin>>l2[i];
	}
	SeqList sl2(l2,1000,s);
	
	sl1.con(sl2);
	sl1.list_display();
	
}
