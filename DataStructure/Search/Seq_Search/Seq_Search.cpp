#include <iostream>
using namespace std;

int main()
{
    int t,n,searchNum;
    
    cin>>n;
    int * nums = new int[n];
    for(int i=1; i<=n; ++i)
    {
        cin>>nums[i];
    }

    cin>>t;
    for(int i=0; i<t; ++i)
    {
        cin>>searchNum;
        nums[0] = searchNum;
        int j=0;
        for(j=n; nums[j]!=searchNum; --j) ;
        if(j)
            cout<<j<<endl;
        else cout<<"error"<<endl;
    }

    return 0;
    
}
