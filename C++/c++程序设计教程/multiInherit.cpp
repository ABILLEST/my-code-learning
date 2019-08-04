#include <iostream>
#include <string> 
using namespace std;

//class reference
class CPeople
{
protected:
	string name;
	char sex;
	int age;
public:
	CPeople(string _name,char _sex,int _age);
	void print();
};

class CStudent : virtual public CPeople
{
protected:
	string id;
	double mark;
public:
	CStudent(string _name,char _sex,int _age,string _id,double _mark);
	virtual void print();
};

class CTeacher : virtual public CPeople
{
protected:
	string position;
	string department;
public:
	CTeacher(string _name,char _sex,int _age,string pos,string depar);
	virtual void print();
}; 

class CGradOnWork : public CStudent,public CTeacher
{
protected:
	string direction;
	string tutor;
public:
	CGradOnWork(string _name,char _sex,int _age,string _id,double _mark
				,string pos,string depar,string dire,string _tutor);
	virtual void print();
}; 

//class methods definition
CPeople::CPeople(string _name,char _sex,int _age)
{
	name = _name;
	sex = _sex;
	age = _age;
}

void CPeople::print()
{
	cout<<"People:"<<endl
		<<"Name: "<<name<<endl
		<<"Sex: "<<sex<<endl
		<<"Age: "<<age<<endl<<endl;
}

CStudent::CStudent(string _name,char _sex,int _age,string _id,double _mark):CPeople(_name,_sex,_age)
{
	id = _id;
	mark = _mark;
}

void CStudent::print()
{
	cout<<"Student:"<<endl
		<<"Name: "<<name<<endl
		<<"Sex: "<<sex<<endl
		<<"Age: "<<age<<endl
		<<"No.: "<<id<<endl
		<<"Score: "<<mark<<endl<<endl;
}

CTeacher::CTeacher(string _name,char _sex,int _age,string pos,string depar):CPeople(_name,_sex,_age)
{
	position = pos;
	department = depar;
}

void CTeacher::print()
{
	cout<<"Teacher:"<<endl
		<<"Name: "<<name<<endl
		<<"Sex: "<<sex<<endl
		<<"Age: "<<age<<endl
		<<"Position: "<<position<<endl
		<<"Department: "<<department<<endl<<endl;
}

CGradOnWork::CGradOnWork(string _name,char _sex,int _age,string _id,double _mark
				,string pos,string depar,string dire,string _tutor)
			:CPeople(_name,_sex,_age),CStudent(_name,_sex,_age,_id,_mark),CTeacher(_name,_sex,_age,pos,depar)
{
	direction = dire;
	tutor = _tutor;
}

void CGradOnWork::print()
{
	cout<<"GradOnWork:"<<endl
		<<"Name: "<<CGradOnWork::name<<endl
		<<"Sex: "<<sex<<endl
		<<"Age: "<<age<<endl
		<<"No.: "<<id<<endl
		<<"Score: "<<mark<<endl
		<<"Position: "<<position<<endl
		<<"Department: "<<department<<endl
		<<"Direction: "<<direction<<endl
		<<"Tutor: "<<tutor<<endl;
}

//multiple inherit
int main()
{
	string name,id,pos,depar,dire,tutor;
	int age;
	double mark;
	char sex;
	
	cin>>name>>sex>>age;
	CPeople p(name,sex,age);
	p.print();
	
	cin>>id>>mark;
	CStudent s(name,sex,age,id,mark);
	s.print();
	
	cin>>pos>>depar;
	CTeacher t(name,sex,age,pos,depar);
	t.print();
	
	cin>>dire>>tutor;
	CGradOnWork g(name,sex,age,id,mark,pos,depar,dire,tutor);
	g.print();
}
