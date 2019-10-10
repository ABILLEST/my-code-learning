#include <stdio.h>
#define StackSize 100
typedef struct{
int i,j;
}PosType;
typedef struct{
PosType pos;
int di;
} ElemType;
typedef struct {
ElemType elem[StackSize];
int top;
}SqStack;
InitStack(SqStack *pS)
{
pS->top=0; /* top指向栈顶的上一个元素 */
}
int Push(SqStack *pS,ElemType e)
{
if (pS->top==StackSize-1) /* 栈满 */
return 0;
pS->elem[pS->top]=e;
pS->top=pS->top+1;
return 1;
}
int Pop(SqStack *pS,ElemType* pe)
{
if (pS->top==0) /* 栈空 */
return 0;
pS->top = pS->top - 1;
*pe = pS->elem[pS->top];
return 1;
}
main()
{
SqStack S;
ElemType e;
PosType pos,pos_end;
int maze[10][10]={ /* 离散迷宫矩阵，0表示墙壁 */
{0,0,0,0,0,0,0,0,0,0},
{0,1,1,0,1,1,1,0,1,0},
{0,1,1,0,1,1,1,0,1,0},
{0,1,1,1,1,0,0,1,1,0},
{0,1,0,0,0,1,1,1,1,0},
{0,1,1,1,0,1,1,1,1,0},
{0,1,0,1,1,1,0,1,1,0},
{0,1,0,0,0,1,0,0,1,0},
{0,0,1,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0,0,0}
};
int i,j;
InitStack(&S);
pos_end.i=8;pos_end.j=8;
pos.i=1;pos.j=1;
do {
if (maze[pos.i][pos.j]==1) { /* 当前位置不是墙壁并且没走过 */
maze[pos.i][pos.j]=2; /* 标记已走过 */
e.pos = pos;
e.di = 1;
Push(&S,e); /* 加入路径 */
if (pos.i==pos_end.i && pos.j==pos_end.j) /* 如果已经到达终点，退出循环，求得的路径放在栈中 */
break;
else
pos.j++; /* 下一个位置是当前位置的右邻 */
}
else{ /* 当前位置不能通过 */
if(S.top>0){
Pop(&S,&e);
while(e.di==4 && S.top>0){
maze[e.pos.i][e.pos.j]=-1; /* 留下不能通过的标记，并退回一步 */
Pop(&S,&e);
}
if (e.di<4){
e.di++; Push(&S,e); /* 换下一个方向搜索 */
pos.i=e.pos.i; pos.j=e.pos.j;
if (e.di==2) pos.i++; /* 设定当前位置是该方向上的相邻块“右下左上” */
else if (e.di==3) pos.j--;
else if (e.di==4) pos.i--;
}
}
}
}while(S.top>0);
/* 求得的路径放在栈中 */
printf("\n");
while(Pop(&S,&e))
printf("\n(%d,%d)",e.pos.i,e.pos.j);
/* 打印出整个迷宫，2的是所找到的路径，-1是走过的不通的路径 */
printf("\n\n");
for(i=0;i<10;i++) {
for(j=0;j<10;j++)
printf("%2d ",maze[i][j]);
printf("\n");
}
}
