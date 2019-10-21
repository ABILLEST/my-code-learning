#include <iostream>
using namespace std;

#define ok 0
#define error -1
#define Elemtype int
#define Status int

//双向循环链表节点定义
//typedef struct DuLNode
//{
//	Elemtype data;
//	struct DuLNode *prior, *next;
//}DuLNode, *DuLinkList;

class DuLinkList;

class DuLNode
{
public:
	Elemtype data;
	DuLNode *prior, *next;
	friend class DuLinkList;
};

class DuLinkList
{
public:
	DuLNode *head;
	DuLinkList();
	~DuLinkList();
	DuLNode* GetElemP_DuL(int i); 
	Status Insert_DuL(int i, Elemtype e);	//前插
	Status Delete_DuL(int i, Elemtype &e);	//删除 
};


DuLinkList::DuLinkList()
{
	
}

DuLinkList::~DuLinkList()
{
	
}

//获取第i个位置的地址 
DuLNode* DuLinkList::GetElemP_DuL(int i)
{
	DuLNode* p = head;
	int count=0;

	while(p->next && count<i-1)
	{
		p = p->next;
		++count;
	}
	if(!(p->next) || count>i-1) return NULL;
	return p;
}

Status DuLinkList::Insert_DuL(int i, Elemtype e)
{
	DuLNode *s, *p;
	
	if(!(p = GetElemP_DuL(i))) return error;	//插入位置不合法
	s = new DuLNode;
	if(!s) return error;
	
	s->data = e;
	//修改挂链 
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	
	return ok;
}

Status DuLinkList::Delete_DuL(int i, Elemtype &e)
{
	DuLNode *p;
	
	if(!(p = GetElemP_DuL(i))) return error;
	
	e = p->data;
	//修改挂链
	p->prior->next = p->next;
	p->next->prior = p->prior;
	
	free(p);
	return ok; 
}

int main()
{

}
