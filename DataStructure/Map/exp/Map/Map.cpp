#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int MaxLen = 20;  //设定图最多包含20个顶点

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
};

//设置邻接矩阵
void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;  //设置图的节点数

    for(i=0; i<MaxLen; ++i)     //矩阵域全置0
        for(j=0; j<MaxLen; ++j)
            Matrix[i][j] = 0;
    
    for(i=0; i<Vexnum; ++i)     //邻接矩阵初始化
        for(j=0; j<Vexnum; ++j)
            Matrix[i][j] = mx[i][j];
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

//从第v个顶点出发深度优先遍历图G（递归）
void Map::DFS(int v)
{
    int w,i,k;

    //对顶点v进行访问
    Visit[v] = true;        //标志已访问
    cout<<v<<" ";

    //找出与v相连的其他所有节点，存放在AdjVex中
    int *AdjVex = new int[Vexnum];      //存放v连接的顶点编号
    for(int i=0; i<Vexnum; ++i)
        AdjVex[i] = -1;     //-1表示不可达
    
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

int main()
{
    int t;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        int n;
        Map map;
        cin>>n;
        int mx[MaxLen][MaxLen];

        for(int j=0; j<n; ++j)
            for(int k=0; k<n; ++k)
                cin>>mx[j][k];
        
        map.SetMatrix(n, mx);
        map.DFSTraverse();
    }

    return 0;
}