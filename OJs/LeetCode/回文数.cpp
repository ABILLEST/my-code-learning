#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/*
	回文数特点：
		1.
		2. 
*/

/*
	方法1：转字符串处理 
	方法2：翻转全部（处理时间长，而且要处理溢出） 
	方法2：翻转一半
	方法3：两头逐位比较
	方法4：正反方向读到字符串里比较 
*/ 

class Solution
{
	public:
		//转String 
		bool isPalindrome(int x)
		{
			string originStr = to_string(x);
			string reversedStr = to_string(x);
			reverse(reversedStr.begin(), reversedStr.end());
			if(originStr == reversedStr)
				return true;
			else return false;
		}
		
		//翻转整个数字 
		bool isPalindrome_2(int x)
		{
			int reversed=0, pop =0, _x=x;

			if(x<0) return false;
			while(x>0)
			{
				pop = x%10;
				//溢出判断
				if(reversed > INT_MAX/10 || (reversed == INT_MAX / 10 && pop > 7)) return 0;
				if(reversed < INT_MIN/10 || (reversed == INT_MIN / 10 && pop < -8)) return 0;
				reversed = reversed*10 + pop;
				x /= 10;
			}
			if(reversed==_x) return true;
			else return false;
		}
		
		//翻转数字的一半 
		bool isPalindrome_3(int x)
		{
			
		}
};

int main()
{
	Solution s;
	int input;
	while(1)
	{
		cout<<"Enter number:";
		cin>>input;
		if(s.isPalindrome_2(input))
			cout<<"true\n"<<endl;
		else cout<<"false\n"<<endl;
	}

}
