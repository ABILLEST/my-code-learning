#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define ok 1
#define error -1
#define Status int

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

int main()
{
	string str;
	int flag;
	int t, n;
	
	cin>>t;
	for(int i=0; i<t; ++i)
	{
		stack <int>  s;
		
		cin>>n;
		int maze[n][n];
		for(int i=0; i<n; ++i)
			for(int j=0; j<n; ++j)
			{
				cin>>maze[i][j];
			}
		
		//起止点 
		PosType start,end;
		start.x=0;	start.y=0;
		end.x=7;	end.y=7;
		
		if(MazePath(maze,start,end)==1)
		{
			cout<<"求解成功！"<<endl;
		}
		else cout<<"求解失败！"<<endl;
	}
	return 0;
}

Status MazePath(int (*maze), PosType start, PosType end)
{
	//若迷宫maze中存在从入口start到出口end的通道，则求得一条存放在栈中
	stack <int>  s;
	ElementType e;
	
	PosType curpos=start;//设定“当前位置”为“入口位置”
	int curstep=1;//探索第一步
	
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
			if(!s.empty())
			{
				e. = s.top();
				s.pop();
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



//path是保存路径的堆栈，堆栈中每个元素都包含x坐标和y坐标，用属性xp和yp表示

//path1是一个临时堆栈，把path的数据倒序输出到path1，使得路径按正序输出

//	if(!path.empty())	//找到路径
//	{	//......若干代码，实现path的数据导入path1
//		i=0;  //以下是输出路径的代码
//		while (!path1.empty())
//		{	
//			cpos = path1.top();
//			if ( (++i)%4 == 0 ) 
//				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--"<<endl;
//			else
//				cout<<'['<<cpos.xp<<','<<cpos.yp<<']'<<"--";
//
//			path1.pop();
//		}
//		cout<<"END"<<endl;
//	}
//	else
//		cout<<"no path"<<endl; //找不到路径输出no path

