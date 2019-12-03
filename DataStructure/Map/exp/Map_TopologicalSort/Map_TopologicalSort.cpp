#include <iostream>
using namespace std;

const int MaxLen = 20;
const int MaxDist = 9999;

class Map
{
private:
    bool Visit[MaxLen];     //访问标志数组
    int Matrix[MaxLen][MaxLen]; //图的邻接矩阵
    int isFinished[MaxLen];     //输出过的顶点
    int Vexnum;     //图的顶点数量
    void DFS(int v, int &c);    //深度优先递归遍历
    void BFS(int v);
    int select();
    void update(int v);
public:
    void SetMatrix(int vnum, int mx[MaxLen][MaxLen]);
    void DFSTraverse();
    void BFSTraverse();
    void ShortestPath_DIJ(int v0);
    bool isStrongConnect();
    bool isZeroInDegree(int vexNo);
    void TopologicalSort();
};

//设置邻接矩阵
void Map::SetMatrix(int vnum, int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;  //设置图的节点数

    for(i= 0; i<Vexnum; ++i)
              isFinished[i]= false;

    for(i=0; i<MaxLen; ++i)
        for(j=0; j<MaxLen; ++j)
            Matrix[i][j] = 0;
    
    for(i=0; i<Vexnum; ++i)     //邻接矩阵初始化
        for(j=0; j<Vexnum; ++j)
        {
            if(mx[i][j])    //输入数据中0表示无穷大，所以只赋非0的输入
                Matrix[i][j] = mx[i][j];
        }
}

int Map::select()
{
    for(int i=0; i<Vexnum; ++i)
    {
        if(!isFinished[i] && isZeroInDegree(i)) //找到度为0的顶点
        {
            isFinished[i]= true;        //表示已经找到过改顶点
            return i;
}
    }
}

//判断顶点的度是否为0
bool Map::isZeroInDegree(int vexNo)
{
    int i;
    //按列查找
    for(i= 0; i<Vexnum && !Matrix[i][vexNo]; ++i)
    {
        if(i==Vexnum-1 && !Matrix[i][vexNo])
            return true;
    }
    return false;
}

//分离出该顶点
void Map::update(int v)
{
    for(int i=0; i<Vexnum; ++i)
    {
        Matrix[v][i] = 0;
    }
}

void Map::TopologicalSort()
{
    for(int i= 0; i< Vexnum; i++)
    {
        int v= select();
        if(v== -1)
            break;
            
        update(v);
        cout<<v<<" ";
    }
    cout<<endl;
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
        map.TopologicalSort();
    }

    return 0;
}