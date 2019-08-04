#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//4ms 8.1MB
//按位推算数字位置
class Solution {
public:
    int findNthDigit(int n) {
        long long level=1;		//数量级
        long long width=1;
        long long cnt=0;		//位数积累（前一位所有数字的组成数字的个数） 
        int num, pos, left;
        
		//确定n所对应的数量级和宽度 
        while(cnt+9*level*width < n )	
        {
            cnt += (9*level*width);
            level*=10;
            ++width;
        }

        if((n-cnt)%width == 0)		//n指向数字的最后一位
        {
            num = level+(n-cnt)/width-1;	//(n-cnt)/width相当于当前数量级的偏移量
            left = width;
            pos = width-left+1;
        }
        else
        {
            num = level+(n-cnt)/width;
            left = (n-cnt)%width;
            pos = width-left+1;		//计算指向数字的位数
        }
        
    	//取数
        while(pos>1)	 //例如：pos==1代表左边数第一位
        {
            num/=10;
            --pos;
        }
    	// cout <<"ret="<<num%10<<endl;
        return (num%10);
    }
};

//8ms 8.5MB
/*
class Solution {
public:
	int findNthDigit(int n)
	{
	    if (n < 10)  return n;//step 1
	    
	    long long length = 0, cnt = 9, i = 1;
	    
	    for (; length + cnt*i < n; ++i){//step 2
	        length += cnt * i;
	        cnt *= 10;
	    }//step 3
	    
	    long long num = pow(10, i-1) + (n-length-1)/i;
	    long long index = (n-length-1)%i;
	    return to_string(num)[index]-'0';
	}
};
*/

int main()
{
	int n;
	cin>>n;
	Solution s;
	cout<<s.findNthDigit(n)<<endl;
}
