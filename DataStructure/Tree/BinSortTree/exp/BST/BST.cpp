#include <iostream>
#include <string>
using namespace std;

#define Status int

class BSTNode
{
public:
    int key;
    BSTNode *LeftChild;
    BSTNode *RightChild;
    BSTNode() : LeftChild(NULL), RightChild(NULL) {}
    ~BSTNode() {}
};

class BST
{
private:
    BSTNode *Root;
    int pos;
    string strTree;
    BSTNode *CreateBST();
    void InOrder(BSTNode *t);
    Status search(BSTNode *t, int k, BSTNode *f, BSTNode *&p);
public:
    BST();
    ~BST();
    void CreateTree(string TreeArray);
    void InOrder();
    Status search(int e);
    Status insert(int e);
};

BST::BST(/* args */)
{
    //Root = new BSTNode();
    Root = NULL;
}

BST::~BST()
{
}

void BST::InOrder()
{
    InOrder(Root);
    cout<<endl;
}

void BST::InOrder(BSTNode *t)
{
    if (t)
    {
        InOrder(t->LeftChild);
        cout << t->key<<" ";
        InOrder(t->RightChild);
    }
}

Status BST::search(BSTNode *t, int k, BSTNode *f, BSTNode *&p)
{
    if(!t)
    {
        p = f;
        return false;
    }
    else if(k == t->key)
    {
        p = t;
        return true;
    }
    else if(k < t->key)
    {
        return search(t->LeftChild, k, t, p);
    }
    else return search(t->RightChild, k, t, p);
}

Status BST::search(int e)
{
    BSTNode * f = new BSTNode;
    BSTNode * p = new BSTNode;
    if(search(Root,e,f,p))
        return true;
    else return false;
}

Status BST::insert(int e)
{
    BSTNode *p = new BSTNode;
    //p = NULL;
    if(!search(Root, e, NULL, p))
    {
        BSTNode * s = new BSTNode;
        s->key = e;
        s->LeftChild = s->RightChild = NULL;
        if(!Root)
            Root = s;
        else if(e < p->key) p->LeftChild = s;
        else p->RightChild = s;
        return true;
    }
    else return false;
}

//insert and build
int main()
{
    int t, n, m, insNum;
    BST bst;
    cin >> t;

    for(int i=0; i<t; ++i)
    {
        cin>>n;
        for(int j=0; j<n; ++j)
        {
            cin>>insNum;
            bst.insert(insNum);
        }
        bst.InOrder();

        cin>>m;
        for(int j=0; j<m; ++j)
        {
            cin>>insNum;
            bst.insert(insNum);
            bst.InOrder();
        }
    }
    
    return 0;
}
