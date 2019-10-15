#include <iostream>
#include <stack>
#include <string>
using namespace std;

#define ok 1
#define error -1

bool Match(char chL, char chR);
int main()
{
	string str;
	int flag;
	int t;
	
	cin>>t;
	for(int i=0; i<t; ++i)
	{
		stack <char>  s;
		char ch;
		cin>>str;
		
		for(int i=0; str[i]!='\0'; ++i)
		{
			switch(str[i])
			{
				case '(': 
				case '[':
				case '{':
					s.push(str[i]); break;
				case ')':
				case ']':
				case '}':
					if(s.empty()){
						cout<<"error"<<endl;
						flag = error;
						break;
					}
					else{
						ch = s.top();
						if(Match(ch,str[i])){
							ch = s.top();
							s.pop();
						}
						else{
							cout<<"error"<<endl;
							flag = error;
						}
					}
					break;
				default:
					break;
			}
			if(flag==error)
				break;
			
			
		}
		if(flag==error)
			continue;
		if(s.empty())
		{
			cout<<"ok"<<endl;
		}
		else cout<<"error"<<endl;
	}
	
	return 0;
}

bool Match(char chL, char chR)
{
	if(chL=='(')
	{
		if(chR==')') return true;
		else return false;
	}
	else if(chL=='[')
	{
		if(chR==']') return true;
		else return false;
	}
	else if(chL=='{')
	{
		if(chR=='}') return true;
		else return false;
	}
	else{
		cerr<<"error"<<endl;
		return false;
	}
}
