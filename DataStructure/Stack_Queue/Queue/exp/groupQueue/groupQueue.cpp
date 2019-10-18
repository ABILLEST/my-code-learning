#include <iostream>
#include <string>
#include <queue>
using namespace std;

#define ElemType int

//返回元素对应组数(1,2,3...)，没有定义该元素则返回0
int groupid(ElemType **table, int rows, int cols, ElemType e)
{
    for(int i=0; i<rows; ++i)
    {
        for(int j=0; j<cols; ++j)
        {
            if(table[i][j]==e) return (i+1);
        }
    }

    return 0;    
}

int main()
{
    int t, n;
    string opr;
    queue<int> q;
    bool sameGroupFound = false;

    cin>>t;

    //同组数据定义
    int **definedTable = new int*[t];
    for(int i=0; i<t; ++i)
    {
        cin>>n;
        definedTable[i] = new int[n];
        for(int j=0; j<n; ++j)
        {
            cin>>definedTable[i][j];
        }
    }

    //操作
    while(1)
    {
        cin>>opr;
        if("STOP" == opr)
        {
            break;
        }
        else if("ENQUEUE" == opr)//检索是否有同一组的元素已经存在，如果有，则新元素排在同组的最后，如果没有则插入队列末尾。
        {
            queue<int> newq;        //临时队列
            int inNum, inGroup;
            sameGroupFound = false;

            cin>>inNum;         //输入插入数字
            inGroup = groupid(definedTable, t, n, inNum);        //获取插入组数

            if(q.empty())
            {
                q.push(inNum);    //队列为空时直接插入
                continue;
            }

            //寻找同组元素位置
            while(!q.empty())
            {
                int temp = q.front();
                int groupNum = groupid(definedTable, t, n, temp);    //出列元素组数
                if(groupNum == inGroup)     //找到同组元素
                {
                    sameGroupFound = true;
                    newq.push(temp);  
                    q.pop();
                    if(q.empty())   //同组元素在队尾
                    {
                        newq.push(inNum);
                        break;
                    }
                }
                else            //出列元素与插入元素不为同组
                {
                    if(sameGroupFound)  //上一元素为同组的最后一个
                    {
                        newq.push(inNum);       //插入元素
                        break;
                    }
                    else        //上一元素与插入元素不同组
                    {
                        newq.push(temp);  
                        q.pop();
                    }
                }
            }

            if(!sameGroupFound) newq.push(inNum);   //队列中找不到同组元素

            while(!q.empty())       //剩余元素排在插入元素后入列
            {
                int temp = q.front();
                newq.push(temp);
                q.pop();
            }


            while(!newq.empty())    //重回原队列
            {
                int temp = newq.front();
                q.push(temp);
                newq.pop();
            }
            
        }
        else if("DEQUEUE" == opr)
        {
            int temp = q.front();
            q.pop();
            cout<<temp<<endl;
        }
        //else cerr<<"error"<<endl;
    }

    return 0;
}