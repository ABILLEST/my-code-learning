#include <iostream>
#include <string>
using namespace std;

class Member //普通会员类
{   
protected:
	int id, bonus;
	string name;
public:
	Member(){}
	Member(string,int,int);
	virtual void print();
	virtual void Add(int);
	virtual int Exchange(int);
};


class VIP : public Member //贵宾会员类
{  
private:
	int addRate, exchangeRate;
public:
	VIP(){}
	VIP(string,int,int,int,int);
	void print();
	void Add(int);
	int Exchange(int);
};

//member class definition
Member::Member(string n,int _id,int _bonus)
{
	id = _id;
	name = n;
	bonus = _bonus;
}

void Member::print()
{
	cout<<"普通会员"<<id<<"--"<<name<<"--"<<bonus<<endl;
}

void Member::Add(int amount)
{
	bonus += amount;
}

int Member::Exchange(int exchange_require_bonus)
{
	int money;
	int exchange_amount_money = exchange_require_bonus / 100;
	int exchange_amount_bonus = exchange_amount_money * 100;
	if(bonus>exchange_amount_bonus){
		bonus -= exchange_amount_bonus;
		money += exchange_amount_money;
	}
	else ;
	
	return money;
}

//VIP class definition
VIP::VIP(string n,int _id,int _bonus,int _addRate,int _exchangeRate):Member(n,_id,_bonus)
{
	addRate = _addRate;
	exchangeRate = _exchangeRate;
}

void VIP::print()
{
	cout<<"贵宾会员"<<id<<"--"<<name<<"--"<<bonus<<endl;
}

void VIP::Add(int amount)
{
	bonus += amount * addRate;
}

int VIP::Exchange(int exchange_require_bonus)
{
	int money;
	int exchange_amount_money = exchange_require_bonus / exchangeRate;
	int exchange_amount_bonus = exchange_amount_money * exchangeRate;
	if(bonus>exchange_amount_bonus){
		bonus -= exchange_amount_bonus;
		money += exchange_amount_money;
	}
	else ;
	
	return money;
}

int main()
{

	Member * pm; //创建一个基类对象指针
	string name;
	int id,bonus,amount,exchange_bonus,addRate,exchangeRate;
	
	//输入数据，创建普通会员对象mm
	cin>>id>>name>>bonus
		>>amount>>exchange_bonus;
	Member mm(name,id,bonus);
	//使用指针pm执行以下操作：
	//1、pm指向普通会员对象mm
	pm = &mm;
	//2、输入数据，通过pm执行积分累加和积分兑换
	pm->Add(amount);
	pm->Exchange(exchange_bonus);
	//3、通过pm调用打印方法输出
	pm->print();

	//输入数据，创建贵宾会员对象vv
	cin>>id>>name>>bonus>>addRate>>exchangeRate
		>>amount>>exchange_bonus;
	VIP vv(name,id,bonus,addRate,exchangeRate);
	//使用指针pm执行以下操作：
	//1、pm指向贵宾会员对象vv
	pm = &vv;
	//2、输入数据，通过pm执行积分累加和积分兑换
	pm->Add(amount);
	pm->Exchange(exchange_bonus);
	//3、通过pm调用打印方法输出
	pm->print();

	return 0;

}
