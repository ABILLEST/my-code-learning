#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ok 0
#define error -1
#define Elemtype int
#define Status int
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

class LinkStack;

class Node
{
public:
	Elemtype data;
	Node *next;
	friend class LinkStack;
};

class LinkStack
{
	Node *top;
	int stacksize;		//ÒÑ·ÖÅäµÄ´æ´¢¿Õ¼ä 
public:
	LinkStack();
	~LinkStack();
	Status InitStack();
	Status ClearStack();
	bool isStackEmpty();
	//ÅÐÂú 
	int StackLen();
	Status GetTop(Elemtype &e);		//¶ÁÕ»¶¥ 
	Status Push(Elemtype e);
	Status Pop(Elemtype &e);
	
};


LinkStack::LinkStack()
{
	//³õÊ¼»¯Âß¼­ÔÚInitStackº¯ÊýÄÚ 
}

LinkStack::~LinkStack()
{
	
}

Status LinkStack::InitStack()
{
	top = new Node;
	if(!top) return error;
	top->next = NULL;	//´´½¨¿ÕÕ»
	return ok;
} 

bool LinkStack::isStackEmpty()
{
	return (top->next ? true : false);
}

int LinkStack::StackLen()
{
	return (stacksize);
}

Status LinkStack::GetTop(Elemtype &e)
{
	if(top->next = NULL) return error;
	e = top->next->data;
	return ok;
}

Status LinkStack::Push(Elemtype e)
{
	Node *temp;
	temp = new Node;
	if(!temp) return error;		//ÉêÇë¿Õ¼äÊ§°Ü
	temp->data = e; temp->next = top->next;	//Í·²å·¨ 
	top->next = temp;	//ÒÆ¶¯Õ»¶¥Ö¸Õë 
	++stacksize;
	
	return ok;
} 

Status LinkStack::Pop(Elemtype &e)
{
	Node *temp;
	temp = top->next;
	if(!temp) return error;		//Õ»Âú 
	top->next = temp->next; e = temp->data; free(temp);
	--stacksize;
	
	return ok;
}


int main()
{

}
