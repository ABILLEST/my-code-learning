#include<stdio.h>
#include<iostream>
#include<malloc.h> 
using namespace std;
#define ERROR 0
#define OK 1
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode *next;
} Lnode,*LinkList;
LinkList ListInit()
{
	Lnode* base=(LinkList)malloc(sizeof(LNode));
	base->data=0;
	base->next=NULL;
	return base;
}
int ListInsert(LinkList L,int i,ElemType e)
{
	LNode *p,*s;
	int j=0;
	 p=(LNode *)L;
	while(p&&j<i-1)
	{
		p=p->next;//移动p到i-1位置 
		++j;
	}
	if(!p||j>i-1)
	return ERROR;
	s=(LNode *)malloc(sizeof(LNode));
	s->data=e;
//	cout<<s->data;
	s->next=p->next;//
	p->next=s;//S插在p之后 
	return OK;
}
int ListDelete(LinkList &L,int i,ElemType &e)
{
	LinkList p=L,q;
	int j=0;
	while(p->next&&j<i-1)
	{p=p->next;
	++j;
	}
	if (!(p->next)||j>i-1)
	return ERROR;
	q=p->next;
	p->next=q->next;
	e=q->data;
	free(q);
}
int ListLength(LinkList L)
{
	LinkList p=L;
	int j=0;
	if(!L)
	return ERROR;
	while(p->next)
	{
		p=p->next;
		++j;
	}
	return j;
}
 
 int GetElem(LinkList L, int i, ElemType &e)
 {
 	LNode *p=L;
 	int j=0;
 	while(p->next&&j<i)
 	{
 		p=p->next;
 		++j;
	 }
	 if(!p||j>i)
	 return ERROR;
	 e=p->data;
	 return OK;
 }
 void Display(LinkList L)
 {
 	LNode *p=L;
 	if(!(p->next))
 	{
 		printf("NULL,");
 		return;
	 }
	 else 
	 p=p->next;
	 while(p)
	 {
	 	printf("%d",p->data);
	 	p=p->next;
	 }
 }
 void PowerSet(int i,LinkList A,LinkList &B)
 {
 	int k=0;
 	ElemType e=0;
 	if (i>ListLength(A))//这个条件的意思是到了叶子节点再输出 
 	{
	 	Display(B);
	 	printf("\n");
 	}
 	else
	 {
	 	GetElem(A,i,e);//注意取值从i， i代表了树深度 
	 	k=ListLength(B);
	 	ListInsert(B,k+1,e);
	 	PowerSet(i+1,A,B); //相当于访问左边 
	 	ListDelete(B,k+1,e);//为什么要删除？删除一个刚好代表右孩子 
	 	PowerSet(i+1,A,B);//相当于访问右边 
	 }
 }
  
 int main()
 {
 	LinkList list=ListInit();
 	LinkList list2=ListInit();
 	ListInsert(list,1,1);
 	ListInsert(list,2,2);
 	ListInsert(list,3,3);
 	Display(list);
 	printf("\npoer set is:\n");
 	PowerSet(1,list,list2);//为什么是1开始？ 
 }







