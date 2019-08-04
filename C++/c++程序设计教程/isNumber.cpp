#include<iostream>
#include<stdlib.h>
using namespace std;

char str[100];
//isNumber function
int main()
{
	int isNumber(char *s);
	
	int t;
	
	char *p=NULL;
	cin>>t;
	
	while(t--)
	{
		cin>>str;
		cout<<isNumber(p)<<endl;
	}
	return 0;
 }
 
int isNumber(char *p)
{
	str[0]=='-' ? p=str+1 : p=str;
	for(; *p!='\0'; p++)
		{
			if((*p-'0')>=0&&(*p-'0')<=9);
			else return -1; 
		}
		return atoi(str);
}
