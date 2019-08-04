#include<iostream>
using namespace std;

//Pointer Encrypt
int main()
{
	int t;
	char c;
	char m[100],e[100],k[100];
	char *q=NULL,*p=NULL,*s=NULL;
	cin>>t;
	

	while(t--)
	{
		cin>>m>>k;
		//for(q=k;*q!='\0';q++) *q -= '0';
		s=e;
		for(p=m;*p!='\0';)
			for(q=k;*q!='\0';q++)
			{
				if(*p>='a'&&*p<='z')
						*s = (*p-'a'+*q-'0')%26 + 'a';
				else if(*p>='A'&&*p<='Z')
						*s = (*p-'A'+*q-'0')%26 + 'A';
				p++,s++;
			}
		*s='\0';
					
		cout<<e<<endl;
	}
	return 0;
}
