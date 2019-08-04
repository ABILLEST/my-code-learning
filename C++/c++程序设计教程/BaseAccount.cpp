#include <iostream>
#include <string>
using namespace std;

class BaseAccount
{
protected:
	string name,account;
	int balance;
public:
	BaseAccount(string _n,string _a,int _b):name(_n),account(_a),balance(_b){}
	virtual void deposit(double amount);
	virtual void withdraw(double amount);	//不能透支 
	virtual void display();
};

class BasePlus : public BaseAccount
{
	int limit;			//默认5000 
	int limit_sum;
public:
	BasePlus(string _n,string _a,int _b):BaseAccount(_n,_a,_b){limit=5000;limit_sum=0;}
	virtual void deposit(double amount);
	virtual void withdraw(double amount);
	virtual void display();
};


void BaseAccount::deposit(double amount)
{
	balance += amount;
}

void BaseAccount::withdraw(double amount)
{
	if(balance>=amount)
		balance -= amount;
	else cout<<"insufficient"<<endl;
}

void BaseAccount::display()
{
	cout<<name<<" "<<account<<" Balance:"<<balance<<endl;
}

void BasePlus::deposit(double amount)
{
	if(limit_sum)
	{
		if(amount>=limit_sum)		//够还 
		{
			amount -= limit_sum;
			limit_sum = 0;
			balance += amount;
		}
		else limit_sum -= amount;
	}
	else balance += amount;
}

void BasePlus::withdraw(double amount)
{
	//透支 
	if(balance<amount)
	{
		if(amount-balance<limit)
		{
			limit_sum += amount-balance;
			balance=0;
		}
		else cout<<"insufficient"<<endl;
	}
	else balance -= amount;
}

void BasePlus::display()
{
	cout<<name<<" "<<account
		<<" Balance:"<<balance<<" limit_sum:"<<limit_sum<<endl;
}

int main()
{
	int t;
	string name,account;
	int balance,de1,wt1,de2,wt2;
	cin>>t;
	
	BaseAccount *p;
	for(int i=0;i<t;i++)
	{
		cin>>name>>account>>balance>>de1>>wt1>>de2>>wt2;
		if(account[1]=='A')
		{
			BaseAccount ba(name,account,balance);
			p = &ba;
			p->deposit(de1);
			p->withdraw(wt1);
			p->deposit(de2);
			p->withdraw(wt2);
			p->display();
		}
		else if(account[1]=='P')
		{
			BasePlus bp(name,account,balance);
			p = &bp;
			p->deposit(de1);
			p->withdraw(wt1);
			p->deposit(de2);
			p->withdraw(wt2);
			p->display();
		}
	}
}





