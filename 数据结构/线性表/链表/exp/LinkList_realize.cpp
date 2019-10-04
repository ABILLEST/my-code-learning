#include <iostream>
#include <stdlib.h>
using namespace std;

#define ok 0
#define error -1

class ListNode
{
	public:
		int data;
		ListNode* next;
		ListNode(){ next = NULL;}
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
		//int getLen();
		ListNode * LL_index(int i);
		int getElem(int i,int& e);
		int ListIns(int i,int e);
		int ListDel(int i,int &e);
		void LL_display();
		
		int swap(int  pa, int pb);
		int swap(ListNode* p, ListNode* q);

		friend int ListLength(LinkList L);
};


LinkList::LinkList()
{
	head = new ListNode;
	len = 0;
}

LinkList::LinkList(int n)
{
	len = n;
	head = new ListNode;
	head->next = NULL;
	ListNode* p=head->next;
	ListNode* q=head;
	for(int i=n; i>0; --i)
	{
		p = new ListNode;
		cin>>p->data;
		q->next = p;
		q = q->next;
	}
}

LinkList::~LinkList()
{
	int j=0;
	ListNode* p=head;
	ListNode* q=head;
	while(p != NULL)
	{
		q = p;
		p = p->next;
		delete(q);
	}
	len = 0;
	head = NULL;
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

int LinkList::getElem(int i,int& e)
{	
	if(!i) return error; 	//头结点不可获取 

	ListNode* p = LL_index(i);
	if(!p) return error;
	e = p->data;
	return ok;
}

int LinkList::ListIns(int i,int e)
{
	int j=0;
	ListNode* p = LL_index(i-1);	//得到前驱 
	if(!p) return error;
	
	ListNode *s = new ListNode;
	s->next = p->next;
	p->next = s;
	s->data = e;
	return ok;
}

int LinkList::ListDel(int i,int &e)
{
	int j=0;
	ListNode* q=NULL;
	
	if(!i) return error;	//头结点不可删除 
	
	ListNode* p = LL_index(i-1);	//得到前驱 
	if(!p) return error;
	
	e = p->next->data;
	q = p->next;
	p->next = p->next->next;
	free(q);
	return ok;
}

void LinkList::LL_display()
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
	if(pa>pb)
	{
		int k;
		k=a;
		a=b;
		b=k;
	}
	if((a>len||a<=0) || (b>len||b<=0))		//位置错误 
	{
		return error;
	}
	else
	{
		ListNode *p,*q,*m,*n,*temp;
		p=LL_index(a);
		q=LL_index(b);
		m=LL_index(a-1);
		n=LL_index(b-1);
		temp=q->next;
		m->next=q;
		q->next=p->next;
		n->next=p;
		p->next=temp;
		return ok;
	}
}

int LinkList::swap(ListNode* p, ListNode* q)
{
	ListNode* tmpP=p;
	ListNode* tmpQ=q;
	int j=0;
	
	if(p==q) return 2;
	
	p->next = q->next;
	q->next->next = tmpP->next->next;

	q->next = tmpP->next;
	tmpP->next->next = tmpQ->next->next;
	
	cout<<p->next->data<<" "<<q->next->data<<endl;
	return ok;
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
    LinkList L(n);
    L.LL_display();
     
    cin>>Pos>>e;
    if(L.ListIns(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.LL_display();
    }
     
     
    cin>>Pos>>e;
    if(L.ListIns(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.LL_display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.LL_display();
    }
     
    cin>>Pos;
    if(L.ListDel(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        L.LL_display();
    }
     
    cin>>Pos;
    if(L.getElem(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        cout<<e<<endl;
    }
 
    cin>>Pos;
    if(L.getElem(Pos,e)==error)
    {
        cout<<"error"<<endl;
    }
    else{
        cout<<e<<endl;
    }
	
}

