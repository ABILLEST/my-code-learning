#include <iostream>
#include <stack>
#include <string>
using namespace std;




int main()
{
	stack <char>  s;
	string str;
	int len;
	int t;
	
	cin>>t;
	for(int i=0; i<t; ++i)
	{
		cin>>str;
		len = str.length();
		for(int j=0; j<len; ++j)
		{
			s.push(str[j]);
		}
		
		for(int j=0; j<len; ++j)
		{
			if(!s.empty())
			{
				char e = s.top();
				s.pop();
				cout<<e;
			}
		}
		cout<<endl;
	}
	
	return 0;
}
