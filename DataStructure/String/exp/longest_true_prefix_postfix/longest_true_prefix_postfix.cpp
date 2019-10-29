/*
题目：
给定一个串，如ABCDAB，则 ABCDAB的真前缀有：{ A, AB,ABC, ABCD, ABCDA } 
ABCDAB的真后缀有：{ B, AB,DAB, CDAB, BCDAB } 因此，该串的真前缀和真后缀中最长的相等串为AB，
我们称之为该串的“最长的真前后缀”。 试实现一个函数string matched_Prefix_Postfix(string str)，
得到输入串str的最长的真前后缀。若不存在最长的真前后缀则输出empty
*/


#include <iostream>
#include <string>
using namespace std;

#define Status int

static int ok = 1;

class myString
{
private:
    string mainstr;
    int size;

    void GetNext(string p, int next[]);
    int KMPFind(string p, int pos, int next[]);
public:
    myString(/* args */);
    ~myString();
    void SetVal(string sp);
    int KMPFindSubStr(string p, int pos);
    Status Replace_first_of(string mode, string p);
    string matched_Prefix_Postfix();
};

myString::myString(/* args */)
{
    size = 0;
    mainstr = "";
}

myString::~myString()
{
    size = 0;
    mainstr = "";
}

void myString::GetNext(string p, int next[])
{
    int i=0, j=-1;
    next[0] = -1;
    int len = p.length();
    while(i<len)
    {
        if(-1==j || p[i]==p[j])
        {
            ++i;
            ++j;
            next[i] = j;
        }
        else j = next[j];
    }
}

int myString::KMPFind(string p, int pos, int next[])
{
    int i=pos-1, j=-1;
    int mainLen = mainstr.length(), pLen = p.length();
    while(i<mainLen && j<pLen)
    {
        if(-1==j || mainstr[i]==p[j]){++i; ++j;}
        else j = next[j];
    }
    if(j >= pLen) return (i-pLen+1);
    else return 0;
}

void myString::SetVal(string sp)
{
    mainstr = "";
    mainstr.assign(sp);
    size = mainstr.length();
}

int myString::KMPFindSubStr(string p, int pos)
{
    int i;
    int L = p.length();
    int *next = new int[L+1];
    GetNext(p, next);
    for(int i=0; i<L; ++i)
        cout<<next[i]<<' ';
    cout<<endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    
    delete []next;

    return v;
}

Status myString::Replace_first_of(string mode, string p)
{
    cout<<mainstr<<endl;
    int L = mode.length();
    int *next = new int[L+1];
    GetNext(mode, next);
    int v = KMPFind(mode, 0, next);
    if(v)
    {
        mainstr.replace(v-1, mode.length(), p);
    }
    cout<<mainstr<<endl;
    return ok;
}

string myString::matched_Prefix_Postfix()
{
    int L = mainstr.length();
    string *pre = new string[L-1];
    string *post = new string [L-1];
    string longest_true_str = "";
    int longest_true_len = 0;

    //计算真前后缀
    for(int i=0; i<L-1; ++i)
    {
        pre[i] = mainstr.substr(0,i+1);
        int len = pre[i].length();
        pre[i][len] = '\0';
    }
    for(int i=0; i<L-1; ++i)
    {
        post[i] = mainstr.substr(L-1-i);
        int len = post[i].length();
        post[i][len] = '\0';
    }

    //寻找最长真前后缀
    for(int i=0; i<L-1; ++i)
    {
        for(int j=0; j<L-1; ++j)
        {
            if(pre[i] == post[j])
            {
                longest_true_str = pre[i];
                longest_true_len = pre[i].length();
            }
        }
    }

    delete []pre;
    delete []post;

    if(!longest_true_len) return "empty";
    else return longest_true_str;
}




int main()
{
    myString mystr;
    string mstr, s;
    int t;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        cin>>mstr;
        mystr.SetVal(mstr);
        s=mystr.matched_Prefix_Postfix();
        cout<<s<<endl;
    }

    return 0;
}