#include <iostream>
#include <iomanip>
using namespace std;
//class reference
class Date;
class Time;

class Date
{
	int year;
	int mon;
	int day;
public:
	Date();
	friend void Display(Date &, Time &);
};

class Time
{
	int hour;
	int minute;
	int second;
public:
	Time();
	friend void Display(Date &, Time &);
};

Date::Date()
{
	cin>>year>>mon>>day;
}

Time::Time()
{
	cin>>hour>>minute>>second;
}

void Display(Date &d, Time &t)
{
	cout<<setw(4)<<d.year<<"-";
	cout<<setfill('0')<<setw(2)<<d.mon<<"-"
		<<setfill('0')<<setw(2)<<d.day<<" "
		<<setfill('0')<<setw(2)<<t.hour<<":"
		<<setfill('0')<<setw(2)<<t.minute<<":"
		<<setfill('0')<<setw(2)<<t.second<<endl;
}

//date friend function
int main()
{
	int t;
	cin>>t;
	for(int i=0; i<t; i++)
	{
		Date date;
		Time time;
		Display(date,time);
	}
	return 0;
}

