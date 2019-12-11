#include <iostream>
#include <string>
using namespace std;

#define Status int
int count = 0;

class BSTNode
{
public:
    int key;
    BSTNode *LeftChild;
    BSTNode *RightChild;
    BSTNode() : LeftChild(NULL), RightChild(NULL) {}
    ~BSTNode() {LeftChild=NULL; RightChild=NULL;}
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
    Status Delete(BSTNode *&t);
    Status DeleteBST(BSTNode *&t, int k);
public:
    BST();
    ~BST();
    void CreateTree(string TreeArray);
    void InOrder();
    Status search(int e);
    Status insert(int e);
    Status DeleteBST(int e);
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
    ++count;
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
    count = 0;
    if(search(Root,e,f,p))
    {
        cout<<count<<endl;
        return true;
    }
    else 
    {
        cout<<"-1"<<endl;
        return false;
    }
    
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

Status BST::DeleteBST(int e)
{
    if(DeleteBST(Root, e))
        return true;
    else return false;
}

Status BST::DeleteBST(BSTNode *&t, int k)
{
    if(!t)
        return false;
    else
    {
        if(k == t->key)
            return Delete(t);
        else if(k < t->key)
            return DeleteBST(t->LeftChild, k);
        else return DeleteBST(t->RightChild, k);
    }
    
}

//!important!
Status BST::Delete(BSTNode *&p)
{
    BSTNode * q;
    if(!p->RightChild)
    {
        q= p;
        p = p->LeftChild;
        delete q;
    }
    else if(!p->LeftChild)
    {
        q = p;
        p = p->RightChild;
        delete q;
    }
    else
    {
        q = p;
        BSTNode * s = new BSTNode;
        s = p->LeftChild;
        while (s->RightChild)
        {
            q = s;
            s = s->RightChild;
        }
        p->key = s->key;
        if(q != p)
            q->RightChild = s->LeftChild;
        else q->LeftChild = s->LeftChild;
        delete s;
    }
    return true;
}

//insert and build
int main()
{
    int t, n, m, num;
    BST bst;
    cin >> t;

    for(int i=0; i<t; ++i)
    {
        //build
        cin>>n;
        for(int j=0; j<n; ++j)
        {
            cin>>num;
            bst.insert(num);
        }
        bst.InOrder();

        //delete
        cin>>m;
        for(int j=0; j<m; ++j)
        {
            cin>>num;
            bst.DeleteBST(num);
            bst.InOrder();
        }
    }
    
    return 0;
}
