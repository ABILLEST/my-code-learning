#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    int t, n;
    string opr;
    queue<int> q;

    cin>>t;
    
    //初始入列
    for(int i=0; i<t; ++i)
    {
        cin>>n;
        for(int j=0; j<n; ++j)
        {
            int temp;
            cin>>temp;
            q.push(temp);
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
        else if("ENQUEUE" == opr)
        {
            queue<int> newq;        //临时队列
            int inNum, inGroup;

            cin>>inNum;         //输入插入数字
            inGroup = inNum/100;        //插入组数

            while(!q.empty())
            {
                int temp = q.front();
                int groupNum = temp/100;    //出列元素组数
                if(groupNum <= inGroup)
                {
                    newq.push(temp);        //排在插入元素前进入新列
                    q.pop();
                }
                else
                {
                    newq.push(inNum);       //插入元素
                    break;
                }
            }
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
        else cerr<<"error"<<endl;
    }

    return 0;
}