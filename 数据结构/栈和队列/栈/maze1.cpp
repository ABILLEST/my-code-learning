#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#define TRUE 1
#define FALSE 0
#define NUMBER 20
using namespace std;
typedef int Status;
typedef struct
{//坐标
int x;
int y;
}PosType;
typedef struct
{//结点类型
int order;
int directory;
PosType seat;
}ElementType;
typedef struct node1
{//栈类型
ElementType node;
struct node1 *next;
}StackNode,* LinkStack;
void InitStack(LinkStack &head);
int IsStackEmpty(LinkStack head);
int Push(LinkStack head, ElementType element);
int Pop(LinkStack head, ElementType &element);
int GetTop(LinkStack head, ElementType &element);
int StackLength(LinkStack head);
Status ClearStack(LinkStack &S);
Status DestroyStack(LinkStack &head);
Status Pass(PosType curpos,int (*a)[10]);//判断当前位置是否可通过
PosType NextPos(PosType curpos,int directory);//相对于当前位置的下一方向位置坐标
void MarkPrint(int &a);//留下不能通过的标记
void InitStack(LinkStack &head){
head=(LinkStack)malloc(sizeof(StackNode));
if(head==NULL){cout<<"分配存储空间失败！"<<endl;exit(0);}
head->next = NULL;
}
int IsStackEmpty(LinkStack head){
if(head->next == NULL) return TRUE;
return FALSE;
}
int Push(LinkStack head, ElementType element){
StackNode *newp;
newp = (StackNode *)malloc(sizeof(StackNode));
if(newp == NULL) {cout<<"分配存储空间失败！"<<endl;exit(0);}
newp->node = element;
newp->next = head->next;
head->next = newp;
return TRUE;
}
int Pop(LinkStack head, ElementType &element){
if(IsStackEmpty(head)) return FALSE;
StackNode *newp = head->next;
element = newp->node;
head->next = newp->next;
free(newp);
return TRUE;
}
int GetTop(LinkStack head, ElementType &element){
element = head->next->node;
if(head->next==NULL)return FALSE;
return TRUE;
}
int StackLength(LinkStack head)
{
LinkStack p;
int i=0;
p=head->next;
while(p)
{
i++;
p=p->next;
}
return i;
}
Status ClearStack(LinkStack &S)
{
LinkStack p;
while(S->next)
{
p=S->next;
S->next=S->next->next;
delete p;
}
return TRUE;
}
Status DestroyStack(LinkStack &head)
{
LinkStack q;
while(head)
{
q=head->next;
delete head;
head=q;
}
return TRUE;
}
//判断当前位置是否可通过
Status Pass(PosType curpos,int (*a)[10]){
if(a[curpos.x][curpos.y]==1||a[curpos.x][curpos.y]==-1)
return FALSE;
return TRUE;
}
//相对于当前位置的下一方向位置坐标
PosType NextPos(PosType curpos,int directory){
switch(directory)
{
case 1:
curpos.x=curpos.x+1;break;
case 2:
curpos.y=curpos.y+1;break;
case 3:
curpos.x=curpos.x-1;break;
case 4:
curpos.y=curpos.y-1;break;
}
return curpos;
}
//留下不能通过的标记
void MarkPrint(int &a){
a=-1;
}
void PrintStack(LinkStack head)
{
LinkStack p;
cout<<"从迷宫的出口到入口的路径为："<<endl;
while(head->next)
{
cout<<"("<<head->next->node.seat.x<<","<<head->next->node.seat.y<<")"<<" ";
p=head->next;
head->next=head->next->next;
free(p);
}
}
Status MazePath(int (*maze)[10],PosType start,PosType end)
{
//若迷宫maze中存在从入口start到出口end的通道，则求得一条存放在栈中
LinkStack S;
ElementType e;
PosType curpos=start;//设定“当前位置”为“入口位置”
int curstep=1;//探索第一步
InitStack(S);
do{
if(Pass(curpos,maze)){//当前位置可以通过，即是未曾走到过的通道块
e.order=curstep;
e.directory=1;
e.seat=curpos;
Push(S,e); //加入路径
maze[e.seat.x][e.seat.y]=-1;
if(curpos.x==end.x&&curpos.y==end.y)//到达终点（出口）
{
PrintStack(S);
return TRUE;
}
curpos=NextPos(curpos,1);//下一位置是当前位置的东邻
curstep++;//探索下一步
}//if
else{//当前位置不能通过
if(!IsStackEmpty(S))
{
Pop(S,e);
while(e.directory==4&&!IsStackEmpty(S))
{
//maze[e.seat.x][e.seat.y]
MarkPrint(maze[e.seat.x][e.seat.y]);
Pop(S,e);
}//while
if(e.directory<4)
{
e.directory++;
Push(S,e);
maze[e.seat.x][e.seat.y]=-1;
curpos=NextPos(e.seat,e.directory);
}//if
}//if
}//else
}while(!IsStackEmpty(S));
return FALSE;
}
int main()
{
int maze[10][10]={
{1,1,1,1,1,1,1,1,1,1},//0
{1,0,0,0,0,0,0,0,1,1},//1
{1,0,0,0,1,0,1,1,0,1},//2
{1,1,1,0,1,0,0,1,0,1},//3
{1,0,0,0,1,1,0,1,0,1},//4
{1,0,0,1,0,0,0,0,0,1},//5
{1,0,1,0,0,0,1,1,0,1},//6
{1,1,1,0,0,0,0,1,0,1},//7
{1,0,0,0,0,0,0,0,0,1},//8
{1,1,1,1,1,1,1,1,1,1} //9
};
PosType start,end;
start.x=1;start.y=1;
end.x=8;end.y=8;
if(MazePath(maze,start,end)==1)
cout<<"求解成功！"<<endl;
else cout<<"求解失败！"<<endl;
}
