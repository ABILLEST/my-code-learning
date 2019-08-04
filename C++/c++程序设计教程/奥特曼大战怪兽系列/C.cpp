#include <iostream>
using namespace std;

class Ultraman;
class Monster;
//这里开始写类的界面代码
//奥特曼类的界面
class Ultraman
{
private:
	int rank,exp,HP,HP_limit,damage,money;
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
};

//怪兽类的界面
class Monster
{
protected:
	int rank,exp,HP,HP_limit,damage,money;
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
	void display();
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
	if(m.getHp()<=0)
	{
		money += m.getMoney();
		exp += m.getExp();
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

void Monster::display()
{
	cout<<"rank="<<rank<<" hp="<<HP<<" damage="<<damage<<" exp="<<exp<<" money="<<money<<endl;
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
	count = 0;
}

void Monster_Boss::attack(Ultraman& utm)
{
	utm.attacked(Monster_Boss::damage);
}

void Monster_Boss::XP(Ultraman& utm)
{
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

//下面是测试主程序
int main()
{
	int t,n;
	cin>>t;
	
	while(t--)  //每个实例就是奥特曼与怪兽的1对1战斗
	{
		bool dead = false;
		bool ran = false;
		bool flag = true;
		int rank,damage;
		//输入奥特曼的等级值，利用等级值，声明一个奥特曼对象并显示奥特曼对象初始状态。
		cin>>rank;
		Ultraman Outman(rank);
		Outman.display();
		
		//输入怪兽个数和等级
		cin>>n>>rank;
		while(!dead&&!ran&&n>0)	//只要奥特曼没死也没逃跑，就继续与n个怪兽的战斗
		{
			Monster monster(rank);
			//设置战斗标志flag为true，启动战斗循环，具体如下：
			flag = true;
			while(flag) //当战斗未结束就继续
			{
				//奥特曼攻击1次，或者是怪兽被攻击1次
				Outman.attack(monster);
		    	if (monster.getHp()>0)  //用怪兽生命来判断，用get方法啦
		    	{
					//怪兽反击1次，或者是奥特曼被攻击1次
					monster.fightback(Outman);
	            	if(Outman.getHp()>10)        //用奥特曼生命来判断，用get方法啦
	            	{
	            		Outman.restore();		//奥特曼回血，在方法中判断是否需要加血
	            	}
	                else if(Outman.getHp()<=0){
	                	cout<<"lose"<<endl;
						//输出奥特曼状态，调用display方法
						Outman.display();
	                	dead = true;
	                }
		    		else
					{
						//奥特曼逃跑，并输出"lose"并回车
						Outman.escape();
						cout<<"lose"<<endl;
						//输出奥特曼状态，调用display方法
						Outman.display();
						//设置flag为false，停止战斗
						flag = false;
						ran = true;
					}
		       }
		       else//怪兽死了
		       {     
					//奥特曼胜利，并输出"win"并回车
					Outman.win(monster);
					cout<<"win"<<endl;
					Outman.upgrade();
		            //设置flag为false，停止战斗
					//输出奥特曼状态，调用display方法
					//Outman.display();
					flag = false;
		       }
			}
			n--;
		}
		
		
		if(!dead&&!ran)//如果打完n个小怪兽奥特曼还没死也没逃跑，就挑战Boss
		{
			Outman.display();
			Monster_Boss boss;
			
			//设置战斗标志flag为true，启动战斗循环，具体如下：
			flag = true;
			while(!dead&&!ran&&flag)
			{
				Outman.attack(boss);
				if(boss.getHp()>0)
				{
					boss.fightback(Outman);
					if(Outman.getHp()>10)           //用奥特曼生命来判断，用get方法啦
					{
						Outman.restore();		//奥特曼回血，在方法中判断是否需要加血
					}
	                else if(Outman.getHp()<=0){
	                	cout<<"lose"<<endl;
						//输出奥特曼状态，调用display方法
						Outman.display();
	                	dead = true;
	                }
		    		else
					{
						//奥特曼逃跑，并输出"lose"并回车
						Outman.escape();
						cout<<"lose"<<endl;
						//输出奥特曼状态，调用display方法
						Outman.display();
						//设置flag为false，停止战斗
						flag = false;
						ran = true;
					}
				}
				else//怪兽死了
		       {     
					//奥特曼胜利，并输出"win"并回车
					Outman.win(boss);
					cout<<"win Boss"<<endl;
					Outman.upgrade();
		            //输出奥特曼状态，调用display方法
					Outman.display();
		            //设置flag为false，停止战斗
					flag = false;
		       }
			}
		}
	}
	
	return 0;
}
