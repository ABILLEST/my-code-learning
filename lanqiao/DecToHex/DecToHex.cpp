#include<iostream>
using namespace std;
#include<cstdlib>

int main()
{
    long long n;//防止数过大
    int m;
    int k = 0;
    char str[100];

    cin >> n;

    if(0<=n && n<=9)
    {
        cout<<n;
		return 1;
    }

    while (n>0)
    {
        m = n % 16;		//保存超出16的整数倍的部分
        n /= 16;
        //转换为字符串
        if (m > 9)
            str[k++] = 'A' + m-10;
        else
            str[k++] = '0' + m;
    }

	//反向输出字符串
    for (int i = k - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    return 0;
}