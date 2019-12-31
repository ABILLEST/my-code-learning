#include<iostream>
using namespace std;

#define DIVIDER 11

class HashNode{
    public:
        int data;
        HashNode* next;
        HashNode();
};

HashNode::HashNode()
{
    data= -1;
    next= NULL;
}

void buildHash(HashNode* &root, int data)
{
        if(!root)   //节点为空
        {
            root = new HashNode();
            root->data = data;
        //  cout<<root<<' '<<hashtable[data%11]<<endl;
        }
        else
        {
            while(root)
            {
                root= root->next;                
            }
            root= new HashNode();
            root->data= data;
        }
}

int main()
{
    int n, t, data;
    cin>>n;
    HashNode* hashtable[DIVIDER];
    
    for(int i= 0; i< DIVIDER; i++)
        hashtable[i]= NULL;

    for(int i= 0; i< n; i++)
    {
        cin>>data;
        HashNode* root= hashtable[data%DIVIDER];  //求余法
        buildHash(hashtable[data%DIVIDER], data);
    }

    cin>>t;
    for(int i= 0; i< t; i++)
    {
        int count = 0;
        cin>>data;
        HashNode* root= hashtable[data%DIVIDER];
        if(!root)   //查找不成功
        {
            cout<<"error"<<endl;
            //表头插入
            hashtable[data%DIVIDER]= new HashNode();
            hashtable[data%DIVIDER]->data = data;
        }
        else
        {
            while(true)
            {
                ++count;
                if(root->data == data)
                {
                    cout<<data%DIVIDER<<' '<<count<<endl;
                    break;
                }
                else
                {
                    if(!root->next) //查找不成功
                    {
                        cout<<"error"<<endl;
                        /*
                        //表头插入
                        HashNode *temp = new HashNode;
                        temp->data = hashtable[data%DIVIDER]->data;
                        temp->next = hashtable[data%DIVIDER]->next;
                        hashtable[data%DIVIDER]->next = temp;
                        hashtable[data%DIVIDER]->data = data;
                        */
                        //表尾插入
                        root->next = new HashNode;
                        root->next->data = data;
                        break;
                    }
                    root= root->next;
                }
            }           
        }
    }    
    return 0;
}