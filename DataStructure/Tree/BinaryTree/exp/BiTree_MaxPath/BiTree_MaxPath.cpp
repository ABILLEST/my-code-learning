#include <iostream>
#include <string>
#include <queue>
using namespace std;

int *power;

class BiTreeNode
{
public:
    char data;
    int weight;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode() : LeftChild(NULL),RightChild(NULL),weight(0){}
    ~BiTreeNode(){}
};

class BiTree
{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    int *weight;
    int n;
    int pos_wt;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode* t);
    void InOrder(BiTreeNode* t);
    void PostOrder(BiTreeNode* t);
    void LeafCount(BiTreeNode* t, int& n);
    void LevelOrder(BiTreeNode * t);
    void LevelCount(BiTreeNode* t, int& n);
    void MaxPath(BiTreeNode* t, int& n);
public:
    BiTree();
    ~BiTree();
    void CreateTree(string TreeArray,int wt[], int _n);
    void PreOrder();
    void InOrder();
    void PostOrder();
    int LeafCount();
    void LevelOrder();
    int LevelCount();
    int MaxPath();
};

BiTree::BiTree(/* args */)
{
    Root = new BiTreeNode();
}

BiTree::~BiTree()
{
}

void BiTree::CreateTree(string TreeArray,int wt[], int _n)
{
    pos = 0;
    pos_wt=0;
    n = _n;
    weight = new int[n+5];
    strTree.assign(TreeArray);
    for(int i= 0; i< n; i++)
		weight[i]= wt[i];
    Root = CreateBiTree();
}

BiTreeNode* BiTree::CreateBiTree()
{
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if('0' == ch)
    {
        T = NULL;
    }
    else
    {
        T = new BiTreeNode();
        T->data = ch;
        T->weight = weight[pos_wt++];
        T->LeftChild = CreateBiTree();
        T->RightChild = CreateBiTree();
    }

    return T;
}

void BiTree::PreOrder()
{   PreOrder(Root);  }

void BiTree::PreOrder(BiTreeNode* t)
{
    if(t)
    {
        cout<<t->data;
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

void BiTree::InOrder()
{   InOrder(Root);  }

void BiTree::InOrder(BiTreeNode* t)
{
    if(t)
    {
        InOrder(t->LeftChild);
        cout<<t->data;
        InOrder(t->RightChild);
    }
}

void BiTree::PostOrder()
{   PostOrder(Root);    }

void BiTree::PostOrder(BiTreeNode* t)
{
    if(t)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout<<t->data;
    }
}

int BiTree::LeafCount()
{
    int n=0;
    LeafCount(Root, n);
    return n;
}

void BiTree::LeafCount(BiTreeNode* t, int& n)
{
    if(t)
    {
        if(!t->LeftChild && !t->RightChild)
        {
            ++n;
        }
        LeafCount(t->LeftChild,n);
        LeafCount(t->RightChild,n);
    }
}

void BiTree::LevelOrder()
{   LevelOrder(Root);   }

void BiTree::LevelOrder(BiTreeNode* t)
{
    queue<BiTreeNode*> tq;
    BiTreeNode* p = t;
    
    if(p)
    {
        tq.push(p);
    }
    while(!tq.empty())
    {
        p = tq.front();
        tq.pop();
       
        cout<<p->data;

        if(p->LeftChild) tq.push(p->LeftChild);
        if(p->RightChild) tq.push(p->RightChild);
       
   }
   cout<<endl;
}

int BiTree::LevelCount()
{
    int n=1;
    LevelCount(Root, n);
    return n;
}

void BiTree::LevelCount(BiTreeNode* t, int& n)
{
    int h1,h2;
    if(!t) n=0;
    if(t)
    {
        LevelCount(t->LeftChild,h1);
        LevelCount(t->RightChild,h2);
        n = (h1>h2?h1:h2)+1;
    }
}

int BiTree::MaxPath()
{
    int maxP=0;
    MaxPath(Root, maxP);
    return maxP;
}

void BiTree::MaxPath(BiTreeNode* t, int& maxpower)
{
    if(t)
    {
        if(t->LeftChild && t->RightChild)
        {
            t->LeftChild->weight += t->weight;
            t->RightChild->weight += t->weight;
        }
        else if(t->LeftChild)
        {
            t->LeftChild->weight += t->weight;
        }
        else if(t->RightChild)
        {
            t->RightChild->weight += t->weight;
        }

        maxpower = maxpower>t->weight?maxpower:t->weight;   //
        MaxPath(t->LeftChild,maxpower);
        MaxPath(t->RightChild,maxpower);
    }
}

int main()
{
    int t, count=0,maxP;
    string str;
    BiTree bt;

    cin>>t;

    for(int i=0; i<t; ++i)
    {
        int n=0;
        cin>>str;

        cin>>n;
        power = new int[n+5];   //这里为什么要+5?
        for(int j=0;j<n;++j)
        {
            cin>>power[j];
        }

        bt.CreateTree(str,power,n);

        maxP = bt.MaxPath();
        cout<<maxP<<endl;
    }
    return 0;
}