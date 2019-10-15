#include <stdio.h>

#define ok 1
#define error -1

typedef struct 
{
    int OccurTime;
    int NType;
}Event, ElemType;

typedef struct LNode
{
    int data;
    struct LNode * next;
}LNode, *LinkList;

typedef LinkList EventList;

typedef struct QNode
{
    QElemType data;
    struct QNode * next;
}QNode, *QueuePtr;

typedef struct 
{
    QueuePtr front;
    QueuePtr rear;
};

typedef struct 
{
    int ArrivalTime;
    int Duration;
}QElemType;

EventList ev;   //事件表
Event en;       //事件
LinkList q[5];  //4个客户队列
QElemType customer; //客户记录
int TotalTime, CustomerNum;

//比较事件发生的时刻
int cmp(Event a, Event b);

//初始化
void OpenForDay()
{
    TotalTime = 0;  CustomerNum = 0;
    InitList(ev);
    en.OccurTime = 0;   en.NType = 0;
    OrderInsert(ev, en, cmp);
    for(int i=1; i<=4; ++i) InitQueue(q[i]);
}

void Bank_Stimulation()
{
    
}