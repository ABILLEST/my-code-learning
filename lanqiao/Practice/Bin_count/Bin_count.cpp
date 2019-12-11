#include<iostream>
using namespace std;

//函数仅供理解，参数穿越会带来不必要的开销
int bitCount_one(long x)
{
    int n=0;
    while (x)
    {
        x &= x-1;
        ++n;
    }
    return n;
}

int main()
{
    long L,R;
    long long count=0;
    cin>>L>>R;

    for(int i=L; i<=R; ++i)
    {
        count+=bitCount_one(i);
    }

    cout<<count<<endl;

    return 0;
}