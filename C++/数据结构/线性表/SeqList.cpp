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
		return 0;
	}
	else if(i==size+1)
	{
		list[i-1] = item;
		size+=1;
	}
	else return -1;
}

int SeqList::list_get(int i)
{
	if(i<=size&&i>0)
	{
		cout<<*(list+i-1);
		return 0;
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
		return 1;
	}
	else{
		return -1;
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

int main()
{
	int s,insLoc,item,delLoc,getLoc;
	cin>>s;
	 
	int *l = new int[1000];
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
	if(sl.list_del(delLoc)==-1)
	{
		cout<<"error"<<endl;
	}
	else{
		sl.list_display();
	}
	
	cin>>delLoc;
	if(sl.list_del(delLoc)==-1)
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
}


