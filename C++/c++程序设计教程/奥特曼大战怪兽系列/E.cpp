#include <iostream>
using namespace std;

class Ultraman;
class Monster;
class Angel;
//这里开始写类的界面代码
//奥特曼类的界面
class Ultraman
{
private:
	int rank,exp,HP,HP_limit,damage,money;
	Angel angel;
public:
	Ultraman(){}
	Ultraman(int);
	int getRank();
	int getHp();
	int getExp();
	int getDamage();
	int getMoney();
	void display();
	void escape();
	void attack(Monster&);
	void attacked(int);
	void restore();
	bool win(Monster&);
	void upgrade();
	void operator ++ ();
	void operator -- ();
	bool operator < (Monster&);
	bool operator == (Monster&);
	friend ostream& operator << (ostream& out, Ultraman& utm);
};

//怪兽类的界面
class Monster
{
protected:
	int rank,exp,HP,HP_limit,damage,money;
	Angel angel;
public:
	Monster(){}
	Monster(int);
	int getRank();
	int getHp();
	int getExp();
	int getDamage();
	int getMoney();
	void attack(Ultraman&);
	virtual void attacked(int);
	virtual void fightback(Ultraman&);
	virtual void display();
	virtual void lose();
};

//普通型怪兽 
class NMonster : public Monster
{
public:
	NMonster(){}
	NMonster(int);
};

//攻击型怪兽 
class AMonster : public Monster
{
public:
	AMonster(){}
	AMonster(int);
};

//防御型怪兽 
class DMonster : public Monster
{
public:
	DMonster(){}
	DMonster(int);
};

//肉鸡型怪兽 
class SMonster : public Monster
{
public:
	SMonster(){}
	SMonster(int);
};

class Angel
{
private:
	int rank,damage,money,exp;
public:
	Angel(){}
	Angel(int);
	int getExp();
	int getMoney();
};

class Monster_Boss : public Monster
{
private:
	int count;
public:
	Monster_Boss();
	void XP(Ultraman&);
	virtual void attack(Ultraman&);
	virtual void attacked(int);
	virtual void fightback(Ultraman&);
	void lose();
	virtual void display();
};

//这里开始写类的实现代码
//奥特曼类的实现
Ultraman::Ultraman(int r)
{
	rank = r;
	HP_limit = r*10;
	HP = HP_limit;
	damage = r*3;
	money = r*10;
	exp=0;
}

int Ultraman::getDamage()
{
	return damage;
}

int Ultraman::getExp()
{
	return exp;
}

int Ultraman::getHp()
{
	return HP;
}

int Ultraman::getMoney()
{
	return money;
}

int Ultraman::getRank()
{
	return rank;
}

void Ultraman::escape()
{
	//hp<=10
	money = 0;
	//lose
}

void Ultraman::attack(Monster& m)
{
	m.attacked(damage);
}

void Ultraman::attacked(int damage_mst)
{
	HP -= damage_mst/2;
}

void Ultraman::restore()
{
	if(10<HP && HP<0.5*HP_limit)
	{
		while(money>=10)
		{
			if(HP==HP_limit)
				break;
			HP++;
			money-=10;
		}
	}
}

bool Ultraman::win(Monster& m)
{
	if(m.getHp()<=0)	//如果奥特曼没死 
	{
		money += m.getMoney() + m.angel.getMoney();
		exp += m.getExp() + m.angel.getExp();
		return true;
	}
	return false;
}

void Ultraman::upgrade()
{
	while(exp>=rank*10)
	{
		exp -= rank*10;
		rank++;
		HP_limit = rank*10;
		HP = HP_limit;
		damage = rank*3;
	}
}

void Ultraman::display()
{
	cout<<"奥特曼状态(rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;
}

void Ultraman::operator ++()
{
	rank *= 2;
	HP_limit = rank*10;
	HP = HP_limit;
	damage = rank*3;
	exp *= 2;
	money *= 2;
}

void Ultraman::operator --()
{
	HP /= 2;
	damage /=2;
	exp /= 2;
	money /= 2;
}

bool Ultraman::operator <(Monster& m)
{
	if(m.getRank()<this->rank)
	{
		HP += m.getHp()*0.5;
		damage += m.getDamage()*0.5;
		money += m.getMoney()*0.5;
		exp += m.getExp()*0.5;
		return true;
	}
	else return false;
}

bool Ultraman::operator ==(Monster& m)
{
	if(m.getRank()==this->rank)
	{
		HP += m.getHp();
		damage += m.getDamage();
		money += m.getMoney();
		exp += m.getExp();
	}
	else return false;
}

//怪兽类的实现
Monster::Monster(int r)
{
	rank = r;
	HP_limit = r*20;
	HP = HP_limit;
	damage = r*2;
	money = r*10;
	exp=r*10;
}

int Monster::getDamage()
{
	return damage;
}

int Monster::getExp()
{
	return exp;
}

int Monster::getHp()
{
	return HP;
}

int Monster::getMoney()
{
	return money;
}

int Monster::getRank()
{
	return rank;
}

void Monster::attack(Ultraman& utm)
{
	utm.attacked(damage);
}

void Monster::attacked(int damage_utm)
{
	HP -= damage_utm;
}

void Monster::fightback(Ultraman& utm)
{
	utm.attacked(damage);
}

void Monster::lose()
{
	cout<<"Boss!Help!"<<endl;
}

void Monster::display()
{
	cout<<"怪兽状态(rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;
}


NMonster::NMonster(int r)
{
	rank = r;
	HP_limit = r*10;
	HP = HP_limit;
	damage = r*2;
	money = r*10;
	exp=r*10;
}

AMonster::AMonster(int r)
{
	rank = r;
	HP_limit = r*5;
	HP = HP_limit;
	damage = r*4;
	money = r*10;
	exp=r*10;
}

DMonster::DMonster(int r)
{
	rank = r;
	HP_limit = r*20;
	HP = HP_limit;
	damage = r*1;
	money = r*10;
	exp=r*10;
}

SMonster::SMonster(int r)
{
	rank = r;
	HP_limit = r*10;
	HP = HP_limit;
	damage = r*1;
	money = r*20;
	exp=r*20;
}

Angel::Angel(int r)
{
	rank = r;
	damage = r*0.5;
	money = r*5;
	exp=r*5;
}

//BOSS类的实现
Monster_Boss::Monster_Boss()
{
	rank = 10;
	HP_limit = 300;
	HP = HP_limit;
	damage = 50;
	money = 1001;
	exp=1000;
}

void Monster_Boss::attack(Ultraman& utm)
{
	utm.attacked(Monster_Boss::damage);
}

void Monster_Boss::XP(Ultraman& utm)
{
	//cout<<"XP*****"<<endl;
	attack(utm);
	attack(utm);
	attack(utm);
}

void Monster_Boss::attacked(int damage_utm)
{
	HP -= damage_utm;
	count++;
}

void Monster_Boss::fightback(Ultraman& utm)
{
	if(count>=5)
		XP(utm);
	else attack(utm);
}

void Monster_Boss::display()
{
	cout<<"Boss怪兽状态(rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<")"<<endl;
}

void Monster_Boss::lose()
{
	cout<<"I'll be back!"<<endl;
}

ostream& operator << (ostream& out, Ultraman& utm)
{
	out<<"奥特曼状态(rank="<<utm.rank<<" hp="<<utm.HP<<" damage="<<utm.damage<<" exp="<<utm.exp<<" money="<<utm.money<<")"<<endl;
}

//下面是测试主程序
int main()
{
	int t;
	bool flag;
	int winflag1=0,winflag2=0,winflag3=0,winflag4=0;
	cin>>t;
	
	while(t--)
	{
		int rank;
		int mgrad[4];
		
		cin>>rank;
		Ultraman Outman(rank);
		Outman.display();
		
		for(int i=0;i<4;i++)
			cin>>mgrad[i];
		NMonster nmst(mgrad[0]);
		AMonster amst(mgrad[1]);
		DMonster dmst(mgrad[2]);
		SMonster smst(mgrad[3]);
		nmst.display();
		amst.display();
		dmst.display();
		smst.display();
 		
 		flag = true;
 		winflag1=0,winflag2=0,winflag3=0,winflag4=0;
 		while(flag)
 		{
 			Outman.attack(nmst);
 			Outman.attack(amst);
 			Outman.attack(dmst);
 			Outman.attack(smst);
 			if
		}
	}

	return 0;
}

