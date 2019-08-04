#include <iostream>
#include <string.h>
using namespace std;

class CPeople
{
protected:
	char id[20];
	char name[10];
public:
	CPeople(){};
};

class CInternetUser : virtual public CPeople
{
protected:
	char password[20];
public:
	void registerUser(char* i,char* n,char* pw);
	int login(char* i,char* pw);
};

class CBankCustomer : virtual public CPeople
{
protected:
	double balance;
public:
	CBankCustomer(){};
	void openAccount(char* n,char *i);
	virtual int deposit(double amount);
	virtual int withdraw(double amount);
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer
{
protected:
	double balance;
	double lastdayBalance,todayGain;
	double interest,lastdayInterest;
public:
	CInternetBankCustomer(){balance=0;}
	virtual int deposit(double amount);
	virtual int withdraw(double amount);
	void setInterest(double in);
	void calculateProfit();
	int login(char* i,char* pw);
	void print();
};

void CInternetUser::registerUser(char* n,char* i,char* pw)
{
	strcpy(id,i);
	strcpy(name,n);
	strcpy(password,pw);
}

int CInternetUser::login(char* i,char* pw)
{
	if(strcmp(id,i)){
		if(strcmp(password,pw)){
			return 1;
		}
	}
	return 0;
}

void CBankCustomer::openAccount(char* n,char *i)
{
	strcpy(name,n);
	strcpy(id,i);
}

int CBankCustomer::deposit(double amount)
{
	balance+=amount;
}

int CBankCustomer::withdraw(double amount)
{
	if(balance<amount)
		return 0;
	else{
		balance-=amount;
		return 1;
	}
}

int CInternetBankCustomer::deposit(double amount)
{
	if(CBankCustomer::balance<amount)
		return 0;
	else{
		CBankCustomer::balance -= amount;
		this->balance += amount;
		return 1;
	}
}

int CInternetBankCustomer::withdraw(double amount)
{
	if(this->balance<amount)
		return 0;
	else{
		CBankCustomer::balance += amount;
		this->balance -= amount;
		return 1;
	}
}

void CInternetBankCustomer::setInterest(double in)
{
	interest = in;
}

void CInternetBankCustomer::calculateProfit()
{
	todayGain = (lastdayBalance/10000)*lastdayInterest;
	this->balance += todayGain;
	lastdayBalance = this->balance;
	lastdayInterest = interest;
}

int CInternetBankCustomer::login(char* i,char* pw)
{
	if(!strcmp(CInternetUser::id,i)){
		if(!strcmp(CInternetUser::password,pw)){
			return 1;
		}
	}		
	return 0;
}

void CInternetBankCustomer::print()
{
	cout<<"Name: "<<name<<" ID: "<<id<<endl
		<<"Bank balance: "<<CBankCustomer::balance<<endl
		<<"Internet bank balance: "<<CInternetBankCustomer::balance<<endl<<endl;
}

//Internet Bank Customer Account 
int main()
{
	int t, no_of_days, i;
	char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
	double money, interest;
	char op_code;
	
	//输入测试案例数t
	cin >> t;
	while (t--)
	{
		//输入互联网用户注册时的用户名,id,登陆密码
		cin >> i_xm >> i_id >> i_mm;
		//输入银行开户用户名,id
		cin >> b_xm >> b_id;
		//输入互联网用户登陆时的id,登陆密码
		cin >> ib_id >> ib_mm;
		CInternetBankCustomer ib_user;
		ib_user.registerUser(i_xm, i_id, i_mm);
		ib_user.openAccount(b_xm, b_id);
		if (ib_user.login(ib_id, ib_mm) == 0)  //互联网用户登陆,若id与密码不符;以及银行开户姓名和id与互联网开户姓名和id不同
		{
		cout << "Password or ID incorrect"<<endl;
		continue;
		}
		//输入天数
		cin >> no_of_days;
		for (i=0; i < no_of_days; i++)
		{
			//输入操作代码, 金额, 当日万元收益
			cin >> op_code >> money >> interest;
		  	switch (op_code)
		 	{
			    case 'S':  //从银行向互联网金融帐户存入
			    case 's':
			       if (ib_user.deposit(money) == 0)
			       {
			          cout << "Bank balance not enough" << endl;
			          continue;
			       }
			       break;
			       
				case 'T': //从互联网金融转入银行帐户
				case 't':
					if (ib_user.withdraw(money) == 0)
					{
						cout << "Internet bank balance not enough" << endl;
						continue;
					}
					break;
				
				case 'D': //直接向银行帐户存款
				case 'd':
					ib_user.CBankCustomer::deposit(money);
					break;
					
				case 'W': //直接从银行帐户取款
				case 'w':
					if (ib_user.CBankCustomer::withdraw(money) == 0)
					{
						cout << "Bank balance not enough" << endl;
						continue;
					}
					break;
				default:
					cout << "Illegal input" << endl;
					continue;
		 	}
			ib_user.setInterest(interest);
			ib_user.calculateProfit();
			//输出用户名,id 
			//输出银行余额
			//输出互联网金融账户余额
			ib_user.print();
		}
	}
}

/*
5
name id password
name id
id password
8
t 10000 1.5
s 100000 1.6
d 150000 1.4
D 100000 1.44
S 100000 1.33
s 50000 1.34
T 20000 1.44
w 50000 1.55
name id password
id name
id password
name id password
id password
id password
name id password
name id
name password
name id password
name id
password id
*/
