#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
	int balance;
	double rate;
	long number;
	char type;
public:
	Account(int b,long num,char t):balance(b),number(num),type(t),rate(0.005){};
	Account(Account& a);
	void Calculate();
	void display();
};

Account::Account(Account& a)
{
	balance = a.balance;
	type = a.type;
	
	rate = 0.015;
	number = a.number+50000000;
}

void Account::Calculate()
{
	balance += balance*rate;
	cout<<"Account="<<number<<"--sum="<<balance<<endl;
}

void Account::display()
{
	cout<<"Account="<<number;
	if(type=='P')
		cout<<"--Person--";
	else if(type=='E')
		cout<<"--Enterprise--";
	cout<<"sum="<<balance<<"--rate="<<rate<<endl;
}


int main()
{
	int t;
	long num;
	char type,op1,op2;
	int balance;
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>num>>type>>balance;
		Account c(balance,num,type);
		Account f(c);
		cin>>op1>>op2;
		if(op1=='C')
			c.Calculate();
		else if(op1=='P')
			c.display();
		if(op2=='C')
			f.Calculate();
		else if(op2=='P')
			f.display();
	}
}
