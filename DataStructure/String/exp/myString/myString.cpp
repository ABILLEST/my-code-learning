#include <iostream>
#include <string>
using namespace std;

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
    while(i<len-1)
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
    int i=pos, j=0;
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
    int *next = new int[L];
    GetNext(p, next);
    for(int i=0; i<L; ++i)
        cout<<next[i]<<' ';
    cout<<endl;
    int v = -1;
    v = KMPFind(p, pos, next);
    
    delete []next;

    return v;
}




int main()
{
    myString mystr;
    string str;
    int t;
    cin>>t;

    for(int i=0; i<t; ++i)
    {
        cin>>str;
        mystr.SetVal(str);
        cin>>str;
        int pos =mystr.KMPFindSubStr(str, 0);
        cout<<pos<<endl;
    }

    return 0;
}