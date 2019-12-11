#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    long long n;
    cin>>n;

    {
        if(n%2==0)
            cout<<(n+1)*(n/2)<<endl;
            //printf("%I64d\n",(n+1)*(n/2));
        else
            cout<<((n+1)/2)*n<<endl;
            //printf("%I64d\n",((n+1)/2)*n);
    }

    return 0;
}