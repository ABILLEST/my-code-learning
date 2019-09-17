#include <iostream>
using namespace std;

#define ok 0
#define error -1

class Node
{
	public:
		int data;
		Node* next;
};

class LinkList
{
	private:
		int len;
		Node* head,tail;
	public:
		LinkList();
		LinkList(int n);
		~LinkList();
		//void ClearList();
		//void InsFirst(Node* h, Node* s);
		//void DelFirst(Node* h, Node& q);
		//void append(Node* s);
		//int getLen();
		int getElem(int i,int& e);
		int ListIns(int i,int e);
		int ListDel(int i,int &e);
		void display();

		friend int ListLength(LinkList L);
};

LinkList::LinkList()
{
	head = new Node;
	head->next = NULL;
}

LinkList::LinkList(int n)
{
	len = n;
	head = new Node;
	head->next = NULL;
	for(int i=n; i>0; --i)
	{
		Node* p = new Node;
		cin>>p->data;
		p->next = head->next;
		head->next = p;
	}
}

LinkList::~LinkList()
{
	int j=0;
	Node* p=head;
	Node* a=head;
	while(p->next && j<len)
	{
		p = p->next;
		free(a);
		a = p;
		++j;
	}
}

int LinkList::getElem(int i,int& e)
{
	Node* p = head->next;
	int count = 1;
	while(p && count<i)
	{
		p = p->next;
		++count;
	}
	if(!p || count>i) return error;
	e = p->data;
	return ok;
}

int LinkList::ListIns(int i,int e)
{
	int j=0;
	Node* p = head;
	while(p && j<i-1)
	{
		p = p->next;
		++j;
	}
	if(!p || j>i-1) return error;
	Node *s = new Node;
	s->next = p->next;
	p->next = s;
	s->data = e;
	return ok;
}

int LinkList::ListDel(int i,int &e)
{
	int j=0;
	Node* p=head;
	while(p->next && j<i-1)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j>i-1) return error;
	e = p->next->data;
	p->next = p->next->next;
	free(p->next->next);
	return ok;
}

void LinkList::display()
{
	Node* p = head;
	int j=0;
	if(!p->next)
	{
		cout<<"¿ÕÁ´±í"<<endl;
		return;
	}
	p = p->next;
	while(p)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
	//cout<<endl;
}


int ListLength(LinkList L)
{
	Node* p;
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
	int n;
	cin>>n;
	LinkList L(n);
	L.display();
}
