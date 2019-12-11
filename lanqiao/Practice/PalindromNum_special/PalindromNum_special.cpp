#include <iostream>
using namespace std;

int main()
{
	int i,n,num;
	int sum,reversal;
    
    cin>>n;
    for(i=10000;i<1000000;i++)
    {
        num=i;                                    //遍历每个五位与六位十进制数 
        sum=0,reversal=0;                         //每位数字之和与其回文数均赋初值0 
        while(num>0)
        {
            reversal=reversal*10+num%10;	      //求解回文数 
            sum+=(num%10);                        //数位分离，从低位开始累加 
            num/=10;
        }
        if(sum==n && reversal==i)            //一个数的各位数字之和等于n且是回文数，则输出 
            cout<<i<<endl;
    }
	
	return 0;
}