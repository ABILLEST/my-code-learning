#include <iostream>
using namespace std;

#define ok 0
#define error -1
#define Elemtype int
#define Status int

class PolyList;

//节点数据结构定义 
class PolyNode
{
public:
	int coef;
	int exp;
	PolyNode *next;
	friend class PolyList;
};

class PolyList
{
public:
	PolyNode *head,*tail;
	PolyList();
	~PolyList();
	Status CreatePoly();
	Status AddPoly(const PolyNode *polyb);
	
};


PolyList::PolyList()
{
	
}

Status PolyList::CreatePoly()
{
	PolyNode *s;
	int c,e;
	
	head = new PolyNode;
	tail = head;
	
	cin>>c>>e;
	while(c != 0)
	{
		s = new PolyNode;
		s->coef = c;
		s->exp = e;
		
		tail->next = s;		//表尾插入 
		tail = s;
		
		cin>>c>>e;
	}
	
	tail->next = NULL;	//表尾置空 
	
}

//将两个多项式相加，结果存在当前多项式中 
Status PolyList::AddPoly(const PolyNode *polyb)
{
	PolyNode *q, *p, *temp;
	int sum=0;
	
	p = this->head->next;
	q = polyb->next;
	tail = head;
	
	while(p!=NULL && q!=NULL)
	{
		if(p->exp < q->exp)
		{
			tail->next = p;
			tail = p;
			p = p->next;
		}
		else if(p->exp > q->exp)
		{
			tail->next = q;
			tail = q;
			q = q->next;
		}
		else{
			sum = p->coef+q->coef;
			if(sum){
				p->coef = sum;
				
				tail->next = p;
				tail = p;
				p = p->next;
				
				temp = q;
				q = q->next;
				free(temp);
			}
			else{
				temp = p;
				p = p->next;
				free(temp);
				
				temp = q;
				q = q->next;
				free(temp);
			}
		}
	}
	
	if(p!=NULL)	//多项式A中还有剩余，则将剩余节点加入到和多项式中 
	{
		tail->next = p;
	}
	else tail->next = q;//否则将B剩余节点加入 
	
	return ok;
}


int main()
{
	
}

