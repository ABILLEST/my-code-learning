#include <iostream>
#include <string.h>
using namespace std;

/*
    注意类型；因为相当于都在模10007下运算，所以一边求余一边计算Fibonacci结果正确而且会比较快
*/

long long Fibonacci(long long n,long long a[])
{
    a[0]=1; a[1]=1; a[2]=1;
    for(long long i=3;i<=n;++i)
    {
        a[i] = (a[i-1]+a[i-2]) % 10007;
    }

    return a[n];
}

int main()
{
    long long n;
    cin>>n;
    long long *Fn = new long long[n+1];
    cout<<Fibonacci(n,Fn)<<endl;

    return 0;
}
