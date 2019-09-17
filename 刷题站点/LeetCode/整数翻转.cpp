#include <iostream>
using namespace std;

class Solution
{
	public:
		int reverse(int x)
		{
			int result=0, pop =0;

			while(x!=0)
			{
				pop = x%10;
				//Òç³öÅĞ¶Ï
				if(result > INT_MAX/10 || (result == INT_MAX / 10 && pop > 7)) return 0;
				if(result < INT_MIN/10 || (result == INT_MIN / 10 && pop < -8)) return 0;
				result = result*10 + pop;
				x /= 10;
			}
			return result;
		}
};

int main()
{
	Solution s;
	cout<<s.reverse(-121)<<endl;
}
