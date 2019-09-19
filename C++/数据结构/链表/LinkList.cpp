#include <iostream>
using namespace std;

#define ok 0
#define error -1

class ListNode
{
	public:
		int data;
		ListNode* next;
};

class LinkList
{
	public:
		int len;
		ListNode* head,tail;
		
		LinkList();
		LinkList(int n);
		~LinkList();
		//void ClearList();
		//void InsFirst(ListNode* h, ListNode* s);
		//void DelFirst(ListNode* h, ListNode& q);
		//void append(ListNode* s);
		int getLen(){ return len; }
		ListNode* LL_index(int i);
		ListNode* LL_PrvIndex(int i);
		int GetElem(int i,int& e);
		int ListIns(int i,int e);
		int ListDel(int i,int &e);
		int swap(int pa,int pb);
		void display();
		int LL_merge(ListNode *La, ListNode *Lb, ListNode* Lc);

		friend int ListLength(LinkList L);
};

LinkList::LinkList()
{
	head = new ListNode;
	head->next = NULL;
}

LinkList::LinkList(int n)
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

int LinkList::ListIns(int i,int e)
{
	int j=0;
	ListNode* p = head;
	
	while(p && j<i-1)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i-1) return error;
	
	ListNode *s = new ListNode;
	s->next = p->next;
	p->next = s;
	s->data = e;
	++len;
	return ok;
}

int LinkList::ListDel(int i,int &e)
{
	int j=0;
	ListNode* q=NULL;
	
	if(!i) return error;	//头结点不可删除 
	
	ListNode* p = LL_PrvIndex(i);	//得到前驱 
	if(!p) return error;
	
	e = p->next->data;
	q = p->next;
	p->next = p->next->next;
	free(q);
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
	
	pc->next = pa ? pa : pb;	//插入剩余段
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
	int n, pos1, pos2, e;
	cin>>n;
	LinkList L1(n);
	cin>>n;
	LinkList L2(n);
	LinkList L3;
	
	L1.LL_merge(L1.head, L2.head, L3.head);
	L3.display();
	
	return 0;
}
