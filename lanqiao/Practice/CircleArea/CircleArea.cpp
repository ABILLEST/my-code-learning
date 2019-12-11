#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

static double PI=atan(1.0)*4;

double CircleArea(int r)
{
    return (PI * r*r);
}

int main()
{
    int r;

    cin>>r;
    double ans = CircleArea(r);
    cout<<fixed<<setprecision(7)<<ans<<endl;

    return 0;
}