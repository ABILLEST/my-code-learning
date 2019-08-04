#include <iostream>
#include <string.h>
using namespace std;

 class CDate
{
private:
    int year, month, day;
public:
	CDate(){};
    CDate(int y, int m, int d) { year = y; month = m; day = d; }
    void set(int y,int m,int d){year = y; month = m; day = d;}
    bool isLeapYear() { return (year%4 == 0 && year%100 != 0) || year%400 == 0; }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDayofYear();         //计算日期从当年1月1日算起的天数
    int getDayof47();         //计算日期从当年4月7日算起的天数
    int getRstDayof2015();         //计算日期从2015年4月7日算起剩下的天数
};

class SFW{
		string name;
		char type;
		char media;
		CDate date;
	public:
		SFW(string,char,char,int,int,int);
		SFW(SFW &);
		void print();
};

int CDate::getDayofYear()
{
int i, sum=day; 
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

    if (isLeapYear())
        for(i=1;i<month;i++)   sum +=b[i];
    else
        for(i=1;i<month;i++)   sum +=a[i];

     return sum;
}

int CDate::getDayof47()
{
int i, sum=day-7; 
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

    if (isLeapYear())
        for(i=4;i<month;i++)   sum +=b[i];
    else
        for(i=4;i<month;i++)   sum +=a[i];

     return sum;
}

int CDate::getRstDayof2015()
{
int i, sum=31-7; 
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int b[13]={0,31,29,31,30,31,30,31,31,30,31,30,31};

    if (isLeapYear())
        for(i=4;i<12;i++)   sum +=b[i];
    else
        for(i=4;i<12;i++)   sum +=a[i];

     return sum;
}

SFW::SFW(string _name, char _type, char _media, int y,int m,int d)
{
	name = _name;
	type = _type;
	media = _media;
	date.set(y,m,d);
}

SFW::SFW(SFW &s)
{
	name = s.name;
	type = 'B';
	media = 'H';
	date = s.date;
}

void SFW::print()
{
	cout<<"name:"<<name<<endl;
	
	cout<<"type:";
	if(type=='O')
		cout<<"original"<<endl;
	else if(type=='B')
		cout<<"backup"<<endl;
	else if(type=='T')
		cout<<"trial"<<endl;
	else cout<<"type error"<<endl;
		
	cout<<"media:";
	if(media=='D')
		cout<<"optical disk"<<endl;
	else if(media=='H')
		cout<<"hard disk"<<endl;
	else if(media=='U')
		cout<<"USB disk"<<endl;
	else cout<<"media error"<<endl;
		
	cout<<"this software ";
	if(date.getYear()==0&&date.getMonth()==0&&date.getDay()==0)
		cout<<"has unlimited use"<<endl;
	else if(date.getYear()<2015)
		cout<<"has expired"<<endl;
	else if(date.getYear()==2015)
			if(date.getDayof47()>0)
				cout<<"is going to be expired in "<<date.getDayof47()<<" days"<<endl;
			else
				cout<<"has expired"<<endl;
	else
		{
			int x=date.getYear()-2015;
			if(x/4==0)
				cout<<"is going to be expired in "<<date.getRstDayof2015()+(x-1)*365+date.getDayofYear()<<" days"<<endl;
			else
				cout<<"is going to be expired in "
				<<date.getRstDayof2015()+(365*2+366)+(x/4-1)*(365*3+366)+(x%4)*365+date.getDayofYear()<<" days"<<endl;
		}

	cout<<endl;
}

//Software copy
int main()
{
	int t, n;
	int y,m,d;
	string SfwName;
	char SfwType, SfwMedia;
	cin>>t;
	
	for(int i=0; i<t; i++)
	{
		cin>>SfwName>>SfwType>>SfwMedia>>y>>m>>d;
		SFW sfw1(SfwName,SfwType,SfwMedia,y,m,d);
		SFW sfw2(sfw1);
		sfw1.print();
		sfw2.print();
	}
	return 0;
}
