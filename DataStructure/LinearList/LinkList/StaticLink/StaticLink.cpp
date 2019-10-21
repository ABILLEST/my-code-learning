#include <iostream>
#include <string>
using namespace std;

#define ok 0
#define error -1
#define MAXSIZE 100
#define ElemType int
#define Status int

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
	int used_head, free_head;	//空闲链表表头 
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
	Status Insert_SL(const ElemType &e, int index=1);
	bool Delete_SL(ElemType &e, int index=1);
	Status Append_SL();
	void display_SL() const;
	int length();
	
	bool Assign(string name);
};

StaticList::StaticList()
{
	space[0].cur = -1;
	free_head = 1;
	for(int i=1; i<MAXSIZE-1; ++i)
		space[i].cur = i+1;
	space[MAXSIZE-1].cur = -1;
}

StaticList::StaticList(int n)
{
	if(n<MAXSIZE)
	{
		len = n;
		space[0].cur = 1;
		for(int i=1; i<=len; ++i)
		{
			cin>>space[i].data;
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
	if(space[0].cur) space[0].cur = space[i].cur;
	return i; 
}

//将下标为k的空闲节点回收到备用链表 
void StaticList::Free_SL(int k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

//(A-B)∪(B-A) ,当前表为表A，参数表B
void StaticList::difference(int &S)
{
	int nA,nB,i,k;
	
	InitSpace_SL();		//初始化备用空间 
	S = Malloc_SL();	//生成S的头结点 
	int r = S;			//r指向S的当前最后节点 
	
	cin>>nA>>nB;		//输入A和B的元素个数 
	for(int j=1; j<=nA; ++j)	//建立集合A的链表 
	{
		i = Malloc_SL();		//分配节点 
		cin>>space[i].data;	 
		space[r].cur = i;		//插入到表尾 
		++len;
		r = i;
	}
	space[r].cur = 0;	//尾节点的指针为空
	
	for(int j=1; j<nB; ++j)//输入B的元素，若不在当前表中则插入，否则删除 
	{
		int b;
		cin>>b;
		
		int p = S;
		k = space[S].cur;	//k指向集合A中的首节点 
		while(k!=space[r].cur && space[k].data!=b)	//在当前表中查找是否存在该元素
		{
			p = k;
			k = space[k].cur;
		}
		if(k==space[r].cur)		//集合A中不存在该元素,插入在r节点之后 
		{
			i = Malloc_SL();
			space[i].data = b;
			space[i].cur = space[r].cur;
			space[r].cur = i;
			++len;
		}
		else	//已存在，删除 
		{
			space[p].cur = space[k].cur;
			Free_SL(k);
			if(r == k) r = p;	//若删除的是r节点，则需修改尾指针 
		}
	}
}

Status StaticList::Insert_SL(const int &e, int index)
{
	return ok;
}

Status StaticList::Append_SL()
{
	return ok;
}

void StaticList::display_SL() const
{
	for(int i=used_head; space[i].cur!=0; i=space[i].cur)
	{
		cout<<space[i].data<<" ";
	}
	cout<<endl;	
}


int main()
{
	int n,s;
	
	
	//cin>>n;
	StaticList LA;
	//cin>>n;
	//StaticList LB(n);
	
	//cout<<"LA: "; LA.display_SL();
	//cout<<"LB: "; LB.display_SL();
	
	LA.difference(s);
	LA.display_SL();
	return 0;
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
