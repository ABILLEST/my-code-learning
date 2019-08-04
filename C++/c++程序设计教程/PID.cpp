#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>
#include <sstream>
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
	int getYear();
};

class PID
{
private:
	int type;
	string num;
	Date date;
public:
	PID(int _type,string _num,int y,int m,int d);
	PID(PID&,int y,int m,int d);
	void print();
};

//Date methods definitions
Date::Date(int y,int m,int d)
{
	year = y;
	mon = m;
	day = d;
}

void Date::print()
{
	cout<<setfill('0')<<setw(4)<<year<<"."
		<<setfill('0')<<setw(2)<<mon<<"."
		<<setfill('0')<<setw(2)<<day<<endl;
}

int Date::getYear()
{
	return year;
}

//PID methods definitions
PID::PID(int _type,string _num,int y,int m, int d):date(y,m,d)
{
	type=_type;
	num = _num;
}

PID::PID(PID& pid,int y,int m,int d):date(y,m,d)
{
	//upgrade
	if(pid.num.length()==15)
	{
		type = 2;
		stringstream sstr;
		string s;
		int sum=0;
		
		sstr << (pid.date.getYear()/100);
		sstr >> s;
		sstr.clear();
		//itoa(pid.date.getYear()/100,s,10);
		num=pid.num;
		num.insert(6,s);
		
		for(int i=0;i<num.length();i++)
			sum += (num[i]-'0');	//char to number
		if((sum/1%10)==0)
			num.append("X");
		else
		{
			sstr << (sum/1%10);
			//cout<<sstr<<endl;
			sstr >> s;
			//cout<<s<<endl;
			//itoa(sum/1%10,t,10);
			num.append(s);
			sstr.clear();
		}
	}
	else if(pid.num.length()==18)
	{
		type = pid.type;
		num = pid.num;
	}
	else cout<<"ID LENGTH ERROR!"<<endl;
}

void PID::print()
{
	cout<<"type="<<type<<" birth=";
	date.print();
	cout<<"ID="<<num<<endl;
}

int main()
{
	int t;
	int type,y,m,d;
	string num;

	cin>>t;
	
	for(int i=0;i<t;i++)
	{
		cin>>type>>num>>y>>m>>d;
		PID pid1(type,num,y,m,d);
		PID pid2(pid1,y,m,d);
		pid2.print();
	}
}
