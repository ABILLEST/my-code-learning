#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
	string name,position;
	int grade, year;
public:
	Employee(string n,string p,int g,int y):name(n),position(p),grade(g),year(y){}
	virtual int salary(){return (1000 + 500*grade + 50*year);}
	friend void show(Employee *p);
};

class Teamleader : public Employee
{
public:
	Teamleader(string n,string p,int g,int y):Employee(n,p,g,y){}
	virtual int salary(){return (3000 + 800*grade + 100*year);}	
	friend void show(Employee *p);
};

class Manager : public Employee
{
public:
	Manager(string n,string p,int g,int y):Employee(n,p,g,y){}
	virtual int salary(){return (5000 + 1000*(grade+year));}
	friend void show(Employee *p);
};

void show(Employee *p)
{
	cout<<p->name<<":"<<p->position<<",Salary:"<<p->salary()<<endl;
}

int main()
{
	int t;
	string name,pos;
	int grade, year;
	cin>>t;
	
	Employee *p;
	for(int i=0;i<t;i++)
	{
		cin>>name>>pos>>grade>>year;
		if(pos=="Employee")
		{
			if(grade>=0&&year>=0)
			{
				p = new Employee(name,pos,grade,year);
				show(p);
			}
			else cout<<"error grade or year."<<endl;
		}
		else if(pos=="Teamleader")
		{
			if(grade>=0&&year>=0)
			{
				p = new Teamleader(name,pos,grade,year);
				show(p);
			}
			else cout<<"error grade or year."<<endl;
		}
		else if(pos=="Manager")
		{
			if(grade>=0&&year>=0)
			{
				p = new Manager(name,pos,grade,year);
				show(p);
			}
			else cout<<"error grade or year."<<endl;
		}
		else cout<<"error position."<<endl;
	}
}
