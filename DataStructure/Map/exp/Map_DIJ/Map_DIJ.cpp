#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MaxLen = 20;
const int MaxDist = 9999;

class Map
{
private:
    bool Visit[MaxLen];     //访问标志数组
    int Matrix[MaxLen][MaxLen]; //图的邻接矩阵
    int Vexnum;     //图的顶点数量
    void DFS(int v);    //深度优先递归遍历
    void BFS(int v);
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
    void DFSTraverse();
    void BFSTraverse();
    void ShortestPath_DIJ(int v0);
};

//设置邻接矩阵
void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;  //设置图的节点数
    for(i=0; i<MaxLen; ++i)
        for(j=0; j<MaxLen; ++j)
            Matrix[i][j] = MaxDist;
    
    for(i=0; i<Vexnum; ++i)     //邻接矩阵初始化
        for(j=0; j<Vexnum; ++j)
        {
            if(mx[i][j])    //输入数据中0表示无穷大，所以只赋非0的输入
                Matrix[i][j] = mx[i][j];
        }
}

void Map::DFSTraverse()
{
    int v;
    //访问标志数组初始化
    for(v=0; v<Vexnum; ++v)
        Visit[v] = false;
    
    //对所有顶点进行检查
    for(v=0; v<Vexnum; ++v)
        if(!Visit[v])       //如果顶点未访问
            DFS(v);         //调用深度优先搜索
    
    cout<<endl;
}

//从第v个顶点出发递归地深度优先遍历图G
void Map::DFS(int v)
{
    int w,i,k;

    //对顶点v进行访问
    Visit[v] = true;
    cout<<v<<" ";

    //找出与v相连的其他所有节点，存放在AdjVex中
    int *AdjVex = new int[Vexnum];      //存放v连接的顶点编号
    for(int i=0; i<Vexnum; ++i)
        AdjVex[i] = -1;
    
    k=0;    //数组AdjVex的空位置下标

    //搜索邻接矩阵找出与顶点v连接的的其他顶点编号
    for(i=0;i<Vexnum;++i)
    {
        if(Matrix[v][i]==1)
            AdjVex[k++] = i;
    }

    for(i=0; i<k; ++i)
    {
        if(!Visit[AdjVex[i]])
            DFS(AdjVex[i]);
    }
        
    delete []AdjVex;
}

void Map::BFSTraverse()
{
    BFS(0);
}

void Map::BFS(int v)
{
    int w,u;
    int i,k;
    int *AdjVex = new int[Vexnum];
    queue<int> Q;

    for(i=0; i<Vexnum; ++i)
        Visit[i] = false;

    for(v=0; v<Vexnum; ++v)
    {
        if(!Visit[v])
        {
            Visit[v] = true;
            cout<<v<<" ";
            Q.push(v);

            while(!Q.empty())
            {
                u = Q.front();
                Q.pop();

                for(int i=0; i<Vexnum; ++i)
                    AdjVex[i] = -1;

                k=0;
                for(i=0; i<Vexnum; ++i)
                {
                    if(Matrix[u][i]==1)
                        AdjVex[k++] = i;
                }

                i=0;
                for(w=AdjVex[i]; w!=-1; w=AdjVex[i++])
                {
                    if(!Visit[w])
                    {
                        Visit[w] = true;
                        cout<<w<<" ";
                        Q.push(w);
                    }
                        
                }
            }
        }
    }
    cout<<endl;
}

void Map::ShortestPath_DIJ(int v0)
{
    int i,j,v,w,min;
    int *dist = new int[Vexnum];
    bool *final = new bool[Vexnum];
    int path[MaxLen][MaxLen];
    int len[MaxLen];

    for(i=0; i<Vexnum; ++i)
    {
        final[i] = false;
        dist[i] = Matrix[v0][i];
    }

    //初始化path
    for(i=0; i<Vexnum; ++i)
        for (j=0; j<Vexnum; ++j)
        {
            path[i][j] = -1;
        }

    //初始化v0到其他顶点的路径
    for(v=0; v<Vexnum; ++v)
    {
        path[v][0] = v0;
        path[v][1] = v;
        len[v] = 2;
    }

    dist[v0] = 0;
    final[v0] = true;
    //主循环
    for(i=0; i<Vexnum; ++i)
    {
        min = MaxDist;
        //寻找离v0最近的顶点w
        for(w=0; w<Vexnum; ++w)
            if(!final[w])   //顶点在V-S中
                if(dist[w]<min)  //w顶点离v0更近
                {
                    v=w;
                    min = dist[w];
                }
        
        final[v] = true;    //离v0最近的v加入S集
        for(w=0; w<Vexnum; ++w) //更新当前最短路径及距离
            if(!final[w] && (min+Matrix[v][w]<dist[w]))
            {
                dist[w] = min + Matrix[v][w];
                for(int x=0; x<Vexnum; ++x)
                    path[w][x] = path[v][x];
                len[w] = len[v]+1;
                path[w][len[w]-1] = w;
            }
    }

    //输出结果
    for(i=0; i<Vexnum; ++i)
    {
        if(i!=v0)
        {
            cout<<v0<<"-"<<i<<"-"<<dist[i];
            cout<<"----[";
            for(j=0; j<len[i]; ++j)
            {
                cout<<path[i][j]<<" ";
            }
            
            cout<<"]"<<endl;
        }
    }

    delete []dist;
    delete []final;
}

int main()
{
    int t;
    int v0,vnum;
    int mx[MaxLen][MaxLen];
    Map map;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        for(int j=0; j<MaxLen; ++j)
            for(int k=0; k<MaxLen; ++k)
                mx[j][k] = 0;

        cin>>vnum;

        for(int j=0; j<vnum; ++j)
            for(int k=0; k<vnum; ++k)
                cin>>mx[j][k];
        
        map.SetMatrix(vnum, mx);
        cin>>v0;
        map.ShortestPath_DIJ(v0);
    }

    return 0;
}