#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	long long n,a,x=0;
    bool positive;
    cin>>n;
    
    if(n<0)
    {
        cout<<0<<endl;
        return 0;
    }

    a = sqrt(n);
    x=pow(a,2);
    while(x<n)
    {
        ++a;
        x=pow(a,2);
    }

    cout<<x<<endl;
	return 0;
}