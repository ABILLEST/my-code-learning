#include <iostream>
#include <string>
using namespace std;


class BiTreeNode
{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode() : LeftChild(NULL),RightChild(NULL){}
    ~BiTreeNode(){}
};

class BiTree
{
private:
    BiTreeNode *Root;
    BiTreeNode *pre;
    int pos;
    string strTree;
    BiTreeNode* CreateBiTree();
    void PreOrder(BiTreeNode* t);
    void InOrder(BiTreeNode* t);
    void PostOrder(BiTreeNode* t);
    void LeafCount(BiTreeNode* t, int& n);
    void LLeafCount(BiTreeNode* t, int& n);
    void Leaf_prt(BiTreeNode* t);
    void LeafDad_prt(BiTreeNode* t);
public:
    BiTree();
    ~BiTree();
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
    int LeafCount();
    int LLeafCount();
    void Leaf_prt();
    void LeafDad_prt();
};

BiTree::BiTree(/* args */)
{
    Root = new BiTreeNode();
}

BiTree::~BiTree()
{
}

void BiTree::CreateTree(string TreeArray)
{
    pos = 0;
    strTree.assign(TreeArray);
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

int BiTree::LLeafCount()
{
    int n=0;
    pre = Root;
    LLeafCount(Root, n);
    return n;
}

void BiTree::LLeafCount(BiTreeNode* t, int& n)
{
    if(t)
    {
        if(!t->LeftChild && !t->RightChild && pre->LeftChild==t)
        {
            ++n;
        }
        pre = t;
        LLeafCount(t->LeftChild,n);
        LLeafCount(t->RightChild,n);
    }
}

void BiTree::Leaf_prt()
{
    Leaf_prt(Root);
    cout<<endl;
}

void BiTree::Leaf_prt(BiTreeNode* t)
{
    if(t)
    {
        Leaf_prt(t->LeftChild);
        if(!t->LeftChild && !t->RightChild )
        {
            cout<<t->data<<" ";
        }
        Leaf_prt(t->RightChild);
    }
}

void BiTree::LeafDad_prt()
{
    int n=0;
    pre = Root;
    LeafDad_prt(Root);
    cout<<endl;
}

void BiTree::LeafDad_prt(BiTreeNode* t)
{
    if(t)
    {
        if(t->LeftChild || t->RightChild)   //是父亲节点则保存
            pre=t;
        LeafDad_prt(t->LeftChild);
        if(!t->LeftChild && !t->RightChild)
        {
            cout<<pre->data<<" ";
        }
        if(t->LeftChild || t->RightChild)
            pre=t;
        LeafDad_prt(t->RightChild);
    }
}

int main()
{
    int t, count=0;
    string str;
    BiTree bt;

    cin>>t;

    for(int i=0; i<t; ++i)
    {
        cin>>str;
        bt.CreateTree(str);
        bt.Leaf_prt();
        bt.LeafDad_prt();
    }
    return 0;
}