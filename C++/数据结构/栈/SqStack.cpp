#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

#define ok 0
#define error -1
#define Elemtype int
#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10


class SqStack
{
	Elemtype *base, *top;
	int stacksize;
public:
	SqStack();
	~SqStack();
	bool ClearStack();
	bool StackEmpty();
	int StackLen();
	int GetTop(Elemtype &e);
	int Push(Elemtype e);
	int Pop(Elemtype &e);
	
};


SqStack::SqStack()
{
	base = new Elemtype[STACK_INIT_SIZE];
	if(!base) exit(error);
	top = base;
	stacksize = STACK_INIT_SIZE;
}

SqStack::~SqStack()
{
	
}

bool SqStack::StackEmpty()
{
	if(base == top) return true;
	return false;
}

int SqStack::StackLen()
{
	return stacksize;
}

int SqStack::GetTop(Elemtype &e)
{
	if(top == base) return error;
	e = *(top-1);
	return ok;
}

int SqStack::Push(Elemtype e)
{
	if(top-base >= stacksize)	//Õ»Âú£¬×·¼Ó´æ´¢¿Õ¼ä
	{
		base = new Elemtype[STACK_INCREMENT];
		if(!base) exit(error);
		
		top = base + stacksize;
		stacksize += STACK_INCREMENT;
	}
	*top++ = e;
	return ok;
} 

int SqStack::Pop(Elemtype &e)
{
	if(top == base) return error;
	e = *--top;
	return ok;
} 


int main()
{

}
