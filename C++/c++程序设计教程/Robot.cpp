#include <iostream>
#include <string>
using namespace std;

class Robot
{
protected:
	string name;
	int HP,damage,defense,grade;
	char type;
public:
	Robot(string n,char _type,int _grade);
	friend bool transform(Robot* r,char targetType);
	void show();
};

class NomalRobot : public Robot
{
public:
	NomalRobot(string n,char _type,int _grade);
};

class AttackRobot : public Robot
{
public:
	AttackRobot(string n,char _type,int _grade);
};

class DefenseRobot : public Robot
{
public:
	DefenseRobot(string n,char _type,int _grade);
};	

class HealthRobot : public Robot
{
public:
	HealthRobot(string n,char _type,int _grade);	
};

Robot::Robot(string n,char _type,int _grade)
{
	name = n;
	type = _type;
	grade = _grade;
}

NomalRobot::NomalRobot(string n,char _type,int _grade):Robot(n,_type,_grade)
{
	HP = grade*5;
	damage = grade*5;
	defense = grade*5;
}

AttackRobot::AttackRobot(string n,char _type,int _grade):Robot(n,_type,_grade)
{
	HP = grade*5;
	damage = grade*10;
	defense = grade*5;
}

DefenseRobot::DefenseRobot(string n,char _type,int _grade):Robot(n,_type,_grade)
{
	HP = grade*5;
	damage = grade*5;
	defense = grade*10;
}

HealthRobot::HealthRobot(string n,char _type,int _grade):Robot(n,_type,_grade)
{
	HP = grade*50;
	damage = grade*5;
	defense = grade*5;
}

void Robot::show()
{
	cout<<name<<"--"<<type<<"--"<<grade<<"--"<<HP<<"--"<<damage<<"--"<<defense<<endl;
}

bool transform(Robot* r,char targetType)
{
	if(r->type==targetType)
		return false;

	r->type = targetType;
	if(targetType=='N')
	{
		r->HP = r->grade*5;
		r->damage = r->grade*5;
		r->defense = r->grade*5;
	}
	else if(targetType=='A')
	{
		r->HP = r->grade*5;
		r->damage = r->grade*10;
		r->defense = r->grade*5;
	}
	else if(targetType=='D')
	{
		r->HP = r->grade*5;
		r->damage = r->grade*5;
		r->defense = r->grade*10;
	}
	else if(targetType=='H')
	{
		r->HP = r->grade*50;
		r->damage = r->grade*5;
		r->defense = r->grade*5;
	}
	return true;
}


//
int main()
{
	int t,grade;
	int counter=0;
	bool flag;
	string name;
	char type,tartype;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>name>>type>>grade>>tartype;
		if(type!='N'&&type!='A'&&type!='D'&&type!='H'){
			cerr<<"Type Error!"<<endl;
		}
		else{
			Robot r(name,type,grade);
			if(transform(&r,tartype))
					counter++;
				r.show();
		}
		
	}
	
	cout<<"The number of robot transform is "<<counter<<endl;
	return 0;
}
