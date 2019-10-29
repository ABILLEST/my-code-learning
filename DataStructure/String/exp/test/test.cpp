#include<iostream>
#include<string>
using namespace std;

string matched_Prefix_Postfix(string str)
{
	int L=str.length();
	string a;
	string b;
	string temp="";
	int size=0;
	for(int i=1;i<L;i++)    //从短到长的循环 
	{
		for(int j=0;j<i;j++)   //赋值的循环 
		{
			a+=str[j];
			b.insert(b.begin(),str[L-j-1]);
		}
		if(a==b)
		{
			temp=a; 
		}
		a.clear();
		b.clear();
	}
	size=temp.length();
	if(!size)
	{
		return "empty";
	}
	else
	{
		return temp;
	}
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		cout<<matched_Prefix_Postfix(str)<<endl;
	}
	return 0;
}





