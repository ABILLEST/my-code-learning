#include <iostream>
#include <string>
using namespace std;

class BiTreeNode
{
public:
    char data;
    BiTreeNode *LeftChild;
    BiTreeNode *RightChild;
    BiTreeNode() : LeftChild(NULL), RightChild(NULL) {}
    ~BiTreeNode() {}
};

class BiTree
{
private:
    BiTreeNode *Root;
    int pos;
    string strTree;
    BiTreeNode *CreateBiTree();
    void PreOrder(BiTreeNode *t);
    void InOrder(BiTreeNode *t);
    void PostOrder(BiTreeNode *t);

public:
    BiTree();
    ~BiTree();
    void CreateTree(string TreeArray);
    void PreOrder();
    void InOrder();
    void PostOrder();
};

BiTree::BiTree(/* args */)
{
    Root = new BiTreeNode();
}

BiTree::~BiTree()
{
}

//利用先序遍历结果建树
void BiTree::CreateTree(string TreeArray)
{
    pos = 0;
    strTree.assign(TreeArray);
    Root = CreateBiTree();
}

//递归建树，类内实现
BiTreeNode *BiTree::CreateBiTree()
{
    BiTreeNode *T;
    char ch;
    ch = strTree[pos++];
    if ('0' == ch)
    {
        T = NULL;
    }
    else
    {
        T = new BiTreeNode();   //生成根节点
        T->data = ch;
        T->LeftChild = CreateBiTree();  //构造左子树
        T->RightChild = CreateBiTree(); //构造右子树
    }

    return T;
}

void BiTree::PreOrder()
{
    PreOrder(Root);
}

void BiTree::PreOrder(BiTreeNode *t)
{
    if (t)
    {
        cout << t->data;    //代表已访问
        PreOrder(t->LeftChild);
        PreOrder(t->RightChild);
    }
}

void BiTree::InOrder()
{
    InOrder(Root);
}

void BiTree::InOrder(BiTreeNode *t)
{
    if (t)
    {
        InOrder(t->LeftChild);
        cout << t->data;
        InOrder(t->RightChild);
    }
}

void BiTree::PostOrder()
{
    PostOrder(Root);
}

void BiTree::PostOrder(BiTreeNode *t)
{
    if (t)
    {
        PostOrder(t->LeftChild);
        PostOrder(t->RightChild);
        cout << t->data;
    }
}

int main()
{
    int t;
    string str;
    BiTree bt;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        cin >> str;
        bt.CreateTree(str);
        bt.PreOrder();
        cout << endl;
        bt.InOrder();
        cout << endl;
        bt.PostOrder();
        cout << endl;
    }
    return 0;
}