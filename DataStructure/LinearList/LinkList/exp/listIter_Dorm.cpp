#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#define ok 0
#define error -1
using namespace std;
 
void outint(int n){cout<<n<<" ";}
int main()
{
    list<int> L1,L2;
    list<string> L3;
    list<int>::iterator p1=L1.begin(),p2=L2.begin();
    list<string>::iterator p3=L3.begin();
    for(int i=0;i<20;i++)
    {
        L1.insert(p1,101+i);
        p1++;
    }
    L1.sort();
    int n,k;
    string temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>temp;
        cin>>k;
        for(p1=L1.begin();p1!=L1.end();p1++)
        {
            if(*p1==k)
            {
                L1.erase(p1);
                L2.insert(L2.begin(),k);
                L2.sort();
                for(p2=L2.begin(),p3=L3.begin();p2!=L2.end();p2++,p3++)
                {
                    if(*p2==k)
                        L3.insert(p3,temp);
                }
                break;
            }
        }
    }
    string c1,c2;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>c1;
        if(c1=="assign")
        {
            cin>>c2;
            k=*L1.begin();
            L2.insert(L2.begin(),k);
            L2.sort();
            for(p2=L2.begin(),p3=L3.begin();p2!=L2.end();p2++,p3++)
                {
                    if(*p2==k){
                        L3.insert(p3,c2);
                        break;
                    }
                }
            L1.erase(L1.begin());
        }
        if(c1=="return")
        {
            cin>>k;
            for(p2=L2.begin(),p3=L3.begin();p2!=L2.end();p2++,p3++)
                {
                    if(*p2==k)
                    {
                        L1.insert(L1.end(),k);
                        L2.erase(p2);
                        L3.erase(p3);
                        break;
                    }
                }
        }
        int flag=1;
        if(c1=="display_used")
        {
            flag=1;
            for(p2=L2.begin(),p3=L3.begin();p2!=L2.end();p2++,p3++)
            {
                if(flag==1)
                {
                    cout<<*p3<<"("<<*p2<<")";
                    flag=0;
                }
                else
                    cout<<"-"<<*p3<<"("<<*p2<<")";
            }
            cout<<endl;
        }
        if(c1=="display_free")
        {
            flag=1;
            for(p1=L1.begin();p1!=L1.end();p1++)
            {
                if(flag==1)
                {
                    cout<<*p1;
                    flag=0;
                }
                else
                    cout<<"-"<<*p1;
            }
            cout<<endl;
        }
    }
}
