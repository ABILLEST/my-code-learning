#include <iostream>
#include <string.h>
using namespace std;

int succ=0;

class CTelNumber
{
	char *num;
public:
	CTelNumber();
	~CTelNumber();
	CTelNumber(CTelNumber &c);
	void print();
};

CTelNumber::CTelNumber()
{
	num = new char[100];
	cin>>num;
}

CTelNumber::~CTelNumber()
{
	num[0] = '\0';
	delete num;
}

CTelNumber::CTelNumber(CTelNumber& c)
{
	char *p=NULL;
	num = new char[strlen(c.num)+2];
	if(strlen(c.num)==7)
	{
		if(c.num[0]=='2'||c.num[0]=='3'||c.num[0]=='4')
	{
		num[0] = '8';
		strcpy(num+1,c.num);
		succ=1;
	}
		else if(c.num[0]=='5'||c.num[0]=='6'||c.num[0]=='7'||c.num[0]=='8')
		{
			num[0] = '2';
			strcpy(num+1,c.num);
			succ=1;
		}
		else succ=0;
	}
	else succ=0;
	for(p=num;*p!='\0';p++)
		if(*p<'0'||*p>'9')
			succ=0;
}

void CTelNumber::print()
{
	if(succ)
		cout<<num<<endl;
	else
		cout<<"Illegal phone number"<<endl;
}


//µç»°ºÅÂëÉýÎ»
int main()
{
	int t, n;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		CTelNumber c1;
		CTelNumber c2(c1);
		c2.print();
	}
	return 0;
}
