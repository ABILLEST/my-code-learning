#include <iostream>
#include <string>
using namespace std;

#define ok 0
#define error -1
#define MAXSIZE 100
#define ElemType int

class StaticList;

typedef class SL_Node
{
	friend class StaticList;
private:
	ElemType data;
	string name;
	int cur;
}SL_Node;

class StaticList
{
private:
	SL_Node space[MAXSIZE];
	int free_node;	//空闲链表表头 
	int len;
public:
	StaticList();
	StaticList(int n);
	~StaticList();
	int LocateElem_SL(ElemType e);
	void InitSpace_SL();
	int Malloc_SL();
	void Free_SL(int k);
	void difference(int &s);
	bool Insert_SL(const ElemType &e, int index=1);
	bool Delete_SL(ElemType &e, int index=1);
	bool Append_SL();
	void display_SL() const;
	int length();
	
	bool Assign(string name,int roomNum,StaticList &free);
	bool Return(int roomNum,StaticList &free);
};

StaticList::StaticList()
{
	space[0].cur = -1;
	free_node = 1;
	for(int i=1; i<MAXSIZE-1; ++i)
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = -1;
}

StaticList::StaticList(int n)
{
	
}

StaticList::~StaticList()
{
	
}

//在静态单链表中查找第一个值为e的元素，找到则返回位置，否则返回0 
int StaticList::LocateElem_SL(ElemType e)
{
	int i = space[0].cur;	//i指示表中第一个节点 
	while(i && space[i].data!=e) i=space[i].cur;
	return i;
}

void StaticList::InitSpace_SL()
{
	for(int i=0; i<MAXSIZE-1; ++i) space[i].cur = i+1;
	space[MAXSIZE-1].cur = 0;
}

//若链表非空，则返回分配的节点下标，否则返回0 
int StaticList::Malloc_SL()
{
	int i=space[0].cur;
	if(space[0].cur) space[0].cur = space[i].cur;
	return i; 
}

//将下标为k的空闲节点回收到备用链表 
void StaticList::Free_SL(int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

void StaticList::display_SL() const
{
	
}

//
void StaticList::difference(int &s)
{
	
}

bool StaticList::Assign(string name, int roomNum, StaticList& free)
{
	
}

bool StaticList::Return(int roomNum,StaticList &free)
{
	
}


int main()
{
	int n, roomNum;
	string name,opr;
	StaticList usedList,freeList;
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>name>>roomNum;
		usedList.Assign(name,roomNum,freeList);
	}
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>opr;
		if("assign"==opr)
		{
			cin>>name>>roomNum;
			usedList.Assign(name,roomNum,freeList);
		}
		else if("return"==opr)
		{
			cin>>roomNum;
			usedList.Return(roomNum,freeList);
		}
		else if("display_free"==opr)
		{
			freeList.display_SL();
		}
		else if("display_used"==opr)
		{
			usedList.display_SL();
		}
		else cout<<"operation name error"<<endl;
	}
	
}


/*
int main()
{
	int n, num, m;
	string opr, name;
	
	cin>>n;
	for(int i=0; i<n; i++)
	{
		cin>>name>>num;
	}
	
	cin>>m;
	for(int i=0; i<m; i++)
	{
		cin>>opr;
		if("assign"==opr)
		{
			
		}
		else if("return"==opr)
		{
			
		}
		else if("display_free"==opr)
		{
			
		}
		else if("display_used"==opr)
		{
			
		}
		else cout<<"operation name error"<<endl;
	}
	
	
	return 0;
}*/
