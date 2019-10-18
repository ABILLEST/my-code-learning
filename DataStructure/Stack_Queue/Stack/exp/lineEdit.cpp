#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	string str;
	char c;
	int len;
	int t;
	
	cin>>t;
	getchar();
	for(int i=0; i<t; ++i)
	{
		stack <char>  s,as;
		cin>>str;
		int k=0;
		while(true)
		{
			c = str[k];
			if(c=='\0') break;
			if(c=='#')
			{
				if(!s.empty())
					s.pop();
			}
			else s.push(c);
			
			++k;
		}
		
		int j;
		len = s.size();
		if(0==len)
		{
			cout<<"NULL"<<endl;
			continue;
		}
		
		while(!s.empty())
		{
			as.push(s.top());
			s.pop();
		}
		
		while(!as.empty())
		{
			char e = as.top();
			cout<<e;
			as.pop();
		}
		cout<<endl;
	}
	
	return 0;
}
