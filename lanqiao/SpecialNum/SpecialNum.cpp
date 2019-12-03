#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int i;
    for(i=100;i<1000;i++)
    {
        int g=i%10, s=i/10%10, b=i/100;
        if(i==g*g*g + s*s*s + b*b*b)
            cout<<i<<endl;
    }
	return 0;
}