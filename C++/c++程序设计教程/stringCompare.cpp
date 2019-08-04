#include<iostream>
using namespace std;

//string compare
char S[100],T[100];
int nsb=0,ntb=0;

int main()
{
	int strCompare(char *sp,char *tp);
	
	int t,result;
	char *sp=S,*tp=T;
	cin>>t;
	
	while(t--)
	{
		nsb=0,ntb=0;
		cin>>S>>T;
		result = strCompare(sp,tp);
		cout<<result<<endl;
	}
	return 0;
}

int strCompare(char *sp,char *tp)
{
	for(;;sp++,tp++)
	{
		if(*tp=='\0'&&*sp!='\0') return 1;
		if(*sp=='\0'&&*tp!='\0') return -1;
		if(*sp=='\0'&&*tp=='\0') break;
		
		if(*sp>*tp) nsb++;
		else if(*sp<*tp) ntb++;
	}
	
	if(nsb>ntb) return 1;
	else if(nsb<ntb) return -1;
	else if(nsb==ntb) return 0;
}
