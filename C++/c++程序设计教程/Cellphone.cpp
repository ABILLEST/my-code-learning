#include <iostream>
#include <iomanip>
using namespace std;

class Date
{
	int year;
	int mon;
	int day;
public:
	Date(){};
	Date(int,int,int);
	void print();
};

class Cellphone
{
	char type;//A机构、B企业、C个人、D备份 
	string num;
	int state;//1在用、2未用、3停用 
	Date* date;
public:
	Cellphone(char,string,int,Date*);
	Cellphone(Cellphone&);
	void print();
	void stop(Date*);
};

Date::Date(int y,int m,int d)
{
	year=y;
	mon=m;
	day=d;
}

void Cellphone::print()
{
	if(type=='A')
		cout<<"类型=机构"<<"||";
	else if(type=='B')
		cout<<"类型=企业"<<"||";
	else if(type=='C') 
		cout<<"类型=个人"<<"||";
	else if(type=='D') 
		cout<<"类型=备份"<<"||";
	cout<<"号码="<<num<<"||";
	if(state==1)
		cout<<"State=在用"<<endl; 
	else if(state==2)
		cout<<"State=未用"<<endl; 
	else if(state==3)
		cout<<"State=停用"<<endl; 
}

void Cellphone::stop(Date* d)
{
	state=3;
	date = new Date;
	*date = *d;
	cout<<"Stop the phone "<<num<<endl;
} 

Cellphone::Cellphone(char _type,string _num,int _state,Date* d)
{
	type=_type;	num=_num; state=_state; date=d;
	cout<<"Construct a new phone "<<num<<endl;
}

Cellphone::Cellphone(Cellphone& c)
{
	type='D';
	num = c.num+"X";
	state=c.state;
	date = new Date;
	*date = *c.date;
	cout<<"Construct a copy of phone "<<c.num<<endl;
}

//date friend function
int main()
{
	int t;
	char type;
	string num;
	int state;
	int year,mon,day;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>type>>num>>state>>year>>mon>>day;
		Date d(year,mon,day);
		Date* date = &d;
		Cellphone c1(type,num,state,date);
		c1.print();
		Cellphone c2(c1);
		c2.print();
		c1.stop(date);
		c1.print();
		cout<<"----"<<endl;
		
	}
	return 0;
}

