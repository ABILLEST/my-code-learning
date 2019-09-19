#include <iostream>
#include <string>
using namespace std;

#define ok 0
#define error -1
#define MAXSIZE 20
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
	
	friend bool Dorm_Init(int n);
	bool Assign(string name,StaticList &free);
	bool Return(int roomNum,StaticList &free);
	void display_used();
};

StaticList::StaticList() : len(0)
{
	for(int i=0; i<MAXSIZE-1; ++i)
	{
		space[i].cur = i+1;	
	}
	
	space[MAXSIZE-1].cur = 0;
}

StaticList::StaticList(int n)
{
	if(n<MAXSIZE)
	{
		len = n;
		space[0].cur = 1;
		for(int i=1; i<len; ++i)
		{
			space[i].cur = i+1;	
		}
		space[len].cur = 0;
	}
	else return;
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
	//设置下一次第一个可用的空闲节点为返回节点的下一个节点
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
	for(int i=1; i<=len; ++i)
	{
		cout<<space[i].data<<"-";
	}
	cout<<endl;	
}

//
void StaticList::difference(int &s)
{
	
}

bool Dorm_Init(StaticList &usedL, StaticList &freeL, int n)
{
	string name;
	int roomNum;
	
	freeL.len = 0;
	space[0].cur = 1;
	for(int j=1; j<=MAXSIZE; ++i)
	{
		space[j].data = 100+j;
		space[j].cur = j+1;	
	}
	space[MAXSIZE].cur = 0;
	
	for(int i=0; i<n; ++i)
	{
		cin>>name>>roomNum;
		for(int j=0; j<MAXSIZE; ++j)
		{
			if(roomNum == freeL.space[j].data)
		}
	}
	
} 

bool StaticList::Assign(string name, StaticList& free)
{
	//不考虑分配不成功 
	int insIndex = this->Malloc_SL();
	int freeIndex = free.Malloc_SL();
	int preIndex;
	
	if(insIndex)
	{
		this->space[insIndex].data = free.space[freeIndex].data;//数据复制 
		for(preIndex=1; preIndex<=insIndex-1; ++preIndex) ;
		space[insIndex].cur = preIndex;
		space[preIndex].cur = insIndex; 
		space[insIndex].name = name;
		++len;
		return true;
	}
	
	return false;
}

bool StaticList::Return(int roomNum,StaticList &free)
{	
	//不考虑交还不成功 
	
}

void StaticList::display_used()
{
	for(int i=1; i<=len; ++i)
	{
		cout<<space[i].name<<"("<<space[i].data<<")";
		if(i!=len) cout<<"-";
	}
	cout<<endl;	
}

//int main()
//{
//	int n, roomNum;
//	string name,opr;
//	cin>>n;
//	StaticList tList(n);
//	tList.display_used();
//	
//	return 0;
//}


int main()
{
	int n, roomNum;
	string name,opr;
	StaticList usedList,freeList;
	
	cin>>n;
	Dorm_Init(usedList,freeList,n);
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>name>>roomNum;
		usedList.Assign_n(name,roomNum,freeList);
	}
	usedList.display_used();
	
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>opr;
		if("assign"==opr)
		{
			cin>>name;
			usedList.Assign(name,freeList);
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
			usedList.display_used();
		}
		else cout<<"operation name error"<<endl;
	}
	
	return 0;	
}



