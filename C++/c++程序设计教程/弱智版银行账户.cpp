#include <iostream>
#include <string.h>
using namespace std;

class CAccount
{
protected:
	long account;
	char name[10];
	float balance;
public:
	CAccount(long a,char* n,float b):account(a),balance(b){strcpy(name,n);}
	void deposit(float m);
	virtual void withdraw(float m);
	void check();
};

class CCreditcard : public CAccount
{
	float limit;
public:
	CCreditcard(long a,char* n,float b,float l):CAccount(a,n,b),limit(l){}
	virtual void withdraw(float m);
};

void CAccount::deposit(float m)
{
	balance += m;
	cout<<"saving ok!"<<endl;
}

void CAccount::withdraw(float m)
{
	if(m>balance)
	{
		cout<<"sorry! over balance!"<<endl;
	}
	else
	{
		balance-=m;
		cout<<"withdraw ok!"<<endl;
	}
}

void CCreditcard::withdraw(float m)
{
	if(m>balance)
	{
		if(m-balance>limit)
			cout<<"sorry! over limit!"<<endl;
		else
		{
			limit -= m-balance;
			balance -= m;
			cout<<"withdraw ok!"<<endl;
		}
	}
	else
	{
		balance-=m;
		cout<<"withdraw ok!"<<endl;
	}	
}

void CAccount::check()
{
	cout<<"balance is "<<balance<<endl;
}

//ÈõÖÇ°æÒøÐÐÕË»§ 
int main()
{
	long account;
	char name[10];
	float balance,w,d,tou;
	
	
	cin>>account >>name >>balance;
	CAccount a(account,name,balance);
	a.check();
	cin>>d;
	a.deposit(d);
	a.check();
	cin>>w;
	a.withdraw(w);
	a.check();
	
	cin>>account >>name >>balance>>tou;
	CCreditcard c(account,name,balance,tou);
	c.check();
	cin>>d;
	c.deposit(d);
	c.check();
	cin>>w;
	c.withdraw(w);
	c.check();
}
