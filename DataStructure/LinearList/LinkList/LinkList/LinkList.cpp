#include <iostream>
using namespace std;

#define ok 0
#define error -1
#define Status int

class ListNode
{
	public:
		Status data;
		ListNode* next;
};

class LinkList
{
	public:
		int len;
		ListNode* head,tail;
		
		LinkList();
		void Init_LL(int n);
		~LinkList();
		int getLen(){ return len; }	//获取链表长 
		Status GetElem(int i,Status& e);	//获取指定节点的数据 
		Status ListIns(int i,Status e);	//在指定位置插入节点 
		Status ListDel(int i,Status &e);	//删除指定位置加点
		void display();
		
		//void ClearList();
		//void InsFirst(ListNode* h, ListNode* s);
		//void DelFirst(ListNode* h, ListNode& q);
		//void append(ListNode* s);
		
		ListNode* LL_index(int i);	//获取第i个的节点 
		ListNode* LL_PrvIndex(int i);//获取第i个节点的前驱 
		Status swap(int pa,int pb);	//交换两个位置的数据 
		Status LL_merge(ListNode *La, ListNode *Lb, ListNode* Lc);	//顺序合并
		Status LL_Difference(ListNode* Lb); 
		Status LL_Reverse();
		void BinAddOne();

		friend int ListLength(LinkList L);
};

LinkList::LinkList()
{
	head = new ListNode;
	head->next = NULL;
}

void LinkList::Init_LL(int n)
{
	len = n;
	head = new ListNode;
	head->next = NULL;
	ListNode *q = head;
	for(int i=n; i>0; --i)
	{
		ListNode* p = new ListNode;
		cin>>p->data;
		q->next = p;
		q = q->next;
	}
	q->next = NULL;
}

LinkList::~LinkList()
{
	int j=0;
	ListNode* p=head;
	ListNode* a=head;
	while(p->next && j<len)
	{
		p = p->next;
		free(a);
		a = p;
		++j;
	}
	head = NULL;
	len = 0;
}

ListNode* LinkList::LL_index(int i)
{
	ListNode* p = head;
	int count=0;

	while(p && count<i)
	{
		p = p->next;
		++count;
	}
	if(!p || count>i) return NULL;
	return p;
}

//获取i位置的前驱p
ListNode* LinkList::LL_PrvIndex(int i)
{
	ListNode* p = head;
	int count=0;

	while(p->next && count<i-1)
	{
		p = p->next;
		++count;
	}
	if(!(p->next) || count>i-1) return NULL;
	return p;
}

int LinkList::GetElem(int i,int& e)
{
	if(i==0) return error;		//不可获取头结点的值
	ListNode* p = LL_index(i);
	if(!p) return error;	//超出界限 
	e = p->data;
	return ok;
}

//在指定位置插入元素
int LinkList::ListIns(int i,int e)
{
	int j=0;
	
	//查找元素
	ListNode* p = LL_PrvIndex(i);

	//插入位置不合法
	if(!p) return error;
	
	//入链
	ListNode *s = new ListNode;
	s->next = p->next;		//先改后指针再改前指针，只需要2条语句 
	p->next = s;

	//连带操作
	s->data = e;
	++len;

	return ok;
}

int LinkList::ListDel(int i,int &e)
{
	int j=0;
	ListNode* q = new ListNode;
	
	if(!i) return error;	//头结点不可删除 
	
	ListNode* p = LL_PrvIndex(i);	//得到前驱 
	if(!p) return error;
	
	e = p->next->data;
	q = p->next;
	p->next = p->next->next;
	delete q;
	--len;
	return ok;
}

void LinkList::display()
{
	ListNode* p = head;
	/*if(!p->next)
	{
		cout<<"空链表"<<endl;
		return;
	}*/
	p = p->next;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	cout<<endl;
}

int LinkList::swap(int pa,int pb)
{
	if((pa>len||pa<=0) || (pb>len||pb<=0))		//位置错误 
	{
		return error;
	}
	else if(pa==pb) return ok;
	else
	{
		ListNode *p,*q,*p_prv,*q_prv,*temp;
		p = LL_index(pa);
		q = LL_index(pb);
		p_prv = LL_index(pa-1);
		q_prv = LL_index(pb-1);
				
		temp=q->next;
		p_prv->next=q;
		q->next=p->next;
		q_prv->next=p;
		p->next=temp;
		return ok;
	}
}

//非原地算法，并未体现链表合并的优势
int LinkList::LL_merge(ListNode *La, ListNode *Lb, ListNode* Lc)	
{
	ListNode *pa = La->next;
	ListNode *pb = Lb->next;
	ListNode *pc = Lc;
	
	while(pa && pb)
	{
		ListNode *newNode = new ListNode;		//新建节点
		newNode->next = NULL;
		
		if(pa->data <= pb->data)		//比较两链表元素大小后依次插入 
		{
			newNode->data = pa->data;
			pa = pa->next;
		}
		else
		{
			newNode->data = pb->data;
			pb = pb->next;
		}
		
		pc->next = newNode;
		pc = pc->next;
	}
	
	//注意下面这条语句，算法结束后B、C两链有重合的部分
	pc->next = pa ? pa : pb;	//插入剩余段
}

//求当前表与表Lb的差，结果保存在当前表中 
Status LinkList::LL_Difference(ListNode* Lb)
{
	ListNode *pre, *p, *q, *r;
	
	//当前表指针 
	pre = head;
	p = head->next;
	
	while(p!=NULL)
	{
		q = Lb->next;
		while(q!=NULL && q->data!=p->data)
		{
			q = q->next;
		}
		if(q!=NULL)		//找到相同值，删除节点 
		{
			r = p;
			pre->next = p->next;
			p = p->next;
			free(r);
		}
		else
		{
			pre = p;
			p = p->next;
		} 
	}
}

//就地逆置
Status LinkList::LL_Reverse()
{
	ListNode* p = head->next;	//保留第一个元素的位置 
	ListNode* q = NULL;			//头结点的next置空获得新链表 
	head->next = NULL;
	while(p!=NULL)
	{
		q = p->next;		//暂存原链 
		
		p->next = head->next;	//头部插入 
		head->next = p;
		
		p = q;
	}
	return ok;
}

//二进制数加一 
void LinkList::BinAddOne()
{
	ListNode *q, *r, *s;
	
	q = head->next;
	r = head;
	
	while(q!=NULL)		//查找最后一个为0的节点 
	{
		if(q->data == 0) r = q;
		q = q->next;
	}
	if(r!=head) r->data = 1;	//置1
	else{
		s = new ListNode;
		s->data = 1;
		//头插
		s->next = head->next;
		head->next = s;
		r = s; 
	}
	r = r->next;
	while(r!=NULL)		//将后面的节点置0
	{
		r->data = 0;
		r = r->next;
	}
}


int ListLength(LinkList L)
{
	ListNode* p;
	p = L.head->next;
	int count=0;
	while(p!=NULL)
	{
		p = p->next;
		++count;
	}
	return count;
}


int main()
{
	int n, Pos, e;
    cin>>n;
    LinkList L;
    L.Init_LL(n);
    L.display();
     
    cin>>Pos>>e;
    if(L.ListIns(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
     
    cin>>Pos>>e;
    if(L.ListIns(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        cout<<e<<endl;
    }
 
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        cout<<e<<endl;
    }
	
	return 0;
}
