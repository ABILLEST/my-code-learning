#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MaxW = 9999;
static int error = -1;
static int ok = 1;
#define Status int

class HuffmanNode
{
public:
    int weight;
    int parent;
    int leftchild;
    int rightchild;
    char name;
};

class Huffman
{
private:
    void MakeTree();
    void SelectMin(int pos, int *s1, int *s2);
public:
    int len;
    int lnum;
    HuffmanNode *huffTree;
    string * huffCode;
    void MakeTree(int n, int wt[]);
    void Coding();
    void Destroy();
    Status Decode(const string codestr, char txtstr[]);
};

void Huffman::MakeTree(int n, int wt[])
{
    int i;
    lnum = n;
    len = 2*n-1;
    huffTree = new HuffmanNode[2*n];
    huffCode = new string[lnum+1];

    for(i=1; i<=n; ++i)
    {
        huffTree[i].weight = wt[i-1];
    }
    for(i=1; i<=len; ++i)
    {
        if(i>n)
        {
            huffTree[i].weight = 0;
        }
        huffTree[i].parent = 0;
        huffTree[i].leftchild = 0;
        huffTree[i].rightchild = 0;
    }
    MakeTree();
}

//?
void Huffman::SelectMin(int pos, int *s1, int *s2)
{
    int w1, w2, i;
    w1 = w2 = MaxW;
    *s1 = *s2 = 0;
    for(i=1; i<=pos; ++i)
    {
        if(huffTree[i].weight<w1 && 0==huffTree[i].parent)
        {
            w2 = w1;
            *s2 = *s1;
            w1 = huffTree[i].weight;
            *s1 = i;
        }
        else
        {
            if(huffTree[i].weight<w2 && 0==huffTree[i].parent)
            {
                w2 = huffTree[i].weight;
                *s2 = i;
            }
        }
    }
}

void Huffman::MakeTree()
{
    int i, s1, s2;
    for(i=lnum+1; i<=len; ++i)
    {
        SelectMin(i-1, &s1, &s2);
        huffTree[s1].parent = i;
        huffTree[s2].parent = i;
        huffTree[i].leftchild = s1;
        huffTree[i].rightchild = s2;
        huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
    }
}

void Huffman::Destroy()
{
    len = 0;
    lnum = 0;
    delete []huffTree;
    delete []huffCode;
}

void Huffman::Coding()
{
    char *cd;
    int i, c, f, start;

    cd = new char[lnum];
    cd[lnum-1] = '\0';
    for(i=1; i<=lnum; ++i)
    {
        start = lnum-1;
        for(c=i,f=huffTree[i].parent; f!=0; c=f,f=huffTree[f].parent)
            if(huffTree[f].leftchild==c) cd[--start] = '0';
            else cd[--start] = '1';
        huffCode[i].assign(&cd[start]);
    }
    delete []cd;
}

Status Huffman::Decode(const string codestr, char txtstr[])
{
    int i, k, c;
    char ch;
    c = len;

    k = 0;
    for(i=0; i<codestr.length(); ++i)
    {
        ch = codestr[i];
        if('0'==ch)
        {
            c = huffTree[c].leftchild;
        }
        if('1'==ch)
        {
            c = huffTree[c].rightchild;
        }
        if(ch!='1' && ch!='0')
        {
            return error;
        }

        if(!huffTree[c].leftchild && !huffTree[c].rightchild)
        {
            txtstr[k] = huffTree[c].name;
            ++k;
            c = len;
        }
        else
            ch = '\0';
    }
    if(ch=='\0') return error;
    else txtstr[k] = '\0';
    return ok;
}

int main()
{
    int t, n,i,j;
    int wt[800];
    char ch[800];
     
    Huffman myHuff;
    cin>>t;
    for(i= 0; i< t; i++){
         
         
         
        cin>>n;
        for(j= 0; j< n; j++)
           cin>>wt[j];
        for(j= 0; j< n; j++){
            cin>>ch[j];
            //cout<<ch[j]<<endl;
        }
            
            
        myHuff.MakeTree(n, wt);
 
        int in;
        cin>>in;
        while(in--){
            string str;
            char txt[800];
            cin>>str;
            //cout<<str<<endl;
            if(myHuff.Decode(str, txt)!= -1)
            cout<<txt<<endl;
            else
            cout<<"error"<<endl;
        }
 
 
 
 
 
        myHuff.Destroy();
    }

    return 0;
}