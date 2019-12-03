#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int main()
{
    string sixt;
    cin>>sixt;

    int len=sixt.length();          //计算输入字符的长度
    long long ten=0;                //这里一定要注意数据类型！！题目要求小于8字符，所以这里用long long，否则报错！
    
	for(int i=len-1;i>=0;i--)       //根据十六进制转十进制的方法，从后向前
    {
        if(isdigit(sixt[i]))           //是否为字符0~9
            {
               ten+=(sixt[i]-'0')*pow(16,len-1-i);           //是的话则将字符0~9转换为数字0~9再计算
            }
        else
            {
               ten+=(sixt[i]-'A'+10)*pow(16,len-1-i);   //不是则将字符A~F转换为对应的数字10~15
            }
    }
    cout<<ten;
    return 0;
}